#pragma once

#include "GraphicsAPI.h"

template<typename T, T>
class GraphicsAPIBootstrap {
	struct Bootstrap {
		static void init() {

		}

		static void cleanup() {

		}
	}
};

template<>
struct GraphicsAPIBootstrap<GraphicsAPI, Vulkan>::Bootstrap {
	static void init() {
		glfwInit();
	}

	static void cleanup() {
		glfwCleanup();
	}
};