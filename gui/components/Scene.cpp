#include "Scene.h"



Scene::Scene() {}

void Scene::draw() {
    for (Drawable* d : allShapes) {
        d->draw();
    }
}

void Scene::pushShapeToFront(Drawable * shape) {
    allShapes.push_front(shape);
}

void Scene::pushShapeToBack(Drawable * shape) {
    allShapes.push_back(shape);
}

void Scene::pushClickableToFront(Clickable * clickable) {
    allClickables.push_front(clickable);
}

void Scene::pushClickableToBack(Clickable * clickable) {
    allClickables.push_back(clickable);
}

void Scene::pushAnimatedShapesToFront(TextureRect * shape) {
    allAnimatedShapes.push_front(shape);
}

void Scene::pushAnimatedShapesToBack(TextureRect * shape) {
    allAnimatedShapes.push_back(shape);
}

void Scene::clickClickables() {
    for (Clickable* c : allClickables) {
        c->clickMouseDown();
    }
}

void Scene::tick() {
    for (TextureRect* a : allAnimatedShapes) {
        a->advance();
    }
    for (Scene::Timer* t : timers) {
        if (t) { // use other data structure so I can delete the timer.
            if (!t->isExpired()) {
                t->tick();
            } else {
                delete t;
            }
        }
    }
}

void Scene::addTimers(unsigned int duration, std::function<void(void)> execution, bool repeating) {
    timers.push_back(new Scene::Timer(duration, execution, repeating));
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
