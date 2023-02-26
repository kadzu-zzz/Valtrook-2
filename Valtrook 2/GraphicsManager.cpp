#include "GraphicsManager.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "WindowData.h"
#include "WindowManager.h"

GraphicsManager::GraphicsManager(GraphicsAPI api) : windowManager(api)
{
    glfwInit();

    WindowData defaultData;
    defaultData.alias = "main";
    defaultData.title = "main";
    defaultData.height = 800;
    defaultData.width = 600;
    defaultData.fullscreen_target = NULL;

    windowManager.GetOrCreateWindow(defaultData);
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
