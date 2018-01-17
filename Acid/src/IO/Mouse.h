#ifndef ACID_MOUSE
#define ACID_MOUSE

#include "GLFW/glfw3.h"

class Mouse
{
public:
	static void MousePosCallback(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	static bool ButtonDown(int button);
	static bool ButtonUp(int button);
	static bool Button(int button);

	static double GetMouseX();
	static double GetMouseY();

private:
	static double x;
	static double y;

	static bool buttons[];
	static bool buttonsDown[];
	static bool buttonsUp[];

};

#endif