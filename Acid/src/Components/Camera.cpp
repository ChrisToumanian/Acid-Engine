#include "Camera.h"

// Constructor
Camera::Camera(Transform* transform) : transform(transform)
{
	name = "Camera";
	enabled = true;
	lockRotation = true;
	angle = 0;
}

// Update
void Camera::Update()
{
	x = transform->position.x;
	y = transform->position.y;
	if (!lockRotation)
	{
		angle = transform->GetAngle();
	}
}

// Set Size
void Camera::SetSize(float w, float h)
{
	width = w;
	height = h;
}

// Set Offset
void Camera::SetOffset(float x, float y)
{
	offsetX = x;
	offsetY = y;
}

// Enable
void Camera::Enable()
{
	enabled = true;
}

// Disable
void Camera::Disable()
{
	enabled = false;
}

// Lock Rotation
void Camera::SetLockRotation(bool lock)
{
	lockRotation = lock;
}

// Set Position
void Camera::SetPosition(float posX, float posY)
{
	x = posX;
	y = posY;
}

// Get PosX
float Camera::GetPosX()
{
	return x;
}

// Get PosY
float Camera::GetPosY()
{
	return y;
}

// Get PosX Offset
float Camera::GetPosXOffset()
{
	return x + offsetX;
}

// Get PosY Offset
float Camera::GetPosYOffset()
{
	return y + offsetY;
}

// Get Angle
float Camera::GetAngle()
{
	return angle;
}

// Get Width
float Camera::GetWidth()
{
	return width;
}

// Get Height
float Camera::GetHeight()
{
	return height;
}