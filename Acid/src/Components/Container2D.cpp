#include "Container2D.h"

// Constructor
Container2D::Container2D(Transform* transform) : transform(transform)
{
	name = "Container2D";
	enabled = true;
	bounce = 1;
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

// Constructor w/Rigidbody2D
Container2D::Container2D(Transform* transform, Rigidbody2D* rigidbody2D) : transform(transform), rigidbody2D(rigidbody2D)
{
	name = "Container2D";
	enabled = true;
	bounce = 1;
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

// Update
void Container2D::Update()
{
	if (rigidbody2D != nullptr)
	{
		// Right Border
		if (transform->position.x - ((rigidbody2D->collider.width * abs(transform->scale.x)) / 2) < x)
		{
			transform->position.x = x + ((rigidbody2D->collider.width * abs(transform->scale.x)) / 2);
			rigidbody2D->velocity.x *= -bounce;
		}

		// Left Border
		if (transform->position.x + ((rigidbody2D->collider.width * transform->scale.x) / 2) > width)
		{
			transform->position.x = width - ((rigidbody2D->collider.width * transform->scale.x) / 2);
			rigidbody2D->velocity.x *= -bounce;
		}

		// Top Border
		if (transform->position.y + ((rigidbody2D->collider.height * transform->scale.y) / 2) > height)
		{
			transform->position.y = height - ((rigidbody2D->collider.height * transform->scale.y) / 2);
			rigidbody2D->velocity.y *= -bounce;
		}

		// Bottom Border
		if (transform->position.y - ((rigidbody2D->collider.height * transform->scale.y) / 2) < y)
		{
			transform->position.y = y + ((rigidbody2D->collider.height * transform->scale.y) / 2);
			rigidbody2D->velocity.y *= -bounce;
		}

	}
}

// Enable/Disable Border
void Container2D::SetEnabled(bool _enabled)
{
	enabled = enabled;
}

// Set Border Bounciness
void Container2D::SetBounce(float _bounce)
{
	bounce = _bounce;
}

// Set Border Dimensions
void Container2D::SetDimensions(float _x, float _y, float _width, float _height)
{
	x = _x;
	y = _y;
	width = _width;
	height = _height;
}