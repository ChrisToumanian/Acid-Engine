#include "Components\Component.h"
#include "Components\Transform.h"
#include "GraphicObject.h"
#include "Utilities\Utilities.h"

class Asteroid : public Component
{
public:
	Asteroid(GraphicObject* parent) : parent(parent) { Start(); };
	virtual ~Asteroid() { }
	
	void Start()
	{
		transform = (Transform*)parent->GetComponent("Transform");
		rotationSpeed = Utilities::GetRandomFloat(-10, 10);
	}

	void Update()
	{
		transform->Rotate(rotationSpeed);
	}

	void OnCollision()
	{
		//parent->Destroy();
	}

private:
	GraphicObject* parent;
	Transform* transform;
	float rotationSpeed;
};