#pragma once

#include <fstream>

class FileWriter {
public:
	FileWriter(std::string path, std::string name);
	~FileWriter();

	std::ofstream File;
};

