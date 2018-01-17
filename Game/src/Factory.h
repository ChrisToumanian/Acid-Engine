#ifndef FACTORY
#define FACTORY

#include "Acid.h"
#include <string>

class Factory
{
public:
	static GraphicObject* CreateGraphicObject(string name, int x, int y, Scene* scene);
};

#endif