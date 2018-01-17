#include "Controller.h"

// Constructor
Controller::Controller(Transform* transform, Rigidbody2D* rigidbody2D) : transform(transform), rigidbody2D(rigidbody2D)
{
	name = "Controller";
	speed = 4;
	force = 0.3;
	maxSpeed = 4;
	movementEnabled = true;
	forceEnabled = false;
	diagonalMovementEnabled = true;
	flipByMovementDirection = true;
}

// Update Inputs
void Controller::Update()
{
	if (movementEnabled)
	{
		CheckMovement();
	}
}

// Check Movement
void Controller::CheckMovement()
{
	if ((Keyboard::Key(primaryUpKey) || Keyboard::Key(secondaryUpKey))
		&& (Keyboard::Key(primaryRightKey) || Keyboard::Key(secondaryRightKey)))	// Up-Right
	{
		transform->Move(speed * 0.6, speed * 0.6);
		if (flipByMovementDirection)
		{
			transform->FlipRight();
		}
		if (forceEnabled)
		{
			rigidbody2D->ChangeVelocity(force, force);
		}
	}
	else if ((Keyboard::Key(primaryUpKey) || Keyboard::Key(secondaryUpKey))
		&& (Keyboard::Key(primaryLeftKey) || Keyboard::Key(secondaryLeftKey)))		// Up-Left
	{
		transform->Move(-speed * 0.6, speed * 0.6);
		if (flipByMovementDirection)
		{
			transform->FlipLeft();
		}
		if (forceEnabled)
		{
			rigidbody2D->ChangeVelocity(-force, force);
		}
	}
	else if ((Keyboard::Key(primaryDownKey) || Keyboard::Key(secondaryDownKey))
		&& (Keyboard::Key(primaryRightKey) || Keyboard::Key(secondaryRightKey)))	// Down-Right
	{
		transform->Move(speed * 0.6, -speed * 0.6);
		if (flipByMovementDirection)
		{
			transform->FlipRight();
		}
		if (forceEnabled)
		{
			rigidbody2D->ChangeVelocity(force, -force);
		}
	}
	else if ((Keyboard::Key(primaryDownKey) || Keyboard::Key(secondaryDownKey))
		&& (Keyboard::Key(primaryLeftKey) || Keyboard::Key(secondaryLeftKey)))		// Down-Left
	{
		transform->Move(-speed * 0.6, -speed * 0.6);
		if (flipByMovementDirection)
		{
			transform->FlipLeft();
		}
		if (forceEnabled)
		{
			rigidbody2D->ChangeVelocity(-force, -force);
		}
	}
	else if (Keyboard::Key(primaryUpKey) || Keyboard::Key(secondaryUpKey))			// Up
	{
		transform->Move(0, speed);
		if (forceEnabled)
		{
			rigidbody2D->ChangeVelocity(0, force);
		}
	}
	else if (Keyboard::Key(primaryDownKey) || Keyboard::Key(secondaryDownKey))		// Down
	{
		transform->Move(0, -speed);
		if (forceEnabled)
		{
			rigidbody2D->ChangeVelocity(0, -force);
		}
	}
	else if (Keyboard::Key(primaryLeftKey) || Keyboard::Key(secondaryLeftKey))		// Left
	{
		transform->Move(-speed, 0);
		if (flipByMovementDirection)
		{
			transform->FlipLeft();
		}
		if (forceEnabled)
		{
			rigidbody2D->ChangeVelocity(-force, 0);
		}
	}
	else if (Keyboard::Key(primaryRightKey) || Keyboard::Key(secondaryRightKey))	// Right
	{
		transform->Move(speed, 0);
		if (flipByMovementDirection)
		{
			transform->FlipRight();
		}
		if (forceEnabled)
		{
			rigidbody2D->ChangeVelocity(force, 0);
		}
	}
}

// Movement Enable/Disbale
void Controller::SetMovementEnabled(bool enabled)
{
	movementEnabled = enabled;
}

// Enable/Disable Force
void Controller::SetForceEnabled(bool enabled)
{
	forceEnabled = enabled;
}

// Set Speed
void Controller::SetSpeed(float _speed)
{
	speed = _speed;
}

// Set Max Speed
void Controller::SetMaxSpeed(float speed)
{
	maxSpeed = speed;
}

// Set Force
void Controller::SetForce(float _force)
{
	force = _force;
}

// Enable/Disable Flip By Movement Direction
void Controller::FlipByMovementDirectionEnabled(bool enabled)
{
	flipByMovementDirection = enabled;
}