#pragma once

#include <string>
#include <vector>
#include <sstream>
#include "FileWriter.h"

class INamedSerializable {
public:
	virtual void deserialize(std::string input) = 0;
	virtual std::string serialize() = 0;
	virtual bool matches(std::string input) = 0;
};

class NamedSerializableCollection {
protected:
	std::vector<INamedSerializable*> config_options;
public:
	void add(INamedSerializable* config) {
		config_options.push_back(config);
	}
	
	void read(std::string line) {
		std::string start = line.substr(0, line.find_last_of("|"));

		for (auto config : config_options)
			if (config->matches(start))
				config->deserialize(line);
	}

	void write(FileWriter* writer) {
		std::stringstream str;
		for (auto config : config_options)
			writer->File << config->serialize() << std::endl;
	}
};

template<typename T>
class NamedSerializable : public INamedSerializable {
	std::string name;
	T value;
	struct TrueSerialize {
		static T deserialize(std::string in) {
			return T();
		}

		static std::string serialize(T in) {
			return "unsupported type";
		}

		static T default_value() {
			return T();
		}
	};
public:
	NamedSerializable(std::string name, T default_value) : name(name), value(default_value) {}

	void deserialize(std::string input) override {
		value = TrueSerialize::deserialize(static_cast<std::string>(input.substr(input.find_first_of('|') + 1, input.size())));
	}

	std::string serialize() override {
		return name + "|" + TrueSerialize::serialize(value);
	}
	bool matches(std::string input) override {
		return input == name;
	}

	std::string getName() {
		return name;
	}

	T getValue() {
		return value;
	}

	void setValue(T v) {
		value = v;
	}
};


template<>
struct NamedSerializable<std::string>::TrueSerialize {
	static std::string deserialize(std::string input) {	return input; }
	static std::string serialize(std::string input) { return input; }
};
template<>
struct NamedSerializable<int>::TrueSerialize {
	static int deserialize(std::string input) { return std::stoi(input); }
	static std::string serialize(int input) { return std::to_string(input); }
};

