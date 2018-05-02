#include "GameLevel.h"
#include <stdio.h>


GameLevel::GameLevel() {}

void GameLevel::addMapLayer(int layerID, GameLevel::MapLayer* gameMapLayer) {
    gameMap[layerID] = gameMapLayer;
    if (gameMapLayer->getColumn() > this->column) {
        this->column = gameMapLayer->getColumn();
    }
    if (gameMapLayer->getRow() > this->row) {
        this->row = gameMapLayer->getRow();
    }
    updateMapGraphics();  // TODO: inefficient
}

void GameLevel::setPlayerCharacter(Entity * entity) {}

void GameLevel::keyPress(unsigned char key) {}

void GameLevel::keyUp(unsigned char key) {}

void GameLevel::mouseDown(float x, float y) {}

void GameLevel::mouseUp(float x, float y) {}

void GameLevel::updateMapGraphics() {
    emptyShapes();
    for (const auto& m : gameMap) {
        m.second->draw();
    }
}

void GameLevel::leftArrowDown() {}

void GameLevel::upArrowDown() {}

void GameLevel::rightArrowDown() {}

void GameLevel::downArrownDown() {}

void GameLevel::leftArrowUp() {}

void GameLevel::upArrowUp() {}

void GameLevel::rightArrowUp() {}

void GameLevel::downArrownUp() {}

void GameLevel::draw() {
    Scene::draw();
}


GameLevel::~GameLevel() {}

GameLevel::MapLayer::MapLayer(GameLevel* gameLevel) {
    this->gameLevel = gameLevel;
}

void GameLevel::MapLayer::mapAddRow(std::string tileChars) {
    gameMapLayer.push_back(tileChars);
    if (tileChars.size() > column) {
        column = tileChars.size();
    }
    row++;
}

void GameLevel::MapLayer::addCharTileMapping(char tileChar, Tile tile) {
    tileMap[tileChar] = tile;
}

unsigned int GameLevel::MapLayer::getColumn() {
    return column;
}

unsigned int GameLevel::MapLayer::getRow() {
    return row;
}

/// <summary>
/// This method doesn't actually do the drawing; 
/// it only push the shape to sceen and let sceen handle the rest.
/// </summary>
void GameLevel::MapLayer::draw() {

    unsigned int currentX = 0;
    unsigned int currentY = 0;
    for (const auto& t : gameMapLayer) {
        currentX = 0;
        for (const char& c : t) {
            TextureRect* tr = TilesetManager::getTextureRect(tileMap[c]);
            tr->setAnchorLocation(currentX * (2.0f / GameConfig::gridColumn) - 1.0f,
                                  currentY * (-2.0f / GameConfig::gridColumn) + 1.0f);
            gameLevel->pushShapeToBack(tr);
            currentX++;
        }
        currentY++;
    }
}

GameLevel::MapLayer::~MapLayer() {}
