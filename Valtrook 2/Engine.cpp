#include "Engine.h"

#include "Logger.h"

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
}

Engine::~Engine()
{
	delete logger;
}

Logger* Engine::getLogger() {
	return logger;
}

void Engine::intialise()
{


	logger->outputLog();
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

		stop();

		logger->logMessage(SEVERE, "AAA");
		logger->logMessage(SEVERE, "AAA");
		logger->logMessage(SEVERE, "AAA");

		logger->outputLog();
	}
	cleanup();
}

void Engine::cleanup()
{

	logger->outputLog();
}
