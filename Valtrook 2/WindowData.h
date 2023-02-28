#pragma once

#include <string>
#include "NamedSerializable.h"
#include "StringUtil.h"

struct WindowData {
public:
	int width = 640;
	int height = 480;
	std::string alias = "main";
	std::string title = "main";
	int fullscreen_target = -1;
}; 

template<>
struct NamedSerializable<WindowData>::TrueSerialize {
	static WindowData deserialize(std::string input) {
		std::vector tokens = split(input, ",");

		if (tokens.size() == 4) {
			WindowData data = WindowData();
			data.title = tokens[0];
			data.width = std::stoi(tokens[1]);
			data.height = std::stoi(tokens[2]);
			data.fullscreen_target = std::stoi(tokens[3]);
			return data;
		}
		return WindowData();
	}

	static std::string serialize(WindowData input) {
		return input.title + "," + std::to_string(input.width) + "," + std::to_string(input.height) + "," + std::to_string(input.fullscreen_target);
	}
};