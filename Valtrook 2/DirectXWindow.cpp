#include "DirectXWindow.h"

#include "Engine.h"
#include "Logger.h"
#include "GraphicsManager.h"
#include "WindowManager.h"

DirectXWindow::DirectXWindow(WindowData data) : data(data) 
{
}

DirectXWindow::~DirectXWindow()
{
    Engine::engine->getGraphicsManager()->getWindowManager()->CloseWindow(data.alias);
}

WindowData* DirectXWindow::getData()
{
    return &data;
}

bool DirectXWindow::IsValid()
{
    return false;
}

void DirectXWindow::Close()
{
}

int DirectXWindow::getHeight()
{
    return data.height;
}

int DirectXWindow::getWidth()
{
    return data.width;
}

std::string DirectXWindow::getAlias()
{
    return data.alias;
}

std::string DirectXWindow::getTitle()
{
    return data.title;
}

bool DirectXWindow::hasFullscreenTarget()
{
    return data.fullscreen_target > -1;
}

int DirectXWindow::getFullscreenTarget()
{
    return data.fullscreen_target;
}
