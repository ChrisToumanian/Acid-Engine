#include "GraphicObject.h"

// GraphicObject Constructor
GraphicObject::GraphicObject(vector<GraphicObject*>* graphicObjectList) : graphicObjectList(graphicObjectList)
{
}

// Update Components
void GraphicObject::Update()
{
	for (auto& c : components) c->Update();
}

// Draw Components
void GraphicObject::Draw()
{
	for (auto& c : components) c->Draw();
}

// Set ID
void GraphicObject::SetID(int _id)
{
	id = _id;
}

// Destroy
void GraphicObject::Destroy()
{
	for (auto& c : components) delete c;
	graphicObjectList[id] = graphicObjectList[graphicObjectList->size() - 1];
	graphicObjectList->erase(graphicObjectList->end() - 1);
	delete this;
}

// Add Component
void GraphicObject::AddComponent(Component* component)
{
	components.push_back(component);
}

// Get Component
Component* GraphicObject::GetComponent(string name)
{
	for (auto& c : components)
	{
		if (c->GetName() == name)
		{
			return c;
		}
	}
	return nullptr;
}

// On Collision
void GraphicObject::OnCollision()
{
	for (auto& c : components) c->OnCollision();
}

// On Trigger
void GraphicObject::OnTrigger()
{
	for (auto& c : components) c->OnTrigger();
}

// Receive Message
void GraphicObject::ReceiveMessage(string message)
{
	for (auto& c : components) c->ReceiveMessage(message);
}