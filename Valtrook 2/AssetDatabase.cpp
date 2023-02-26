#include "AssetDatabase.h"

void AssetDatabase::EarlyLoad()
{
	config.Load();
}

void AssetDatabase::Save()
{
	config.Save();
}