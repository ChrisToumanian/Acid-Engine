#include "CircleCollider.h"

// Constructor
CircleCollider::CircleCollider(Transform* transform, Rigidbody2D* rigidbody, vector<GraphicObject*>* graphicObjectLayer) : transform(transform), rigidbody(rigidbody), layer(graphicObjectLayer)
{
	name = "CircleCollider";
	enabled = true;
	trigger = false;
	SetOffset(transform->origin.x, transform->origin.y);
	SetRadius(transform->size.width / 2);
}

// Update
void CircleCollider::Update()
{
	//DoCollisions();
}

// Check if moving towards
bool CircleCollider::IsMovingTowards(CircleCollider* collider)
{
	float dot = (rigidbody->velocity.x * collider->rigidbody->velocity.x) + (rigidbody->velocity.y * collider->rigidbody->velocity.y);
	if (dot < 0)
	{
		return true;
	}
	return false;
}

// Check Collisions
void CircleCollider::CheckCollisions()
{
	if (enabled && transform->GetMovedThisFrame())
	{
		vector<GraphicObject*> graphics = *layer;
		int size = layer->size();
		for (int i = 0; i < size; i++)
		{
			CircleCollider* collider = (CircleCollider*)graphics[i]->GetComponent("CircleCollider");
			if (collider != NULL && collider != this)
			{
				if (WillCollide(collider))
				{
					if (trigger)
					{
						//graphics[i]->OnTrigger();
					}
					else //if (IsMovingTowards(collider))
					{
						Separate(collider);
						ResolveCollision(collider);
						//Separate(collider);
						Transform* transform2 = (Transform*)graphics[i]->GetComponent("Transform");
						transform2->SetMovedThisFrame(false);
						//graphics[i]->OnCollision();
					}
				}
			}
		}
	}
}

// Separate
void CircleCollider::Separate(CircleCollider* collider)
{
	float d = Distance(collider);
	float h = radius + collider->radius - d;
	float cos = (collider->transform->position.x - transform->position.x) / d;
	float a = cos * h;
	float o = sqrt(h*h - a*a);
	transform->position.x += a / 2;
	transform->position.y += o / 2;
	collider->transform->position.x += -a / 2;
	collider->transform->position.y += -o / 2;
}

// Resolve Collision
void CircleCollider::ResolveCollision(CircleCollider* collider)
{
	float vx = (rigidbody->velocity.x * (rigidbody->GetMass() - collider->rigidbody->GetMass()) +
		(2 * collider->rigidbody->GetMass() * collider->rigidbody->velocity.x)) /
		(rigidbody->GetMass() + collider->rigidbody->GetMass());

	float vy = (rigidbody->velocity.y * (rigidbody->GetMass() - collider->rigidbody->GetMass()) +
		(2 * collider->rigidbody->GetMass() * collider->rigidbody->velocity.y)) /
		(rigidbody->GetMass() + collider->rigidbody->GetMass());

	float vx2 = (collider->rigidbody->velocity.x * (collider->rigidbody->GetMass() - rigidbody->GetMass()) +
		(2 * rigidbody->GetMass() * rigidbody->velocity.x)) /
		(collider->rigidbody->GetMass() + rigidbody->GetMass());

	float vy2 = (collider->rigidbody->velocity.y * (collider->rigidbody->GetMass() - rigidbody->GetMass()) +
		(2 * rigidbody->GetMass() * rigidbody->velocity.y)) /
		(collider->rigidbody->GetMass() + rigidbody->GetMass());

	rigidbody->velocity.x = vx;
	rigidbody->velocity.y = vy;
	collider->rigidbody->velocity.x = vx2;
	collider->rigidbody->velocity.y = vy2;

	//transform->Move(vx, vy);
	//collider->transform->Move(vx2, vy2);

}

// Set Radius
void CircleCollider::SetRadius(float _radius)
{
	radius = _radius;
}

// Set Offset
void CircleCollider::SetOffset(float offsetX, float offsetY)
{
	offset.x = offsetX;
	offset.y = offsetY;
}

// Enable
void CircleCollider::Enable()
{
	enabled = true;
}

// Disable
void CircleCollider::Disable()
{
	enabled = false;
}

// Get Distance to another collider
float CircleCollider::Distance(CircleCollider* collider)
{
	return sqrt(pow(transform->position.x - collider->transform->position.x, 2) + pow(transform->position.y - collider->transform->position.y, 2));
}

// Check if touching another collider
bool CircleCollider::IsColliding(CircleCollider* collider)
{
	int dx = collider->transform->position.x - transform->position.x;
	int dy = collider->transform->position.y - transform->position.y;
	int radii = radius + collider->radius;
	if ((dx * dx) + (dy * dy) < radii * radii)
	{
		return true;
	}
	return false;
}

// Check if it will collide
bool CircleCollider::WillCollide(CircleCollider* collider)
{
	int dx = collider->transform->position.x + collider->rigidbody->velocity.x - transform->position.x + rigidbody->velocity.x;
	int dy = collider->transform->position.y + collider->rigidbody->velocity.y - transform->position.y + rigidbody->velocity.y;
	int radii = radius + collider->radius;
	if ((dx * dx) + (dy * dy) < radii * radii)
	{
		return true;
	}
	return false;
}