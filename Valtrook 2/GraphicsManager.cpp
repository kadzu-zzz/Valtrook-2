#include "GraphicsManager.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "WindowData.h"
#include "WindowManager.h"
#include "Engine.h"
#include "AssetDatabase.h"
#include "EngineConfig.h"
#include "Logger.h"


GraphicsManager::GraphicsManager(GraphicsAPI api) : windowManager(api)
{
    glfwInit();

    windowManager.GetOrCreateWindow(Engine::engine->getAssets()->config.default_window_data.getValue());
}

GraphicsManager::~GraphicsManager()
{
    glfwTerminate();
}

WindowManager* GraphicsManager::getWindowManager()
{
    return &windowManager;
}

void GraphicsManager::loop()
{
    if (!windowManager.loop()) {
        Engine::engine->getLogger()->logMessage(INFO, "No Windows Open");
        Engine::engine->stop();
    }
    glfwPollEvents();
}
