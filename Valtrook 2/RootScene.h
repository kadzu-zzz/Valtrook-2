#pragma once
#include "Scene.h"
#include "Engine.h"
#include "Logger.h"

class RootScene final : public Scene
{
public:
	RootScene() : Scene(true, true) {}

private:
	void Update() {
		Engine::engine->getLogger()->logMessage(INFO, "Updating.\n");
	};
	void Render() {};
};

