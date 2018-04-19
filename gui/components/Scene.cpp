#include "Scene.h"



Scene::Scene() {}

void Scene::addTimers(unsigned int duration, std::function<void(void)> execution, bool repeating) {
    timers.push_back(std::make_unique<Scene::Timer>(duration, execution, repeating));
}


void Scene::Timer::reset() {
    remainingTicks = duration;
}

Scene::Timer::Timer(unsigned int duration, std::function<void(void)> execution, bool repeating) {
    if (duration) {
        this->remainingTicks = duration;
        this->execution = execution;
    } else {
        expired = true;
    }
}

void Scene::Timer::tick() {
    if (!expired && !--remainingTicks) {
        if (execution) {
            execution();
            if (repeating) {
                reset();
            } else {
                expired = true;
            }
        }
    }
}

bool Scene::Timer::isExpired() {
    return expired;
}
