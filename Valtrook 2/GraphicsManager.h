#pragma once

#include "GraphicsAPI.h"
#include "WindowManager.h"
#include <memory>


class GraphicsManager
{
private:
	GraphicsAPI api;
	WindowManager windowManager;
public:
	GraphicsManager(GraphicsAPI api);
	~GraphicsManager();


	WindowManager* getWindowManager();



	void loop();
};

