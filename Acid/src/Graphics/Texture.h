#ifndef ACID_TEXTURE
#define ACID_TEXTURE

#include "GLFW/glfw3.h"
#include "soil.h"

#include <iostream>
#include <string>
using namespace std;

class Texture
{
public:
	Texture();
	Texture(int _id);
	Texture(string path);

	void DisableSmoothing();

	int GetID();
	int GetWidth();
	int GetHeight();

private:
	bool GetTextureParams();
	
	int id;
	int width;
	int height;

};

#endif