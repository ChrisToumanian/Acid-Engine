#ifndef SPRITE_COMPONENT
#define SPRITE_COMPONENT

#include "Component.h"
#include "Transform.h"
#include "../Scene.h"
#include "../Graphics/Texture.h"
#include "GLFW/glfw3.h"

struct Color
{
	int r;
	int g;
	int b;
	int a;
};

struct Clip
{
	int x;
	int y;
	int w;
	int h;
};

class Sprite : public Component
{
public:
	Sprite(Transform* transform, Texture* texture, Scene* scene);
	virtual ~Sprite() { };

	void Update() override;
	void Draw() override;

	void SetColor(int r, int g, int b);
	void SetColor(int r, int g, int b, int a);
	void SetClip(int x, int y);
	void SetClip(int x, int y, int w, int h);

private:
	Scene* scene{ nullptr };
	Transform* transform{ nullptr };
	Texture* texture{ nullptr };
	Color color;
	Clip clip;
	int width;
	int height;
	
};

#endif