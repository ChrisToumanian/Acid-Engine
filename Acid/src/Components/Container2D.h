#ifndef CONTAINER2D_COMPONENT
#define CONTAINER2D_COMPONENT

#include "Component.h"
#include "Transform.h"
#include "Rigidbody2D.h"

class Container2D : public Component
{
public:
	Container2D(Transform* transform);
	Container2D(Transform* transform, Rigidbody2D* rigidbody2D);
	virtual ~Container2D() { };
	void Update() override;
	void Draw() {};

	void SetEnabled(bool _enabled);
	void SetBounce(float _bounce);
	void SetDimensions(float x, float y, float width, float height);

private:
	bool enabled;
	float bounce;
	float x;
	float y;
	float width;
	float height;

	Transform* transform{ nullptr };
	Rigidbody2D* rigidbody2D{ nullptr };
};

#endif