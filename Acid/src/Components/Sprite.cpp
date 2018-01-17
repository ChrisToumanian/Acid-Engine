#include "Sprite.h"

// Constructor
Sprite::Sprite(Transform* transform, Texture* texture, Scene* scene) : transform(transform), texture(texture), scene(scene)
{
	name = "Sprite";
	width = texture->GetWidth();
	height = texture->GetHeight();
	color = { 1, 1, 1, 1 };
	clip = { 0, 0, width, height };
	texture->DisableSmoothing();
	transform->SetSize(width, height);
	transform->SetOrigin(width / 2, height / 2);
}

// Update
void Sprite::Update()
{
}

// Draw
void Sprite::Draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture->GetID());
	glLoadIdentity();

	// Translate -> Rotate -> Scale
	if (scene->camera != nullptr)
	{
		glTranslatef(transform->position.x - scene->camera->GetPosXOffset(), transform->position.y - scene->camera->GetPosYOffset(), transform->position.z);
		glRotatef(transform->rotation.angle, 0, 0, 1);
		glTranslatef(transform->origin.x * -transform->scale.x, -transform->origin.y * transform->scale.y, -transform->origin.z * transform->scale.z);
		glScalef(transform->scale.x, transform->scale.y, transform->scale.z);
	}
	else
	{
		glTranslatef(transform->position.x, transform->position.y, transform->position.z);
		glRotatef(transform->rotation.angle, 0, 0, 1);
		glTranslatef(transform->origin.x * -transform->scale.x, -transform->origin.y * transform->scale.y, -transform->origin.z * transform->scale.z);
		glScalef(transform->scale.x, transform->scale.y, transform->scale.z);
	}

	// Tint & Texture Coordinates
	glColor4f(color.r, color.g, color.b, color.a);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);		glVertex2f(0, 0);											// Bottom Left
	glTexCoord2f(1, 0);		glVertex2f(transform->GetWidth(), 0);						// Bottom Right
	glTexCoord2f(1, 1);		glVertex2f(transform->GetWidth(), transform->GetHeight());	// Top Right
	glTexCoord2f(0, 1);		glVertex2f(0, transform->GetHeight());						// Top Left
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

// Set Color w/o alpha
void Sprite::SetColor(int r, int g, int b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}

// Set Color with alpha
void Sprite::SetColor(int r, int g, int b, int a)
{
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}

// Set Clip Position
void Sprite::SetClip(int x, int y)
{
	clip.x = x;
	clip.y = y;
}

// Set Clip Position & Dimensions
void Sprite::SetClip(int x, int y, int w, int h)
{
	clip.x = x;
	clip.y = y;
	clip.w = w;
	clip.h = h;
}