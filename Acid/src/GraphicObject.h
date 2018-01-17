#ifndef ACID_GRAPHICOBJECT
#define ACID_GRAPHICOBJECT

#include "Components/Component.h"
#include <string>
#include <vector>
using namespace std;

class GraphicObject
{
public:
	GraphicObject(vector<GraphicObject*>* graphicObjectList);
	void Update();
	void Draw();
	void SetID(int _id);
	void AddComponent(Component* component);
	void Destroy();
	void OnCollision();
	void OnTrigger();
	void ReceiveMessage(string message);
	Component* GetComponent(string name);

	vector<Component*> components;

protected:
	vector<GraphicObject*>* graphicObjectList;
	int id;
};

#endif