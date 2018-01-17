#ifndef RIGIDBODY2D_COMPONENT
#define RIGIDBODY2D_COMPONENT

#include "Component.h"
#include "Transform.h"

struct Velocity
{
	float x;
	float y;
};

struct Gravity
{
	float x;
	float y;
};

struct Collider
{
	bool enabled;
	bool physical;
	float x;
	float y;
	float width;
	float height;
};

class Rigidbody2D : public Component
{
public:
	Rigidbody2D(Transform* transform);
	virtual ~Rigidbody2D() { };

	void Update() override;
	void Draw() {};

	void SetGravity(float x, float y);
	void SetVelocity(float x, float y);
	void ChangeVelocity(float x, float y);
	void SetMaxVelocityEnabled(bool enabled);
	void SetMaxVelocity(float x, float y);
	void SetDrag(float _drag);
	void SetRotationOffset(float rotation);
	void SetColliderEnabled(bool enabled);
	void SetColliderPhysical(bool physical);
	void SetColliderDimensions(float x, float y, float width, float height);
	void SetBounciness(float bounce);
	void SetFriction(float fric);
	void SetMass(float ms);
	void SetDensity(float dens);
	void MatchRotationToVelocity();
	void RotateWithVelocityEnabled(bool enabled);
	float GetMass();

	Velocity velocity;
	Gravity gravity;
	Collider collider;

private:
	void LimitVelocity();

	Transform* transform{ nullptr };
	bool maxVelocityEnabled;
	bool gravityEnabled;
	bool rotateWithVelocity;
	float maxVelocityX;
	float maxVelocityY;
	float drag;
	float rotationOffset;
	float friction;
	float mass;
	float density;
	float bounciness;

};

#endif