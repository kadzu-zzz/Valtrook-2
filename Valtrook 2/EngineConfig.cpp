#include "EngineConfig.h"

#include "FileReader.h"
#include "FileWriter.h"
#include <sstream>
#include <string>

EngineConfig::EngineConfig() : graphics_mode("Graphics Mode", GraphicsAPIWrapper(Vulkan))
{
}

void EngineConfig::Load()
{
	FileReader reader("", "engine.conf");
	if (reader.File.good()) {
		std::string start = "";
		std::string line = "";
		while (std::getline(reader.File, line)) {
			start = line.substr(0, line.find_last_of("|"));

			if (graphics_mode.config_name == start) {
				graphics_mode.deserailize(line);
			} 
		}
	}
}

void EngineConfig::Save()
{
	FileWriter writer("", "engine.conf");
	if (writer.File.good()) {
		writer.File << graphics_mode.serialize();
	}
}
