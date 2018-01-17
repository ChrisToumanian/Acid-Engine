#include "Window.h"

struct Window::Position position = { 0, 0 };
struct Window::Color clearColor = { 0, 0, 0, 1 };

Window::Window()
{
	SCREEN_WIDTH = 1920;
	SCREEN_HEIGHT = 1080;
	SCALE_WIDTH = SCREEN_WIDTH;
	SCALE_HEIGHT = SCREEN_HEIGHT;
	FULLSCREEN = false;
	ORTHOGRAPHIC = true;
	SCALE = 1;
	IO_ENABLED = true;
	VSYNC = true;
	swapInterval = 1;
	ALPHA_BLENDING = true;
	windowCentered = true;
	windowTitle = "";
	BORDERED = true;
	RESIZABLE = false;
	window = NULL;
	monitor = NULL;
	parentWindow = NULL;
}

Window::~Window()
{

}

bool Window::Initialize()
{
	// Initialize GLFW
	if (!glfwInit())
	{
		return false;
	}

	// Create GLFW Window
	monitor = glfwGetPrimaryMonitor();
	glfwWindowHint(GLFW_RESIZABLE, RESIZABLE);
	glfwWindowHint(GLFW_DECORATED, BORDERED);
	if (FULLSCREEN)
	{
		SCREEN_WIDTH = GetMonitorWidth();
		SCREEN_HEIGHT = GetMonitorHeight();
		window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, monitor, parentWindow);
	}
	else {
		window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, parentWindow);
	}
	if (window == NULL)
	{
		return false;
	}

	// Set Clear Color
	glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);

	// OpenGL GLFW Setup
	glfwMakeContextCurrent(window);
	//int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	// VSYNC
	glfwSwapInterval(swapInterval);

	// Callbacks
	if (IO_ENABLED)
	{
		glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
		glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);
		glfwSetKeyCallback(window, Keyboard::KeyCallback);
	}

	// Window Position
	if (windowCentered)
	{
		const GLFWvidmode* mode = glfwGetVideoMode(monitor);
		position.x = (mode->width - SCREEN_WIDTH) / 2;
		position.y = (mode->height - SCREEN_HEIGHT) / 2;
	}
	glfwSetWindowPos(window, position.x, position.y);

	// GL Viewport & Orthographic Camera
	float scaleHeight = (float)SCREEN_HEIGHT / (float)SCALE_HEIGHT;
	float scaleWidth = (float)SCREEN_WIDTH / (float)SCALE_WIDTH;
	scaleOffset = (SCREEN_WIDTH - SCALE_WIDTH * scaleHeight) / 2;

	glViewport(scaleOffset, 0, width - scaleOffset * 2, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10);
	glScaled(scaleWidth * SCALE, scaleHeight * SCALE, 1);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);

	// Alpha Blending
	if (ALPHA_BLENDING)
	{
		glEnable(GL_ALPHA_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	return true;
}

void Window::SetCameraPosition(float x, float y)
{
	//glViewport(scaleOffset + -x * (SCREEN_WIDTH / SCALE_WIDTH), -y * (SCREEN_HEIGHT / SCALE_HEIGHT), SCREEN_WIDTH - scaleOffset * 2, SCREEN_HEIGHT);
	//glTranslatef(x, y, 0);
}

void Window::SetResolution(int width, int height)
{
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;
}

void Window::SetFullscreen(bool fullscreen)
{
	FULLSCREEN = fullscreen;
}

void Window::SetWindowTitle(char* title)
{
	windowTitle = title;
}

void Window::SetOrthographic(bool orthographic)
{
	ORTHOGRAPHIC = orthographic;
}

void Window::SetWindowPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

void Window::SetWindowCentered(bool centered)
{
	windowCentered = centered;
}

void Window::SetAlphaBlending(bool alphaBlending)
{
	ALPHA_BLENDING = alphaBlending;
}

void Window::SetClearColor(int r, int g, int b)
{
	clearColor.r = r;
	clearColor.g = g;
	clearColor.b = b;
	glClearColor(clearColor.r / 255, clearColor.g / 255, clearColor.b / 255, clearColor.a);
}

void Window::SetScale(float scale)
{
	SCALE = scale;
}

void Window::SetScale(int width, int height)
{
	SCALE_WIDTH = width;
	SCALE_HEIGHT = height;
}

void Window::SetResizable(bool resizable)
{
	RESIZABLE = resizable;
}

void Window::ShowBorder(bool bordered)
{
	BORDERED = bordered;
}

void Window::SetParentWindow(GLFWwindow* context)
{
	parentWindow = context;
}

int Window::GetWidth()
{
	return SCREEN_WIDTH;
}

int Window::GetHeight()
{
	return SCREEN_HEIGHT;
}

int Window::GetMonitorWidth()
{
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	return mode->width;
}

int Window::GetMonitorHeight()
{
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	return mode->height;
}

GLFWwindow* Window::GetWindowContext()
{
	return window;
}

void Window::SetVsync(bool vsync)
{
	if (vsync)
	{
		VSYNC = true;
	}
	else
	{
		VSYNC = false;
	}
}

void Window::SetSwapInterval(int interval)
{
	swapInterval = interval;
}

void Window::SetWindowIcon(string filepath)
{
	
}

void Window::Load(string filepath)
{
	XmlReader xml(filepath);

	// Window Title
	/*if (xml.FindValue("fullscreen") != "")
	{
		char* windowTitle = Utilities::StringToChar(xml.FindValue("windowTitle"));
		SetWindowTitle(windowTitle);
	} */
	
	// Fullscreen
	if (xml.FindValue("fullscreen") != "")
	{
		if (xml.FindValue("fullscreen") == "true")
		{
			SetFullscreen(true);
		}
		else
		{
			SetFullscreen(false);
		}
	}

	// Window Centered
	if (xml.FindValue("windowCentered") != "")
	{
		if (xml.FindValue("windowCentered") == "true")
		{
			SetWindowCentered(true);
		}
		else
		{
			SetWindowCentered(false);
		}
	}

	// Resolution
	if (xml.FindValue("resolutionWidth") != "" && xml.FindValue("resolutionHeight") != "")
	{
		SetResolution(stoi(xml.FindValue("resolutionWidth")), stoi(xml.FindValue("resolutionHeight")));
	}

	// Scale Resolution
	if (xml.FindValue("scaleWidth") != "" && xml.FindValue("scaleHeight") != "")
	{
		SetScale(stoi(xml.FindValue("scaleWidth")), stoi(xml.FindValue("scaleHeight")));
	}

	// Scale
	if (xml.FindValue("scale") != "")
	{
		SetScale(::atof(xml.FindValue("scale").c_str()));
	}

	// Show Border
	if (xml.FindValue("windowBorder") != "")
	{
		if (xml.FindValue("windowBorder") == "false")
		{
			ShowBorder(false);
		}
		else
		{
			ShowBorder(true);
		}
	}

	// Window Position
	if (xml.FindValue("windowPositionX") != "" && xml.FindValue("windowPositionY") != "")
	{
		SetWindowPosition(stoi(xml.FindValue("windowPositionX")), stoi(xml.FindValue("windowPositionY")));
	}

	Initialize();

}