#pragma once
#include "gui/components/Scene.h"
#include <memory>
class ScenePrototype {
public:
	virtual std::unique_ptr<Scene> instantiate() = 0;
	virtual ~ScenePrototype() {}
};

