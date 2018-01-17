#include "Rigidbody2D.h"

// Constructor
Rigidbody2D::Rigidbody2D(Transform* transform) : transform(transform)
{
	name = "Rigidbody2D";
	velocity = { 0, 0 };
	gravity = { 0, 0 };
	collider = { 1, 1, transform->origin.x, transform->origin.y, transform->size.width, transform->size.height};
	drag = 0;
	maxVelocityEnabled = false;
	gravityEnabled = false;
	maxVelocityX = 6;
	maxVelocityY = 6;
	rotateWithVelocity = false;
	rotationOffset = 0;
	friction = 0;
	mass = 1;
	density = 0;
	bounciness = 0.8;
}

// Update
void Rigidbody2D::Update()
{
	if (gravityEnabled)
	{
		velocity.x -= gravity.x;
		velocity.y -= gravity.y;
	}
	if (maxVelocityEnabled)
	{
		LimitVelocity();
	}
	if (drag > 0)
	{
		velocity.x *= drag;
		velocity.y *= drag;
	}
	if (rotateWithVelocity)
	{
		MatchRotationToVelocity();
	}
	transform->Move(velocity.x, velocity.y);
}

// Rotate With Velocity Enabled
void Rigidbody2D::RotateWithVelocityEnabled(bool enabled)
{
	rotateWithVelocity = enabled;
}

// Match Transform Rotation to Velocity Angle
void Rigidbody2D::MatchRotationToVelocity()
{
	transform->SetRotation(-atan2(velocity.x, velocity.y) * 180 / 3.141 + rotationOffset);
}

// Set Rotation Offset For Transform
void Rigidbody2D::SetRotationOffset(float rotation)
{
	rotationOffset = rotation;
}

// Limit Velocity To Max 
void Rigidbody2D::LimitVelocity()
{
	if (velocity.x > maxVelocityX)
	{
		velocity.x = maxVelocityX;
	}
	if (velocity.x < -maxVelocityX)
	{
		velocity.x = -maxVelocityX;
	}
	if (velocity.y > maxVelocityY)
	{
		velocity.y = maxVelocityY;
	}
	if (velocity.y < -maxVelocityY)
	{
		velocity.y = -maxVelocityY;
	}
}

// Set Gravity 2D
void Rigidbody2D::SetGravity(float x, float y)
{
	gravity.x = x;
	gravity.y = y;
}

// Set Velocity 2D
void Rigidbody2D::SetVelocity(float x, float y)
{
	velocity.x = x;
	velocity.y = y;
	LimitVelocity();
}

// Change Velocity 2D
void Rigidbody2D::ChangeVelocity(float x, float y)
{
	velocity.x += x;
	velocity.y += y;
	LimitVelocity();
}

// Set Drag
void Rigidbody2D::SetDrag(float _drag)
{
	drag = _drag;
}

// Set Bounciness
void Rigidbody2D::SetBounciness(float bounce)
{
	bounciness = bounce;
}

// Set Friction
void Rigidbody2D::SetFriction(float fric)
{
	friction = fric;
}

// Set Mass
void Rigidbody2D::SetMass(float ms)
{
	mass = ms;
}

// Set Density
void Rigidbody2D::SetDensity(float dens)
{
	density = dens;
}

// Enable/Disable Max Velocity Limit
void Rigidbody2D::SetMaxVelocityEnabled(bool enabled)
{
	maxVelocityEnabled = enabled;
}

// Set Max Velocity
void Rigidbody2D::SetMaxVelocity(float x, float y)
{
	maxVelocityX = x;
	maxVelocityY = y;
}

// Enable/Disable Collider
void Rigidbody2D::SetColliderEnabled(bool enabled)
{
	collider.enabled = enabled;
}

// Enable/Disable Physical Collider
void Rigidbody2D::SetColliderPhysical(bool physical)
{
	collider.physical = physical;
}

// Set Collider Dimensions
void Rigidbody2D::SetColliderDimensions(float x, float y, float width, float height)
{
	collider.x = x;
	collider.y = y;
	collider.width = width;
	collider.height = height;
}

// Get Mass
float Rigidbody2D::GetMass()
{
	return mass;
}