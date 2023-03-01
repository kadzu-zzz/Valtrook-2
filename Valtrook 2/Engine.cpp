#include "Engine.h"

#include "Logger.h"
#include "AssetDatabase.h"
#include "InputManager.h"
#include "GraphicsManager.h"
#include "NamedSerializable.h"

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

void Engine::run(bool* bRestart)
{
	if (!bRunning) {
		this->bRestart = bRestart;
		bRunning = true;

		logger->outputLog();
		engineLoop();
	}
}

void Engine::stop()
{
	if (bRunning) {
		bRunning = false;
		logger->outputLog();
	}
}

void Engine::engineLoop()
{
	while (bRunning) {
		logger->logMessage(SEVERE, "AAA");
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
