#pragma once

#include "IWindow.h"
#include "WindowData.h"

class DirectXWindow : public IWindow
{
private:
	//GLFWwindow* window;

	WindowData data;

public:
	DirectXWindow(WindowData data);
	~DirectXWindow();

	WindowData* getData();

	bool IsValid();
	void Close();

	int getHeight();
	int getWidth();
	std::string getAlias();
	std::string getTitle();
	bool hasFullscreenTarget();
	int getFullscreenTarget();
};

