#ifndef CONTROLLER_COMPONENT
#define CONTROLLER_COMPONENT

#include "Component.h"
#include "Transform.h"
#include "Rigidbody2D.h"
#include "../IO/Mouse.h"
#include "../IO/Keyboard.h"

class Controller : public Component
{
public:
	Controller(Transform* transform, Rigidbody2D* rigidbody2D);
	virtual ~Controller() { };

	void Update() override;
	void Draw() { };
	void SetMovementEnabled(bool _enabled);
	void SetForceEnabled(bool _enabled);
	void SetSpeed(float _speed);
	void SetMaxSpeed(float _maxSpeed);
	void SetForce(float _force);
	void FlipByMovementDirectionEnabled(bool enabled);

private:
	void CheckMovement();

	Transform* transform{ nullptr };
	Rigidbody2D* rigidbody2D{ nullptr };
	bool movementEnabled;
	bool forceEnabled;
	bool diagonalMovementEnabled;
	bool flipByMovementDirection;
	float speed;
	float maxSpeed;
	float force;

	int primaryUpKey = GLFW_KEY_W;
	int secondaryUpKey = GLFW_KEY_UP;
	int primaryDownKey = GLFW_KEY_S;
	int secondaryDownKey = GLFW_KEY_DOWN;
	int primaryLeftKey = GLFW_KEY_A;
	int secondaryLeftKey = GLFW_KEY_LEFT;
	int primaryRightKey = GLFW_KEY_D;
	int secondaryRightKey = GLFW_KEY_RIGHT;
};

#endif