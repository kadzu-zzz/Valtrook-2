#include "GraphicsManager.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "WindowData.h"
#include "WindowManager.h"
#include "Engine.h"
#include "AssetDatabase.h"
#include "EngineConfig.h"
#include "Logger.h"

void error_callback(int error, const char* description);

GraphicsManager::GraphicsManager(GraphicsAPI api) : api(api), windowManager(api)
{
    switch (api) {
    case OpenGL:
    case Vulkan:
        glfwInit();
        glfwSetErrorCallback(error_callback);
        break;
    }

    windowManager.Initialize();
}

void error_callback(int error, const char* description)
{
    Engine::engine->getLogger()->logMessage(ERROR, description);
}


GraphicsManager::~GraphicsManager()
{
    switch (api) {
    case OpenGL:
    case Vulkan:
        glfwTerminate();
        break;
    }
}

WindowManager* GraphicsManager::getWindowManager()
{
    return &windowManager;
}

void GraphicsManager::loop()
{
    if (windowManager.loop() || windowManager.GetMainWindow() == nullptr) {
        Engine::engine->getLogger()->logMessage(INFO, "No Windows Open");
        Engine::engine->stop();
    }
    windowManager.GetMainWindow()->WindowPoll();
    if(renderingEngine.IsReady())
        renderingEngine.Display();
}
