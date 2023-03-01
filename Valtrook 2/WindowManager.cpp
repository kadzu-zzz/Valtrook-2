#include "WindowManager.h"

#include "GLFWWindow.h"
#include "Engine.h"
#include "AssetDatabase.h"
#include "EngineConfig.h"

WindowManager::WindowManager(GraphicsAPI api) : api(api), windows()
{
	mainWindow = GetOrCreateWindow(Engine::engine->getAssets()->config.default_window_data.getValue());
}

WindowManager::~WindowManager()
{	
	windows.clear();
}

std::shared_ptr<IWindow> WindowManager::GetMainWindow()
{
	return mainWindow;
}

std::shared_ptr<IWindow> WindowManager::GetWindow(std::string windowAlias)
{
	if (auto search = windows.find(windowAlias); search != windows.end())
		return search->second;
	return NULL;
}

std::shared_ptr<IWindow> WindowManager::GetOrCreateWindow(WindowData data)
{
	if (auto search = windows.find(data.alias); search != windows.end()) {
		return search->second;
	}

	switch (api) {
		case GraphicsAPI::Vulkan:
		case GraphicsAPI::OpenGL:
			windows[data.alias] = std::make_shared<GLFWWindow>(data);
		break;
	}

	return windows[data.alias];
}

void WindowManager::CloseWindow(std::string alias)
{
	windows_to_close.insert(alias);
}

void WindowManager::ProcessCloseWindows()
{
	for (auto window : windows_to_close) {
		windows.at(window)->Close();
		windows.extract(window);
	}
	windows_to_close.clear();
}

bool WindowManager::loop()
{
	if (windows.empty())
		return false;

	auto close_windows = std::vector<std::string>();
	for (auto vals : windows) {
		if (!vals.second->IsValid()) {
			windows_to_close.insert(vals.first);
		}
	}
	ProcessCloseWindows();

	return true;
}
