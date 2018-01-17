#ifndef TRANSFORM_COMPONENT
#define TRANSFORM_COMPONENT

#include "Component.h"
#include "Transform.h"

struct Position
{
	float x;
	float y;
	float z;
};

struct Rotation
{
	float angle;
	float x;
	float y;
	float z;
};

struct Scale
{
	float x;
	float y;
	float z;
};

struct Size
{
	float width;
	float height;
	float depth;
};

struct Origin
{
	float x;
	float y;
	float z;
};

class Transform : public Component
{
public:
	Transform();
	virtual ~Transform() { };

	void Update();
	void Draw() { };

	void SetParent(Transform* _parent);
	void ResetOrigin();
	void Move(float x, float y);
	void Move(float x, float y, float z);
	void Rotate(float angle);
	void Rotate(float x, float y, float z);
	void UniformResize(float size);
	void Resize(float x, float y);
	void Resize(float x, float y, float z);
	void Flip();
	void FlipRight();
	void FlipLeft();

	void SetPosition(float x, float y);
	void SetPosition(float x, float y, float z);
	void SetRotation(float angle);
	void SetRotation(float x, float y, float z);
	void SetUniformScale(float size);
	void SetScale(float x, float y);
	void SetScale(float x, float y, float z);
	void SetOrigin(float x, float y);
	void SetSize(float width, float height);
	void SetSize(float width, float height, float depth);
	void SetMovedThisFrame(bool moved);
	bool GetMovedThisFrame();

	float GetWidth();
	float GetHeight();
	float GetDepth();
	float GetAngle();
	float GetAngleX();
	float GetAngleY();

	Position position;
	Rotation rotation;
	Scale scale;
	Size size;
	Origin origin;

private:
	Transform* parent;
	bool movedThisFrame;

};

#endif