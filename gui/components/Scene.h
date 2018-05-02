#pragma once
#include "../lang/Drawable.h"
#include "../lang/Clickable.h"
#include "../lang/Animatable.h"
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
    std::deque<Animatable*> allAnimatedShapes;
    std::deque<Scene::Timer*> timers;
public:
    Scene();
    /// <summary>
    /// This function will be called by <see cref="Game" /> object when a key is pressed.
    /// Useful for handling key control objects in the scene.
    /// </summary>
    /// <param name="key">the ASCII value of the pressed key</param>
    virtual void keyPress(unsigned char key) = 0;

    /// <summary>
    /// This function will be called by <see cref="Game" /> object
    /// when a pressed key is released.
    /// Useful for handling key control objects in the scene.
    /// </summary>
    /// <param name="key">the ASCII value of the released key</param>
    virtual void keyUp(unsigned char key) = 0;

    /// <summary>
    /// This function will be called by <see cref="Game" /> object
    /// when the left mouse button is clicked.
    /// <seealso cref="clickClickables" />
    /// </summary>
    /// <param name="x">the x window coordinate when the mouse was clicked</param>
    /// <param name="y">the y window coordinate when the mouse was clicked</param>
    virtual void mouseDown(float x, float y) = 0;

    /// <summary>
    /// This function will be called by <see cref="Game" /> object
    /// when the clicked left mouse button is released.
    /// </summary>
    /// <param name="x">the x window coordinate when the mouse was released</param>
    /// <param name="y">the y window coordinate when the mouse was released</param>
    virtual void mouseUp(float x, float y) = 0;

    virtual void leftArrowDown() = 0;
    virtual void upArrowDown() = 0;
    virtual void rightArrowDown() = 0;
    virtual void downArrownDown() = 0;

    virtual void leftArrowUp() = 0;
    virtual void upArrowUp() = 0;
    virtual void rightArrowUp() = 0;
    virtual void downArrownUp() = 0;


    virtual void draw();

    void pushShapeToFront(Drawable* shape);
    void pushShapeToBack(Drawable* shape);
    void emptyShapes();
    // TODO: auto push to all shapes
    void pushClickableToFront(Clickable* clickable);
    void pushClickableToBack(Clickable* clickable);
    void pushAnimatedShapesToFront(Animatable* shape);
    void pushAnimatedShapesToBack(Animatable* shape);
    // TODO: change to mouse down mouse up latter.
    void clickClickables(float x, float y);
    void tick();
    void addTimers(unsigned int duration, std::function<void(void)> executable, bool repeating = false);
    virtual ~Scene() {};
};

/// <summary>
/// A tick based timer (instead of time base).
/// If the updateFrame from App.cpp got slower, this will also get slower.
/// </summary>
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
