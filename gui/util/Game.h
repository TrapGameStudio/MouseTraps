#pragma once
#include "../geom/Vector.h"
#include "../geom/Point.h"
#include "../components/Scene.h"
#include "../util/ScenePrototype.h"
#include "../../test/DemoSceen.h"
#include "../../game/levels/DemoLevel.h"
#include "../../game/levels/Map02.h"
#include "../../game/levels/Map01.h"
#include <memory>
#include <deque>
#include <map>
class Game {
private:
    // TODO: use map
    std::deque<std::unique_ptr<Scene>> currentScenes;
    std::map<unsigned int, std::unique_ptr<ScenePrototype>> gameLevels;
public:
    static const int GridColumn;
    static const int GridRow;
    static void gridCoordinatesToWindowCoordinates(float& x, float& y);
    static void gridCoordinatesToWindowCoordinates(Point* p);
    static void gridCoordinatesToWindowCoordinates(Vector* v);

    void mouseDown(float x, float y);
    void mouseUp(float x, float y);
    void keyUp(unsigned char key);
    void keyPress(unsigned char key);

    void leftArrowDown();
    void upArrowDown();
    void rightArrowDown();
    void downArrownDown();

    void leftArrowUp();
    void upArrowUp();
    void rightArrowUp();
    void downArrownUp();

    void redraw();

    void updateFrame();


    Game();
    ~Game();
};

