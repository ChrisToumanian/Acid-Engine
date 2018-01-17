#ifndef COMPONENT
#define COMPONENT

#include <iostream>
#include <string>
using namespace std;

class Component
{
public:
	virtual ~Component() { }
	virtual void Update() { }
	virtual void Draw() { }
	virtual void OnCollision() { }
	virtual void OnTrigger() { }
	virtual void ReceiveMessage(string message) { }
	string GetName() { return name; }

protected:
	string name;
};

#endif