#include "Engine.h"

#include "Logger.h"
#include "AssetDatabase.h"
#include "InputManager.h"
#include "GraphicsManager.h"
#include "NamedSerializable.h"
#include "Scene.h"
#include "RootScene.h"

#include <string>

Engine* Engine::engine = nullptr;

#include <windows.h> //For CreateDirectory.
static void CreateDirectoryIfItDoesNotExist(std::string directory) {
	CreateDirectory(LPCWSTR(directory.c_str()), NULL);
}

Engine::Engine() : bRestart(nullptr), bRunning(false)
{
	Engine::engine = this;
	logger = new Logger();
	assets = new AssetDatabase();
	input_manager = new InputManager();
	assets->EarlyLoad();

	graphics_manager = new GraphicsManager(assets->config.graphics_mode.getValue());
	root_scene = std::static_pointer_cast<Scene>(std::make_shared<RootScene>());
	root_scene->Initialize(root_scene);

	logger->outputLog();
}

Engine::~Engine()
{
	delete assets;
	delete graphics_manager;
	delete logger;
}

Logger* Engine::getLogger() {
	return logger;
}

AssetDatabase* Engine::getAssets()
{
	return assets;
}

GraphicsManager* Engine::getGraphicsManager()
{
	return graphics_manager;
}

InputManager* Engine::getInputManager()
{
	return input_manager;
}

std::shared_ptr<Scene> Engine::getRootScene()
{
	return root_scene;
}

void Engine::run(bool* bRestart)
{
	if (!bRunning) {
		this->bRestart = bRestart;
		bRunning = true;

		logger->outputLog();
		engineLoop();
	}
}

void Engine::stop(bool restart)
{
	if (bRunning) {
		bRunning = false;
		*bRestart = restart;
		logger->outputLog();
	}
}

void Engine::engineLoop()
{
	while (bRunning) {
		if (root_scene) {
			root_scene->Engine_Update();
			root_scene->Engine_Render();
		}

		graphics_manager->loop();

		logger->outputLog();
	}
	cleanup();
}

void Engine::cleanup()
{
	logger->outputLog();
	assets->Save();
}
