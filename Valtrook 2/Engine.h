#pragma once

class Logger;
class AssetDatabase;
class GraphicsManager;
class InputManager;
class Scene;

#include <memory>

class Engine
{
public:
	static Engine* engine;

	Engine();
	~Engine();

	void run(bool* bRestart);
	void stop(bool restart = false); 

	Logger* getLogger();
	AssetDatabase* getAssets();
	GraphicsManager* getGraphicsManager();
	InputManager* getInputManager();
	std::shared_ptr<Scene> getRootScene();
private:
	bool* bRestart;
	bool bRunning;

	std::shared_ptr<Scene> root_scene;
	Logger* logger;
	AssetDatabase* assets;
	GraphicsManager* graphics_manager;
	InputManager* input_manager;

	void engineLoop();
	void cleanup();
};

