#include "Scene.h"



Scene::Scene() {}

void Scene::draw() {
    for (Drawable* d : allShapes) {
        d->draw();
    }
}

/// <summary>
/// Add a shape to the front of the scene.
/// </summary>
/// <param name="shape">the shape to add</param>
void Scene::pushShapeToFront(Drawable * shape) {
    allShapes.push_front(shape);
}

/// <summary>
/// Add a shape to the back of the scene.
/// </summary>
/// <param name="shape">the shape to add</param>
void Scene::pushShapeToBack(Drawable * shape) {
    allShapes.push_back(shape);
}

/// <summary>
/// Clear all drawalbe objects from the scene.
/// </summary>
void Scene::emptyShapes() {
    allShapes.clear();
}

/// <summary>
/// Register a clickable object to listen for mouse related events
/// and (not implemented yet) add the shape to the front of the scene.
/// </summary>
/// <param name="clickable">the clickable object to add</param>
void Scene::pushClickableToFront(Clickable * clickable) {
    allClickables.push_front(clickable);
}

/// <summary>
/// Register a clickable object to listen for mouse related events
/// and (not implemented yet) add the shape to the back of the scene.
/// </summary>
/// <param name="clickable">the clickable object to add</param>
void Scene::pushClickableToBack(Clickable * clickable) {
    allClickables.push_back(clickable);
}

/// <summary>
/// Register a animated ojbect to listen for frame advancing event
/// and (not implemented yet) add the shape to the front of the scene.
/// </summary>
/// <param name="shape">the animated object to add</param>
void Scene::pushAnimatedShapesToFront(Animatable * shape) {
    allAnimatedShapes.push_front(shape);
}

/// <summary>
/// Register a animated ojbect to listen for frame advancing event
/// and (not implemented yet) add the shape to the back of the scene.
/// </summary>
/// <param name="shape">the animated object to add</param>
void Scene::pushAnimatedShapesToBack(Animatable * shape) {
    allAnimatedShapes.push_back(shape);
}

// TODO: should only click on the top object
/// <summary>
/// Click all clickable object that is in the range of the mouse click.
/// </summary>
/// <param name="x">x window coordinate of the mouse click</param>
/// <param name="y">y window coordinate of the mouse click</param>
void Scene::clickClickables(float x, float y) {
    for (Clickable* c : allClickables) {
        if (c->contains(x, y)) {
            c->clickMouseDown();
        }
    }
}

/// <summary>
/// Call by <see cref="Game#updateFrame" /> to update animations and update
/// the tick based timer.
/// </summary>
void Scene::tick() {
    for (Animatable* a : allAnimatedShapes) {
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

void Scene::addTimers(unsigned int duration, std::function<void(void)> executable, bool repeating) {
    timers.push_back(new Scene::Timer(duration, executable, repeating));
}


void Scene::Timer::reset() {
    remainingTicks = duration;
}


Scene::Timer::Timer(unsigned int duration, std::function<void(void)> executable, bool repeating) {
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
