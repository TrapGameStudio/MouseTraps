#include "Game.h"

const int Game::GridColumn = 40;
const int Game::GridRow = 30;

void Game::gridCoordinatesToWindowCoordinates(float & x, float & y) {}

void Game::gridCoordinatesToWindowCoordinates(Point * p) {}

void Game::gridCoordinatesToWindowCoordinates(Vector * v) {}

void Game::mouseDown(float x, float y) {
    for (unsigned int i = 0; i < currentScenes.size(); i++) {
        currentScenes[i]->clickClickables(x, y);
    }
}

void Game::mouseUp(float x, float y) {}

void Game::keyUp(unsigned char key) {}

void Game::keyPress(unsigned char key) {}

void Game::redraw() {
    for (unsigned int i = 0; i < currentScenes.size(); i++) {
        currentScenes[i]->draw();
    }
}

void Game::updateFrame() {
    for (unsigned int i = 0; i < currentScenes.size(); i++) {
        currentScenes[i]->tick();
        currentScenes[i]->draw();
    }
}

Game::Game() {
    currentScenes.push_back(std::make_unique<Map02>());
}

Game::~Game() {}
