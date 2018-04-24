#pragma once
#include "Scene.h"
#include <vector>
#include <string>
#include <map>
#include "GameMapLayer.h"
class GameLevel :
    public Scene {
private:
    std::map<int, GameMapLayer> gameMap;
    unsigned int column;
    unsigned int row;
public:
    GameLevel();
    void addMapLayer(int layerID, GameMapLayer gameMapLayer);
    void keyPress(unsigned char key);
    void keyUp(unsigned char key);
    void mouseDown(float x, float y);
    void mouseUp(float x, float y);
    void draw();
    ~GameLevel();
};

