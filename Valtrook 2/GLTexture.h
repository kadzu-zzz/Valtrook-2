#pragma once

#include "Texture.h"

class GLTexture : public Texture
{
public:
	GLTexture(unsigned int texture, unsigned int width, unsigned int height);

	virtual unsigned int TextureID() override;
	virtual unsigned int Width() override;
	virtual unsigned int Height() override;
	virtual std::array<unsigned int, 2> TextureSize() override;
protected:
	unsigned int id;
	std::array<unsigned int, 2> size;
};

