#ifndef BOXCOLLIDER_COMPONENT
#define BOXCOLLIDER_COMPONENT

#include "Component.h"
#include "Transform.h"
#include "Rigidbody2D.h"
#include "../GraphicObject.h"

struct BoxSize
{
	float x;
	float y;
};

struct Offset
{
	float x;
	float y;
};

class BoxCollider : public Component
{
public:
	BoxCollider(Transform* transform, Rigidbody2D* rigidbody, vector<GraphicObject*>* graphicObjectLayer);
	virtual ~BoxCollider() { };

	void Update() override;
	void Draw() {};

	void SetSize(float width, float height);
	void SetOffset(float offsetX, float offsetY);
	void Enable();
	void Disable();

	float Distance(BoxCollider* collider);
	float Direction(BoxCollider* collider);
	bool isTouching(BoxCollider* collider);
	bool isRightOf(BoxCollider* collider);
	bool isAbove(BoxCollider* collider);

	BoxSize size;
	Offset offset;
	Transform* transform{ nullptr };

private:
	bool enabled;
	Rigidbody2D* rigidbody;
	vector<GraphicObject*>* layer;

};

#endif