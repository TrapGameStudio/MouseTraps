#pragma once
#include "gui/lang/Drawable.h"
#include <deque>
#include <functional>
#include <memory>
class Scene {
protected:
	class Timer;
private:
	std::deque<std::unique_ptr<Scene::Timer>> timers;
public:
	Scene();
	virtual void draw() = 0;
	void addTimers(unsigned int duration, std::function<void(void)> execution, bool repeating = false);
	virtual ~Scene() {};
};

class Scene::Timer {
private:
	bool expired = false;
	bool repeating = false;
	unsigned int duration = 0;
	unsigned int remainingTicks = 0;
	std::function<void(void)> execution;
	void reset();
public:
	Timer(unsigned int duration, std::function<void(void)> execution, bool repeating = false);
	void tick();
	bool isExpired();
};
