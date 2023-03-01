#pragma once

#include "NamedSerializable.h"
#include "GraphicsAPI.h"
#include "WindowData.h"
#include <unordered_map>
#include <vector>

struct WindowData;

class EngineConfig
{
private:
	NamedSerializableCollection config_options;
public:
	EngineConfig();

	NamedSerializable<GraphicsAPI> graphics_mode;
	NamedSerializable<int> gl_major_version;
	NamedSerializable<int> gl_minor_version;

	NamedSerializable<WindowData> default_window_data;

	void Load();
	void Save();
};

