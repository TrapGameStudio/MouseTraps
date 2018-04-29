#pragma once
#include "Scene.h"
#include "Tile.h"
#include "../util/TilesetManager.h"
#include "game/GameConfig.h"
#include <vector>
#include <string>
#include <map>

class GameLevel :
    public Scene {
public:
    class MapLayer;
private:
    std::map<int, MapLayer*> gameMap;
    unsigned int column;
    unsigned int row;
public:
    GameLevel();
    void addMapLayer(int layerID, MapLayer* gameMapLayer);
    void keyPress(unsigned char key);
    void keyUp(unsigned char key);
    void mouseDown(float x, float y);
    void mouseUp(float x, float y);
    void updateMapGraphics();
    void draw();
    ~GameLevel();
};

class GameLevel::MapLayer {
private:
    GameLevel* gameLevel;
    std::vector<std::string> gameMapLayer;
    std::unordered_map<char, Tile> tileMap;
    unsigned int column = 0;
    unsigned int row = 0;
public:
    MapLayer(GameLevel* gameLevel);
    void mapAddRow(std::string);
    void addCharTileMapping(char, Tile);
    unsigned int getColumn();
    unsigned int getRow();
    void draw();
    ~MapLayer();
};