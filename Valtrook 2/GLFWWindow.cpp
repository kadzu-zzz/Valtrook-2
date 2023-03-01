#include "GLFWWindow.h"

#include "Engine.h"
#include "Logger.h"
#include "GraphicsManager.h"
#include "WindowManager.h"
#include "AssetDatabase.h"
#include "EngineConfig.h"
#include "InputManager.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

GLFWWindow::GLFWWindow(WindowData data) : data(data)
{
    GLFWmonitor* targetMonitor = NULL;
    if (data.fullscreen_target > -1) {
        GLFWmonitor** monitors = glfwGetMonitors(&data.fullscreen_target);
        if (monitors != NULL) {
            targetMonitor = monitors[data.fullscreen_target];
        }
    }

    switch (Engine::engine->getAssets()->config.graphics_mode.getValue()) {
    case OpenGL:
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Engine::engine->getAssets()->config.gl_major_version.getValue());
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Engine::engine->getAssets()->config.gl_minor_version.getValue());
        break;
    case Vulkan:
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        break;
    }

    window = glfwCreateWindow(data.width, data.height, data.title.c_str(), targetMonitor, nullptr);

    switch (Engine::engine->getAssets()->config.graphics_mode.getValue()) {
    case OpenGL:
        glfwSetKeyCallback(window, key_callback);
        break;
    case Vulkan:
        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

        Engine::engine->getLogger()->logMessage(INFO, data.title + " supports " + std::to_string(extensionCount) + " extensions.\n");
        break;
    }
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Engine::engine->getInputManager()->GLFWRecieveInput(window, key, scancode, action, mods);
}

GLFWWindow::~GLFWWindow()
{
    Engine::engine->getGraphicsManager()->getWindowManager()->CloseWindow(data.alias);
}

WindowData* GLFWWindow::getData()
{
    return &data;
}

bool GLFWWindow::IsValid()
{
    if (window == NULL)
        return false;
    return !glfwWindowShouldClose(window);
}

void GLFWWindow::Close()
{   
    glfwDestroyWindow(window);
    window = NULL;
}

int GLFWWindow::getHeight()
{
    return data.height;
}

int GLFWWindow::getWidth()
{
    return data.width;
}

std::string GLFWWindow::getAlias()
{
    return data.alias;
}

std::string GLFWWindow::getTitle()
{
    return data.title;
}

bool GLFWWindow::hasFullscreenTarget()
{
    return data.fullscreen_target > -1;
}

int GLFWWindow::getFullscreenTarget()
{
    return data.fullscreen_target;
}

void GLFWWindow::WindowPoll()
{
    glfwPollEvents();
}
