#pragma once
#include <string>
#include <unordered_map>
#include "Tile.h"
#include "../lang/Drawable.h"
class GameLevel;

class GameMapLayer :
    public Drawable {
private:
    std::vector<std::string> gameMap;
    std::unordered_map<char, Tile> tileMap;
    GameLevel* gameLevel;
    unsigned int column = 0;
    unsigned int row = 0;
public:
    GameMapLayer(GameLevel* gameLevel);
    void mapAddRow(std::string);
    void addCharTileMapping(char, Tile);
    unsigned int getColumn();
    unsigned int getRow();
    void draw();
    ~GameMapLayer();
};

