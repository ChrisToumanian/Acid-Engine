#include "Transform.h"

// Constructor
Transform::Transform()
{
	name = "Transform";
	movedThisFrame = false;
	position = { 0, 0, 0 };
	rotation = { 0, 0, 0, 0 };
	scale = { 1, 1, 1 };
	origin = { 0, 0, 0 };
	size = { 0, 0, 0 };
}

// Update
void Transform::Update()
{
	if (movedThisFrame)
	{
		movedThisFrame = false;
	}
}

// Set Parent Transform
void Transform::SetParent(Transform* _parent)
{
	parent = _parent;
}

// Set Position 2D
void Transform::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

// Set Position 3D
void Transform::SetPosition(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

// Move 2D
void Transform::Move(float x, float y)
{
	position.x += x;
	position.y += y;
	movedThisFrame = true;
}

// Move 3D
void Transform::Move(float x, float y, float z)
{
	position.x += x;
	position.y += y;
	position.z += z;
	movedThisFrame = true;
}

// Rotate by Angle
void Transform::Rotate(float angle)
{
	rotation.angle += angle;
}

// Rotate 3D
void Transform::Rotate(float x, float y, float z)
{
	rotation.x += x;
	rotation.y += y;
	rotation.z += z;
}

// Set Rotation at Angle
void Transform::SetRotation(float angle)
{
	rotation.angle = angle;
}

// Set Rotation 3D
void Transform::SetRotation(float x, float y, float z)
{
	rotation.x = x;
	rotation.y = y;
	rotation.z = z;
}

// Set Uniform Scale
void Transform::SetUniformScale(float size)
{
	scale.x = size;
	scale.y = size;
	scale.z = size;
}

// Set Scale 2D
void Transform::SetScale(float x, float y)
{
	scale.x = x;
	scale.y = y;
}

// Set Scale 3D
void Transform::SetScale(float x, float y, float z)
{
	scale.x = x;
	scale.y = y;
	scale.z = z;
}

// Uniform Resize
void Transform::UniformResize(float size)
{
	scale.x *= size;
	scale.y *= size;
	scale.z *= size;
}

// Resize 2D
void Transform::Resize(float x, float y)
{
	scale.x *= x;
	scale.y *= y;
}

// Resize 3D
void Transform::Resize(float x, float y, float z)
{
	scale.x *= x;
	scale.y *= y;
	scale.z *= z;
}

// Set Origin 2D
void Transform::SetOrigin(float x, float y)
{
	origin.x = x;
	origin.y = y;
}

// Reset Origin
void Transform::ResetOrigin()
{
	origin.x = 0;
	origin.y = 0;
	origin.z = 0;
}

// Flip x-scale
void Transform::Flip()
{
	scale.x *= -1;
}

// Flip Right
void Transform::FlipRight()
{
	if (scale.x < 0)
	{
		scale.x *= -1;
	}
}

// Flip Left
void Transform::FlipLeft()
{
	if (scale.x > 0)
	{
		scale.x *= -1;
	}
}

// Get Angle
float Transform::GetAngle()
{
	return rotation.angle;
}

// Get Angle X
float Transform::GetAngleX()
{
	float x = cosf(GetAngle());
	return x;
}

// Get Angle Y
float Transform::GetAngleY()
{
	float y = sinf(GetAngle());
	return y;
}

// Set Size 2D
void Transform::SetSize(float width, float height)
{
	size.width = width;
	size.height = height;
}

// Set Size 3D
void Transform::SetSize(float width, float height, float depth)
{
	size.width = width;
	size.height = height;
	size.depth = depth;
}

// Get Width
float Transform::GetWidth()
{
	return size.width;
}

// Get Height
float Transform::GetHeight()
{
	return size.height;
}

// Get Depth
float Transform::GetDepth()
{
	return size.depth;
}

// Set Moved This Frame
void Transform::SetMovedThisFrame(bool moved)
{
	movedThisFrame = moved;
}

// Get Moved This Frame
bool Transform::GetMovedThisFrame()
{
	return movedThisFrame;
}