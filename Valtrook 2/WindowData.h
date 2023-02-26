#pragma once

#include <string>

struct GLFWmonitor;

struct WindowData {
public:
	int width;
	int height;
	std::string alias;
	std::string title;
	GLFWmonitor* fullscreen_target;
};