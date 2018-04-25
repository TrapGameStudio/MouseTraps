#pragma once
#include "../lang/Drawable.h"
#include "../lang/Clickable.h"
#include "../components/TextureRect.h"
#include <deque>
#include <functional>
#include <memory>
class Scene {
protected:
    class Timer;
private:
    // TODO: use map to check duplicates
    std::deque<Drawable*> allShapes;
    std::deque<Clickable*> allClickables;
    // TODO: make specialized list for animated objects.
    std::deque<TextureRect*> allAnimatedShapes;
    std::deque<Scene::Timer* > timers;
public:
    Scene();
    virtual void keyPress(unsigned char key) = 0;
    virtual void keyUp(unsigned char key) = 0;
    virtual void mouseDown(float x, float y) = 0;
    virtual void mouseUp(float x, float y) = 0;
    virtual void draw();
    void pushShapeToFront(Drawable* shape);
    void pushShapeToBack(Drawable* shape);
    void emptyShapes();
    // TODO: auto push to all shapes
    void pushClickableToFront(Clickable* clickable);
    void pushClickableToBack(Clickable* clickable);
    void pushAnimatedShapesToFront(TextureRect* shape);
    void pushAnimatedShapesToBack(TextureRect* shape);
    // TODO: change to mouse down mouse up latter.
    void clickClickables(float x, float y);
    void tick();
    void addTimers(unsigned int duration, std::function<void(void)> executable, bool repeating = false);
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
    Timer(unsigned int duration, std::function<void(void)> executable, bool repeating = false);
    void tick();
    bool isExpired();
};
