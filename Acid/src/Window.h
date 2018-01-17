#ifndef ACID_WINDOW
#define ACID_WINDOW

#include <string>
#include <vector>
#include "Utilities/Utilities.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"
#include "GraphicObject.h"
#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")
#include "Utilities/XmlReader.h"

using namespace std;

class Window
{
public:
	Window();
	~Window();

	GLFWwindow* GetWindowContext();

	bool Initialize();
	void Load(string filepath);
	void SetResolution(int width, int height);
	void SetFullscreen(bool fullscreen);
	void SetWindowTitle(char* title);
	void SetOrthographic(bool orthographic);
	void SetWindowPosition(int x, int y);
	void SetWindowCentered(bool centered);
	void SetAlphaBlending(bool alphaBlending);
	void SetClearColor(int r, int g, int b);
	void SetScale(float scale);
	void SetScale(int width, int height);
	void ShowBorder(bool bordered);
	void SetResizable(bool resizable);
	void SetParentWindow(GLFWwindow* context);
	void SetVsync(bool vsync);
	void SetSwapInterval(int interval);
	void SetWindowIcon(string filepath);
	void SetCameraPosition(float x, float y);
	int GetWidth();
	int GetHeight();
	int GetMonitorWidth();
	int GetMonitorHeight();

	struct Position
	{
		int x;
		int y;
	};

	struct Color
	{
		int r;
		int g;
		int b;

		int a;
	};

private:
	GLFWwindow* window;
	GLFWwindow* parentWindow;
	GLFWmonitor* monitor;
	char* windowTitle;
	bool windowCentered;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	int SCALE_WIDTH;
	int SCALE_HEIGHT;
	int swapInterval;
	float SCALE;
	bool ORTHOGRAPHIC;
	bool FULLSCREEN;
	bool IO_ENABLED;
	bool VSYNC;
	bool ALPHA_BLENDING;
	bool RESIZABLE;
	bool BORDERED;
	float scaleOffset;
	int width;
	int height;
};

#endif