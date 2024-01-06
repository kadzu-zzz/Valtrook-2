#include "Colour.h"

Colour::Colour() : Colour(255, 255, 255, 255)
{
}

Colour::Colour(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : r(r), g(g), b(b), a(a)
{
}
