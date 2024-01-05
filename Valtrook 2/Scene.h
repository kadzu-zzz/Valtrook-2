#pragma once

#include <vector>
#include <memory>

class Scene
{
protected:
	bool has_update;
	bool has_render;
		
	std::weak_ptr<Scene> self;
	std::weak_ptr<Scene> parent;
	std::vector<std::shared_ptr<Scene>> children;

	virtual void Update() = 0;
	virtual void Render() = 0;

public:
	Scene();
	Scene(bool updates, bool renders);

	void Initialize(std::shared_ptr<Scene> self);

	void Engine_Update();
	void Engine_Render();

	void AddChild(std::shared_ptr<Scene> child);
	std::shared_ptr<Scene> TakeChild(std::shared_ptr<Scene> child);
	void DeleteChild(std::shared_ptr<Scene> child);
	void ClearChildren();
};


