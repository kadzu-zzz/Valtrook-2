#include "RenderingEngine.h"


RenderingEngine::RenderingEngine() : bInitialized(false)
{
}

void RenderingEngine::Initialize(GraphicsAPI api)
{
	if (bInitialized) {
		Stop();
	}

	switch (api) {

	}
	bInitialized = true;
}

void RenderingEngine::Stop()
{
	bInitialized = false;
}

bool RenderingEngine::IsReady()
{
	return bInitialized;
}

void RenderingEngine::Render(RenderData&& data)
{
}

void RenderingEngine::Render(RenderData* data, int length)
{
}

void RenderingEngine::Display()
{
}
