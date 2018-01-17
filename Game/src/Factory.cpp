#include "Factory.h"
#include "Asteroid.cpp"

GraphicObject* Factory::CreateGraphicObject(string name, int x, int y, Scene* scene)
{
	if (name == "bg")
	{
		GraphicObject* object = new GraphicObject(&scene->graphicObjects);
		Transform* transform = new Transform();
		transform->SetPosition(x, y);
		object->AddComponent(transform);
		Texture* texture = new Texture("Assets/Images/SpaceBGEarth.png");
		Sprite* sprite = new Sprite(transform, texture, scene);
		transform->ResetOrigin();
		object->AddComponent(sprite);
		scene->Add(object);
		return object;
	}
	else if (name == "playership")
	{
		GraphicObject* object = new GraphicObject(&scene->graphicObjects);
		Transform* transform = new Transform();
		transform->SetPosition(x, y);
		object->AddComponent(transform);
		Texture* texture = new Texture("Assets/Images/playership1.png");
		Sprite* sprite = new Sprite(transform, texture, scene);
		object->AddComponent(sprite);
		Rigidbody2D* rigidbody = new Rigidbody2D(transform);
		rigidbody->RotateWithVelocityEnabled(true);
		rigidbody->SetDrag(0.97);
		rigidbody->SetMass(3);
		object->AddComponent(rigidbody);
		Container2D* container = new Container2D(transform, rigidbody);
		object->AddComponent(container);
		Controller* controller = new Controller(transform, rigidbody);
		controller->SetForceEnabled(true);
		controller->SetSpeed(0);
		object->AddComponent(controller);
		CircleCollider* collider = new CircleCollider(transform, rigidbody, &scene->graphicObjects);
		object->AddComponent(collider);
		Camera* camera = new Camera(transform);
		object->AddComponent(camera);
		scene->Add(object);
		return object;
	}
	else if (name == "asteroid")
	{
		GraphicObject* object = new GraphicObject(&scene->graphicObjects);
		Transform* transform = new Transform();
		transform->SetPosition(x, y);
		object->AddComponent(transform);
		Texture* texture = new Texture("Assets/Images/smallasteroid01.png");
		Sprite* sprite = new Sprite(transform, texture, scene);
		object->AddComponent(sprite);
		Rigidbody2D* rigidbody = new Rigidbody2D(transform);
		rigidbody->SetVelocity(Utilities::GetRandomFloat(-2, 2), Utilities::GetRandomFloat(-2, 2));
		object->AddComponent(rigidbody);
		Container2D* container = new Container2D(transform, rigidbody);
		object->AddComponent(container);
		Asteroid* asteroid = new Asteroid(object);
		object->AddComponent(asteroid);
		CircleCollider* collider = new CircleCollider(transform, rigidbody, &scene->graphicObjects);
		object->AddComponent(collider);
		scene->Add(object);
		return object;
	}
	else if (name == "particle")
	{
		GraphicObject* object = new GraphicObject(&scene->graphicObjects);
		Transform* transform = new Transform();
		transform->SetPosition(x, y);
		object->AddComponent(transform);
		Texture* texture = new Texture("Assets/Images/YellowLaser.png");
		Sprite* sprite = new Sprite(transform, texture, scene);
		object->AddComponent(sprite);
		Rigidbody2D* rigidbody = new Rigidbody2D(transform);
		rigidbody->RotateWithVelocityEnabled(true);
		object->AddComponent(rigidbody);
		CircleCollider* collider = new CircleCollider(transform, rigidbody, &scene->graphicObjects);
		object->AddComponent(collider);
		scene->Add(object);
		return object;
	}
	return nullptr;
}