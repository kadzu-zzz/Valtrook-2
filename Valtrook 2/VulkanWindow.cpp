#include "VulkanWindow.h"

#include "Engine.h"
#include "Logger.h"
#include "GraphicsManager.h"
#include "WindowManager.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

VulkanWindow::VulkanWindow(WindowData data) : data(data)
{
    GLFWmonitor* targetMonitor = NULL;
    if (data.fullscreen_target > -1) {
        GLFWmonitor** monitors = glfwGetMonitors(&data.fullscreen_target);
        if (monitors != NULL) {
            targetMonitor = monitors[data.fullscreen_target];
        }
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(data.width, data.height, data.title.c_str(), targetMonitor, nullptr);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    Engine::engine->getLogger()->logMessage(INFO, data.title + " supports " + std::to_string(extensionCount) + " extensions.\n");
}

VulkanWindow::~VulkanWindow()
{
    Engine::engine->getGraphicsManager()->getWindowManager()->CloseWindow(data.alias);
}

WindowData* VulkanWindow::getData()
{
    return &data;
}

bool VulkanWindow::IsValid()
{
    if (window == NULL)
        return false;
    return !glfwWindowShouldClose(window);
}

void VulkanWindow::Close()
{   
    glfwDestroyWindow(window);
    window = NULL;
}

int VulkanWindow::getHeight()
{
    return data.height;
}

int VulkanWindow::getWidth()
{
    return data.width;
}

std::string VulkanWindow::getAlias()
{
    return data.alias;
}

std::string VulkanWindow::getTitle()
{
    return data.title;
}

bool VulkanWindow::hasFullscreenTarget()
{
    return data.fullscreen_target > -1;
}

int VulkanWindow::getFullscreenTarget()
{
    return data.fullscreen_target;
}
