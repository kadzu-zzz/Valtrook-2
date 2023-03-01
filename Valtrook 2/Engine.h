#pragma once

class Logger;
class AssetDatabase;
class GraphicsManager;
class InputManager;

class Engine
{
public:
	static Engine* engine;

	Engine();
	~Engine();

	void run(bool* bRestart);
	void stop();

	Logger* getLogger();
	AssetDatabase* getAssets();
	GraphicsManager* getGraphicsManager();
	InputManager* getInputManager();
private:
	bool* bRestart;
	bool bRunning;

	Logger* logger;
	AssetDatabase* assets;
	GraphicsManager* graphics_manager;
	InputManager* input_manager;

	void engineLoop();
	void cleanup();

};

