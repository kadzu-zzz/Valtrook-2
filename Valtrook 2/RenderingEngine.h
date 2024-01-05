#pragma once

#include "GraphicsAPI.h"
#include "RenderData.h"

class RenderingEngine
{
private:
	bool bInitialized;

public:
	RenderingEngine();

	void Initialize(GraphicsAPI api);
	void Stop();
	bool IsReady();
	
	void Render(RenderData&& data);
	void Render(RenderData* data, int length);

	void Display();
};

