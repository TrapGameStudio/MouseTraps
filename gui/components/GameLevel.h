#pragma once
#include "Scene.h"
#include "Tile.h"
#include "../util/TilesetManager.h"
#include "util/MiceGenerator.h"
#include "game/components/Entity.h"
#include "game/GameConfig.h"
#include <vector>
#include <string>
#include <map>
class MiceGenerator;

class GameLevel :
    public Scene {
public:
	MiceGenerator* generator;
    class MapLayer;
private:
    std::map<int, MapLayer*> gameMap;
    Entity * player;
    Direction playerDirection = Direction::Resting;
    unsigned int column;
    unsigned int row;
public:
    GameLevel();
    void addMapLayer(int layerID, MapLayer* gameMapLayer);
    void setPlayerCharacter(Entity* entity);
	void setMiceGenerator(GameLevel*);
    void keyPress(unsigned char key);
    void keyUp(unsigned char key);
    void mouseDown(float x, float y);
    void mouseUp(float x, float y);
    void updateMapGraphics();

    void leftArrowDown();
    void upArrowDown();
    void rightArrowDown();
    void downArrownDown();

    void leftArrowUp();
    void upArrowUp();
    void rightArrowUp();
    void downArrownUp();

    bool isPassable(float x, float y);

    bool collideLeft(Entity* e);
    bool collideUp(Entity* e);
    bool collideRight(Entity* e);
    bool collideDown(Entity* e);

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
    char getTile(unsigned int x, unsigned int y);
    void draw();
    ~MapLayer();
};