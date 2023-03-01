#pragma once

#include "NamedSerializable.h"

enum GraphicsAPI {
	Vulkan,
	OpenGL
};

template<>
struct NamedSerializable<GraphicsAPI>::TrueSerialize {
	static GraphicsAPI deserialize(std::string input) {
		if (input == "Vulkan")
			return GraphicsAPI::Vulkan;
		else if (input == "OpenGL")
			return GraphicsAPI::OpenGL;
		return GraphicsAPI::OpenGL;
	}

	static std::string serialize(GraphicsAPI input) {
		switch (input) {
		case Vulkan:
			return "Vulkan";
		case OpenGL:
			return "OpenGL";
		}
		return "InvalidGraphicsAPI";
	}
};