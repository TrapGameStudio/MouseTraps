#pragma once
#include <functional>
class Clickable {

public:
    virtual void entered() = 0;
    virtual void onEnter(std::function<void(void)> onEnterFunction) = 0;
    virtual void left() = 0;
    virtual void onLeave(std::function<void(void)> onLeaveFunction) = 0;
    virtual void clickMouseDown() = 0;
    virtual void onClickMouseDown(std::function<void(void)> onClickMouseDownFunction) = 0;
    virtual void clickMouseUp() = 0;
    virtual void onClickMouseUp(std::function<void(void)> onClickMouseUpFunction) = 0;
    virtual bool contains(float x, float y) const = 0;
    virtual ~Clickable() {};
};

