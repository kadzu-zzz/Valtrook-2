#pragma once

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <string>

#include "IWindow.h"
#include "WindowData.h"
#include "GraphicsAPI.h"

class IWindow;

class WindowManager
{
protected:
	GraphicsAPI api;
	std::unordered_map<std::string, std::shared_ptr<IWindow>> windows;
	std::unordered_set<std::string> windows_to_close;
public:
	WindowManager(GraphicsAPI api);
	~WindowManager();

	std::shared_ptr<IWindow> GetWindow(std::string windowAlias);
	std::shared_ptr<IWindow> GetOrCreateWindow(WindowData data);

	void CloseWindow(std::string alias);
	void ProcessCloseWindows();

	bool loop();
};

