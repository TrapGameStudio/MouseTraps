#include "GameLevel.h"



GameLevel::GameLevel() {}

void GameLevel::addMapLayer(int layerID, GameMapLayer gameMapLayer) {
    gameMap.insert(std::make_pair(layerID, gameMapLayer));
    if (gameMapLayer.getColumn() > this->column) {
        this->column = gameMapLayer.getColumn();
    }
    if (gameMapLayer.getRow() > this->row) {
        this->row = gameMapLayer.getRow();
    }
}

void GameLevel::keyPress(unsigned char key) {}

void GameLevel::keyUp(unsigned char key) {}

void GameLevel::mouseDown(float x, float y) {}

void GameLevel::mouseUp(float x, float y) {}

void GameLevel::draw() {
    for (const auto& m : gameMap) {

    }
}


GameLevel::~GameLevel() {}
