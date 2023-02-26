#pragma once

#include "Engine.h"
#include "IConfigSerializable.h"
#include "Logger.h"

enum GraphicsAPI {
	Vulkan,
	OpenGL
};

class GraphicsAPIWrapper : public IConfigSerializable {
public:
	GraphicsAPI api;

	GraphicsAPIWrapper(GraphicsAPI api) : api(api) {}

	void deserialize(std::string input) {
		if (input == "Vulkan")
			api = Vulkan;
		else if (input == "OpenGL")
			api = OpenGL;
		else
			Engine::engine->getLogger()->logMessage(SEVERE, "Invalid GraphicsAPI Selected.");
	}

	std::string serialize() {
		switch (api) {
		case Vulkan:
			return "Vulkan";
		case OpenGL:
			return "OpenGL";
		}
		return "InvalidGraphicsAPI";
	}
};