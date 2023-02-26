#pragma once

#include <fstream>

class FileReader {
public:
	FileReader(std::string path, std::string name);
	~FileReader();

	std::ifstream File;
};

