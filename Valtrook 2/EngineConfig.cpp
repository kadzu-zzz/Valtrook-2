#include "EngineConfig.h"

#include "FileReader.h"
#include "FileWriter.h"
#include <sstream>
#include <string>

EngineConfig::EngineConfig() : graphics_mode("Graphics Mode", Vulkan), default_window_data("Default Window", WindowData())
{
	config_options.add(&graphics_mode);
	config_options.add(&default_window_data);
}

void EngineConfig::Load()
{
	FileReader reader("", "engine.conf");
	if (reader.File.good()) {
		std::string line = "";
		while (std::getline(reader.File, line)) {
			config_options.read(line);
		}
	}
}

void EngineConfig::Save()
{
	FileWriter writer("", "engine.conf");
	if (writer.File.good()) {
		config_options.write(&writer);
	}
}
