#pragma once

#include <array>

class Texture
{
	virtual unsigned int texture() = 0;
	virtual unsigned int Width() = 0;
	virtual unsigned int Height() = 0;
	virtual std::array<unsigned int, 2> TextureSize() = 0;
};

