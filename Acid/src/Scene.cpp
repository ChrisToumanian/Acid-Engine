#include "Scene.h"

Scene::Scene()
{
	running = true;
}

Scene::~Scene()
{

}

void Scene::SetWindow(Window* _window)
{
	window = _window;
}

void Scene::Update()
{
	PollEvents();
	UpdateGraphicObjects();
	ClearBuffer();
	RenderGraphicObjects();
	Render();
}

void Scene::SetActiveCamera(Camera* _camera)
{
	camera = _camera;
}

void Scene::EnableCollisionThread()
{
	running = true;
}

void Scene::DisableCollisionThread()
{
	running = false;
}

void Scene::CollisionLoop()
{
	while (running)
	{
		int size = graphicObjects.size();
		for (int i = 0; i < size; i++)
		{
			if (IsNearCamera(graphicObjects[i]))
			{
				CircleCollider* collider = (CircleCollider*)graphicObjects[i]->GetComponent("CircleCollider");
				if (collider != NULL)
				{
					collider->CheckCollisions();
				}
			}
		}
	}
}

bool Scene::IsNearCamera(GraphicObject* object)
{
	if (camera != nullptr)
	{
		Transform* transform = (Transform*)object->GetComponent("Transform");
		if (transform->position.x < camera->GetPosX() + (camera->GetWidth() / 1.5) && transform->position.x > camera->GetPosX() - (camera->GetWidth() / 1.5)
			&& transform->position.y < camera->GetPosY() + (camera->GetHeight() / 1.5) && transform->position.y > camera->GetPosY() - (camera->GetHeight() / 1.5))
		{
			return true;
		}
	}
	return false;
}

void Scene::Add(GraphicObject* graphicObject)
{
	int id = graphicObjects.size();
	graphicObject->SetID(id);
	graphicObjects.push_back(graphicObject);
}

void Scene::UpdateGraphicObjects()
{
	for (int i = 0; i < graphicObjects.size(); i++)
	{
		if (IsNearCamera(graphicObjects[i]) || i == 0)
		{
			graphicObjects[i]->Update();
		}
	}
}

void Scene::RenderGraphicObjects()
{
	for (int i = 0; i < graphicObjects.size(); i++)
	{
		if (IsNearCamera(graphicObjects[i]) || i == 0)
		{
			graphicObjects[i]->Draw();
		}
	}
}

void Scene::PollEvents()
{
	glfwPollEvents();
}

void Scene::ClearBuffer()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Scene::Render()
{
	glfwSwapBuffers(window->GetWindowContext());
}

void Scene::MakeCurrentContext()
{
	glfwMakeContextCurrent(window->GetWindowContext());
}

void Scene::Load(string filepath)
{

}

Window* Scene::GetWindow()
{
	return window;
}