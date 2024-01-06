#include "GLTexture.h"

GLTexture::GLTexture(unsigned int texture, unsigned int width, unsigned int height) : id(texture), size({width, height})
{
}

unsigned int GLTexture::TextureID()
{
    return id;
}

unsigned int GLTexture::Width()
{
    return size[0];
}

unsigned int GLTexture::Height()
{
    return size[1];
}

std::array<unsigned int, 2> GLTexture::TextureSize()
{
    return size;
}
