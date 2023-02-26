#pragma once

#include <string>

class IConfigSerializable {
public:
	virtual void deserialize(std::string input) = 0;
	virtual std::string serialize() = 0;
};