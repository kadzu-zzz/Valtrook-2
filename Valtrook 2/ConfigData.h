#pragma once

#include "IConfigSerializable.h"

#include <string>
#include <string_view>

template<typename T >
class ConfigData
{
	static_assert(std::is_base_of<IConfigSerializable, T>::value, "T must inherit from IConfigSerializable");
public:
	ConfigData(std::string config_name, T default_data) : config_name(config_name), data(default_data) {}

	const std::string config_name;
	T data;

	std::string serialize() {
		return config_name + "|" + data.serialize();
	}

	void deserailize(std::string TIn) {
		data.deserialize(TIn.substr(TIn.find_first_of('|') + 1, TIn.size()));
	}
};

