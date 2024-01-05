#pragma once

#include "IWindow.h"
#include "WindowData.h"

struct GLFWwindow;

class GLFWWindow : public IWindow
{
protected:
	GLFWwindow* window;

	WindowData data;

public:
	GLFWWindow(WindowData data);
	~GLFWWindow();

	WindowData* getData();

	bool IsValid();
	void Close();

	int getHeight();
	int getWidth();
	std::string getAlias();
	std::string getTitle();
	bool hasFullscreenTarget();
	int getFullscreenTarget();

	void WindowPoll();
};

