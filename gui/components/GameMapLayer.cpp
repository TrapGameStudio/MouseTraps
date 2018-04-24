#include "GameMapLayer.h"



GameMapLayer::GameMapLayer(GameLevel* gameLevel) {
    this->gameLevel = gameLevel;
}

void GameMapLayer::mapAddRow(std::string tileChars) {
    gameMap.push_back(tileChars);
    if (tileChars.size() > column) {
        column = tileChars.size();
    }
    row++;
}

void GameMapLayer::addCharTileMapping(char tileChar, Tile tile) {
    tileMap.insert(std::make_pair(tileChar, tile));
}

unsigned int GameMapLayer::getColumn() {
    return column;
}

unsigned int GameMapLayer::getRow() {
    return row;
}

void GameMapLayer::draw() {
    unsigned int currentX = 0;
    unsigned int currentY = 0;
    for (const auto& t : gameMap) {
        for (const char& c : t) {

        }
    }
}


GameMapLayer::~GameMapLayer() {}
