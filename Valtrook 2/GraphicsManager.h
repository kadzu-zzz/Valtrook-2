#pragma once

#include "GraphicsAPI.h"
#include "WindowManager.h"
#include "RenderingEngine.h"

#include <memory>


class GraphicsManager
{
private:
	GraphicsAPI api;
	WindowManager windowManager;
	RenderingEngine renderingEngine;
public:
	GraphicsManager(GraphicsAPI api);
	~GraphicsManager();


	WindowManager* getWindowManager();

	RenderingEngine* getRenderingEngine();

	void loop();
};

