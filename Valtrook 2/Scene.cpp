#include "Scene.h"

Scene::Scene() : has_update(false), has_render(false)
{
}

Scene::Scene(bool updates, bool renders) : has_update(updates), has_render(renders)
{
}

void Scene::Initialize(std::shared_ptr<Scene> self)
{
	this->self = self;
}

void Scene::Engine_Update()
{
	if (has_update)
		Update();

	for (auto forward_iter = children.begin(); forward_iter != children.end(); forward_iter++) {
		(*forward_iter)->Engine_Update();
	}
}

void Scene::Engine_Render()
{
	if (has_render)
		Render();

	for (auto forward_iter = children.begin(); forward_iter != children.end(); forward_iter++) {
		(*forward_iter)->Engine_Render();
	}
}

void Scene::AddChild(std::shared_ptr<Scene> child)
{
	if (child->parent.lock().get() != this) {
		children.push_back(child->parent.lock()->TakeChild(child));
	}
	else {
		children.push_back(child);
	}
	child->parent = self;
}

std::shared_ptr<Scene> Scene::TakeChild(std::shared_ptr<Scene> child)
{
	for (auto forward_iter = children.begin(); forward_iter != children.end(); forward_iter++) {
		if (*forward_iter == child) {
			children.erase(forward_iter);
		}
	}
	return child;
}

void Scene::DeleteChild(std::shared_ptr<Scene> child) {
	for (auto forward_iter = children.begin(); forward_iter != children.end(); forward_iter++) {
		if (*forward_iter == child) {
			(*forward_iter)->ClearChildren();
			children.erase(forward_iter);
		}
	}
}

void Scene::ClearChildren()
{
	for (auto forward_iter = children.begin(); forward_iter != children.end(); forward_iter++) {
		(*forward_iter)->ClearChildren();
	}
	children.clear();
}
