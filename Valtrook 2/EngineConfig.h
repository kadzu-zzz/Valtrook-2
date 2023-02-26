#pragma once

#include "Config.h"

#include "ConfigData.h"
#include "GraphicsAPI.h"
#include <map>

class EngineConfig
{
public:
	EngineConfig();

	ConfigData<GraphicsAPIWrapper> graphics_mode;

	void Load();
	void Save();
};

