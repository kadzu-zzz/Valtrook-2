#pragma once

class Material;

template<typename GlyphType>
struct RenderData {
public:
	std::vector<GlyphType> glyphs;
	Material* material;
};