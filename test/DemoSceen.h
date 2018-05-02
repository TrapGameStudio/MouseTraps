#pragma once
#include "../gui/components/Scene.h"
#include "../gui/components/Button.h"
#include "../game/components/Entity.h"
class DemoSceen :
    public Scene {
private:
    //Button<TextureRect>* mushroom;
public:
    void keyPress(unsigned char key);
    void keyUp(unsigned char key);
    void mouseDown(float x, float y);
    void mouseUp(float x, float y);

    void leftArrowDown();
    void upArrowDown();
    void rightArrowDown();
    void downArrownDown();

    void leftArrowUp();
    void upArrowUp();
    void rightArrowUp();
    void downArrownUp();
    DemoSceen();
    ~DemoSceen();
};

