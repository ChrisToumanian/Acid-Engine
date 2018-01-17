#ifndef CAMERA_COMPONENT
#define CAMERA_COMPONENT

#include "Component.h"
#include "Transform.h"

class Camera : public Component
{
public:
	Camera(Transform* transform);
	virtual ~Camera() { };

	void Update() override;
	void Draw() {};
	void Enable();
	void Disable();
	void SetPosition(float posX, float posY);
	void SetSize(float w, float h);
	void SetOffset(float x, float y);
	void SetLockRotation(bool lock);
	float GetPosX();
	float GetPosY();
	float GetPosXOffset();
	float GetPosYOffset();
	float GetAngle();
	float GetWidth();
	float GetHeight();

private:
	Transform* transform;
	bool enabled;
	bool lockRotation;
	float x = 0;
	float y = 0;
	float offsetX = 0;
	float offsetY = 0;
	float angle;
	int width;
	int height;

};

#endif