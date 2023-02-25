#pragma once

class Logger;

class Engine
{
public:
	static Engine* engine;

	Engine();
	~Engine();

	void intialise();
	void run(bool* bRestart);
	void stop();

	Logger* getLogger();
private:
	bool* bRestart;
	bool bRunning;

	Logger* logger;

	void engineLoop();
	void cleanup();

};

