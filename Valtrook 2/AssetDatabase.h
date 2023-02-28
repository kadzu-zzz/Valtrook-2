#pragma once

#include "EngineConfig.h"

class AssetDatabase
{
public:
	EngineConfig config;

	void EarlyLoad();

	void Save();
};

