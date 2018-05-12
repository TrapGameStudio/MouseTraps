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

void Game::keyPress(unsigned char key) {
    for (auto&& sc : currentScenes) {
        sc->keyPress(key);
    }
    if (key == '0') {
        currentScenes.clear();
        currentScenes.push_back(std::make_unique<Map01>());
    }
    if (key == '-') {
        currentScenes.clear();
        currentScenes.push_back(std::make_unique<Map02>());
    }
    if (key == '=') {
        currentScenes.clear();
        currentScenes.push_back(std::make_unique<Map03>());
    }
}

void Game::leftArrowDown() {
    for (auto&& sc : currentScenes) {
        sc->leftArrowDown();
    }
}

void Game::upArrowDown() {
    for (auto&& sc : currentScenes) {
        sc->upArrowDown();
    }
}

void Game::rightArrowDown() {
    for (auto&& sc : currentScenes) {
        sc->rightArrowDown();
    }
}

void Game::downArrownDown() {
    for (auto&& sc : currentScenes) {
        sc->downArrownDown();
    }
}

void Game::leftArrowUp() {
    for (auto&& sc : currentScenes) {
        sc->leftArrowUp();
    }
}

void Game::upArrowUp() {
    for (auto&& sc : currentScenes) {
        sc->upArrowUp();
    }
}

void Game::rightArrowUp() {
    for (auto&& sc : currentScenes) {
        sc->rightArrowUp();
    }
}

void Game::downArrownUp() {
    for (auto&& sc : currentScenes) {
        sc->downArrownUp();
    }
}

Scene* Game::grabScene(int scene) {
	int i = 0;
	for (auto&& sc : currentScenes) {
		if (i = scene)
			return currentScenes[i].get();
	}
	return nullptr;
}

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

Game::GameState::GameState() {

}

void Game::GameState::loadGameState() {

}

void Game::GameState::saveGameState() {

}

Game::GameState::PlayerState::PlayerState(Entity* player) {
	this->playerLocation = player->getLocation();
	this->playerDirection = player->getDirection();
	
}

void Game::GameState::PlayerState::loadPlayerState() {

}

void Game::GameState::PlayerState::savePlayerState() {

}

Game::GameState::MiceState::MiceState() {

}

void Game::GameState::MiceState::loadMiceState() {

}

void Game::GameState::MiceState::saveMiceState() {

}