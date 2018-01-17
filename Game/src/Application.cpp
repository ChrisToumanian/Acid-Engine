#include "Acid.h"
#include "Factory.h"
#include <thread>

using namespace std;

void CollisionLoop(Scene* scene)
{
	scene->CollisionLoop();
}

int main()
{
	// Initialize Scene
	bool running = true;
	/* int width = 440;
	int height = 320; */
	int width = 860;
	int height = 360;
	int levelWidth = 1243;
	int levelHeight = 720;
	Window window;
	window.SetWindowTitle("SPAAACE");
	window.SetScale(width, height);
	/* window.SetResolution(1320, 960);
	window.SetFullscreen(false); */
	window.SetResolution(3440, 1440);
	window.SetFullscreen(true);
	window.Initialize();

	Scene* scene = new Scene();
	scene->SetWindow(&window);

	// Background
	Factory::CreateGraphicObject("bg", 0, 0, scene);

	// Asteroids
	for (int i = 0; i < 1000; i++)
	{
		GraphicObject* asteroid = Factory::CreateGraphicObject("asteroid", Utilities::GetRandomInt(0, width), Utilities::GetRandomInt(0, height), scene);
		Container2D* container = (Container2D*)asteroid->GetComponent("Container2D");
		container->SetDimensions(0, 0, levelWidth, levelHeight);
	}

	// Player Ship
	GraphicObject* playerShip = Factory::CreateGraphicObject("playership", width / 2, height / 2, scene);
	Container2D* playerShipContainer = (Container2D*)playerShip->GetComponent("Container2D");
	playerShipContainer->SetDimensions(0, 0, levelWidth, levelHeight);
	Transform* playerShipTransform = (Transform*)playerShip->GetComponent("Transform");
	Rigidbody2D* playerShipRigidbody2D = (Rigidbody2D*)playerShip->GetComponent("Rigidbody2D");
	Camera* camera = (Camera*)playerShip->GetComponent("Camera");
	camera->SetPosition(playerShipTransform->position.x, playerShipTransform->position.y);
	camera->SetSize(width, height);
	camera->SetOffset(-width / 2, -height / 2);
	scene->SetActiveCamera(camera);
	
	// Collisions
	//thread collisions(CollisionLoop, scene);

	// Render Loop
	while (running)
	{
		// Exit game when escape is pressed
		if (Keyboard::KeyDown(GLFW_KEY_ESCAPE))
		{
			running = false;
			scene->DisableCollisionThread();
			glfwTerminate();
			terminate;
			break;
		}

		// Shoot Particle
		if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_1))
		{
			GraphicObject* particle = Factory::CreateGraphicObject("particle", playerShipTransform->position.x, playerShipTransform->position.y, scene);
			Rigidbody2D* particleRigidbody = (Rigidbody2D*)particle->GetComponent("Rigidbody2D");
			particleRigidbody->velocity = playerShipRigidbody2D->velocity;
			particleRigidbody->ChangeVelocity(particleRigidbody->velocity.x * 4, particleRigidbody->velocity.y * 4);
		}
		 
		// Update Scene
		scene->Update();
	}

	return 0;
}