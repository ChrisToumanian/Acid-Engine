#ifndef CIRCLECOLLIDER_COMPONENT
#define CIRCLECOLLIDER_COMPONENT

#include "Component.h"
#include "Transform.h"
#include "Rigidbody2D.h"
#include "../GraphicObject.h"

struct CenterOffset
{
	float x;
	float y;
};

class CircleCollider : public Component
{
public:
	CircleCollider(Transform* transform, Rigidbody2D* rigidbody, vector<GraphicObject*>* graphicObjectLayer);
	virtual ~CircleCollider() { };

	void Update() override;
	void Draw() {};

	void SetRadius(float _radius);
	void SetOffset(float offsetX, float offsetY);
	void Enable();
	void Disable();
	void CheckCollisions();
	bool IsColliding(CircleCollider* collider);
	bool IsMovingTowards(CircleCollider* collider);
	bool WillCollide(CircleCollider* collider);
	void ResolveCollision(CircleCollider* collider);
	float Distance(CircleCollider* collider);
	void Separate(CircleCollider* collider);

	CenterOffset offset;
	Transform* transform{ nullptr };

private:
	bool enabled;
	bool trigger;
	float radius;
	Rigidbody2D* rigidbody;
	vector<GraphicObject*>* layer;

};

#endif