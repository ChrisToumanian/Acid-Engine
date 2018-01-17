#include "BoxCollider.h"

// Constructor
BoxCollider::BoxCollider(Transform* transform, Rigidbody2D* rigidbody, vector<GraphicObject*>* graphicObjectLayer) : transform(transform), rigidbody(rigidbody), layer(graphicObjectLayer)
{
	name = "BoxCollider";
	enabled = true;
	SetSize(transform->GetWidth(), transform->GetHeight());
	SetOffset(transform->origin.x, transform->origin.y);
}

// Update
void BoxCollider::Update()
{
	if (enabled)
	{
		vector<GraphicObject*> graphics = *layer;
		int size = layer->size();
		for (int i = 0; i < size; i++)
		{	
			GraphicObject* object = graphics[i];
			BoxCollider* collider = (BoxCollider*)object->GetComponent("BoxCollider");
			if (collider != NULL)
			{
				float distance = Distance(collider);
				if (distance < 16)
				{
					if (isRightOf(collider))
					{
						rigidbody->ChangeVelocity(collider->rigidbody->velocity.x, 0);
					}
					else
					{
						rigidbody->ChangeVelocity(-collider->rigidbody->velocity.x, 0);
					}
					if (isAbove(collider))
					{
						rigidbody->ChangeVelocity(0, collider->rigidbody->velocity.y);
					}
					else
					{
						rigidbody->ChangeVelocity(0, -collider->rigidbody->velocity.y);
					}
				}
			}
		}
	}
}

// Set Size
void BoxCollider::SetSize(float width, float height)
{
	size.x = width;
	size.y = height;
}

// Set Offset
void BoxCollider::SetOffset(float offsetX, float offsetY)
{
	offset.x = offsetX;
	offset.y = offsetY;
}

// Enable
void BoxCollider::Enable()
{
	enabled = true;
}

// Disable
void BoxCollider::Disable()
{
	enabled = false;
}

// Get Distance to another collider
float BoxCollider::Distance(BoxCollider* collider)
{
	return sqrt(pow(transform->position.x - collider->transform->position.x, 2) + pow(transform->position.y - collider->transform->position.y, 2));
}

// Get Direction to another collider
float BoxCollider::Direction(BoxCollider* collider)
{
	float direction = 0;
	return direction;
}

// Check if touching another collider
bool BoxCollider::isTouching(BoxCollider* collider)
{
	return false;
}

// Check if it is to right of another collider
bool BoxCollider::isRightOf(BoxCollider* collider)
{
	if (transform->position.x > collider->transform->position.x)
	{
		return true;
	}
	return false;
}

// Check if it is above of another collider
bool BoxCollider::isAbove(BoxCollider* collider)
{
	if (transform->position.y > collider->transform->position.y)
	{
		return true;
	}
	return false;
}