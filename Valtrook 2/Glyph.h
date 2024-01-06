#pragma once

#include "Vertex.h"
#include <array>

class Texture;

template<unsigned int Vertexes>
struct Glyph {
	Glyph(Texture* text, std::array<Vertex, Vertexes> verts) : texture(text), vertexes(verts) {};

	Texture* texture;
	std::array<Vertex, Vertexes> vertexes;
};

struct TriangleGlyph : public Glyph<3> {
	TriangleGlyph(Texture* text, std::array<Vertex, 3> verts) : Glyph(text, verts) {};
};

struct RectangleGlyph : public Glyph<6> {
	RectangleGlyph(Texture* text, std::array<Vertex, 4> verts) : Glyph(text, { verts[0], verts[1], verts[2], verts[2], verts[3], verts[1] }) {};
	RectangleGlyph(Texture* text, std::array<Vertex, 6> verts) : Glyph(text, verts) {};

	std::array<TriangleGlyph, 2> dispose() {
		return std::array<TriangleGlyph, 2>({ TriangleGlyph(texture, std::array<Vertex, 3>({ vertexes[0], vertexes[1], vertexes[2] })),
												TriangleGlyph(texture, std::array<Vertex, 3>({ vertexes[3], vertexes[4], vertexes[5] })) });
	}
};

struct LineGlyph : public Glyph<2> {
	LineGlyph(Texture* text, std::array<Vertex, 2> verts) : Glyph(text, verts) {};
};
