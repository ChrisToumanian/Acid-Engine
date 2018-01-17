#ifndef ACID_SCENE
#define ACID_SCENE

#include <string>
#include <vector>
#include <thread>
#include "GraphicObject.h"
#include "Window.h"
#include "Utilities/Utilities.h"
#include "GLFW/glfw3.h"
#include "Utilities/XmlReader.h"
#include "Components/CircleCollider.h"
#include "Components/Camera.h"

using namespace std;

class Scene
{
public:
	Scene();
	~Scene();

	vector<GraphicObject*> graphicObjects;

	void Load(string filepath);
	void Add(GraphicObject* graphicObject);
	void Update();
	void Render();
	void SetWindow(Window* window);
	void SetActiveCamera(Camera* camera);
	void MakeCurrentContext();
	void CollisionLoop();
	void EnableCollisionThread();
	void DisableCollisionThread();
	Window* GetWindow();
	Camera* camera{ nullptr };
	
private:
	void UpdateGraphicObjects();
	void RenderGraphicObjects();
	void PollEvents();
	void ClearBuffer();
	bool IsNearCamera(GraphicObject* object);

	Window* window;
	bool running;
};

#endif