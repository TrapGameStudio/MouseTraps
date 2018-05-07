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

void GameLevel::setPlayerCharacter(Entity * entity) {
	player = entity;  // TODO: fix memory leak
    allEntities.push_back(entity);
}

void GameLevel::keyPress(unsigned char key) {
    if (key == ' ') {

        // make a bomb
        TextureRect* bomb = TextureRect::builder()
            .ofTexture("Graphics/Tilesets/SF_Inside_B.png")
            .ofColumnRow(16, 16)
            .ofCurrentColumnRow(15, 0)
            .atLocation(player->getLocation())
            .onAnchor(Anchor::Bottom)
            .ofSize(2.0f / GameConfig::gridColumn, 2.0f / GameConfig::gridRow)
            .build();

        removeShape(player);    // remove and readd player to make the player on top of the bomb
        pushShapeToBack(bomb);
        pushShapeToBack(player);

        // bomb exploding in 100 ticks. when explode, remove the bomb, 
        // create a new Animated Texture Rectangle for the explosion,
        // and after explosion, remove explosion texture rectangle.
        addTimer(100, [this, bomb]() {
            TextureRect* explosion = TextureRect::builder()
                .ofTexture("Graphics/Animations/Fire2.png")
                .ofColumnRow(7, 1)
                .ofTextureType(TextureType::Animation)
                .ofSize(6.0f / GameConfig::gridColumn, 6.0f / GameConfig::gridRow)
                .atLocation(bomb->getAnchorLocation())
                .onAnchor(Anchor::Bottom)
                .build();

            // actual logic of the explosion
            explode(bomb->getAnchorLocation()->getX(), bomb->getAnchorLocation()->getY());

            pushShapeToBack(explosion);
            pushAnimatedShapesToBack(explosion);
            removeShape(bomb);

            addTimer(10, [this, explosion]() {
                removeShape(explosion);
            });
        });
    }
}

void GameLevel::keyUp(unsigned char key) {}

void GameLevel::mouseDown(float x, float y) {}

void GameLevel::mouseUp(float x, float y) {}

void GameLevel::updateMapGraphics() {
    emptyShapes();
    for (const auto& m : gameMap) {
        m.second->draw();
    }
}

void GameLevel::leftArrowDown(){
    isPassable(player->getLocation()->getX(), player->getLocation()->getY());
    playerDirection = Direction::MoveLeft;
}

void GameLevel::upArrowDown(){
    playerDirection = Direction::MoveUp;
}

void GameLevel::rightArrowDown(){
    playerDirection = Direction::MoveRight;
}

void GameLevel::downArrownDown(){
	playerDirection = Direction::MoveDown;
}

void GameLevel::leftArrowUp() {
    playerDirection = Direction::Resting;
}

void GameLevel::upArrowUp() {
    playerDirection = Direction::Resting;
}

void GameLevel::rightArrowUp() {
    playerDirection = Direction::Resting;
}

void GameLevel::downArrownUp() {
    playerDirection = Direction::Resting;
}

bool GameLevel::isPassable(float x, float y) {
    int tileX = GameConfig::gridColumn * (x + 1) / 2;
    int tileY = -GameConfig::gridRow  * (y - 1) / 2;

    if (tileX < 0 || tileX >= GameConfig::gridColumn || tileY < 0 || tileY >= GameConfig::gridRow) {
        return false;
    }

    for (auto& ml : gameMap) {
        //printf("%u, %u: %c\n", tileX, tileY, ml.second->getTile(tileX, tileY));
        if (ml.first > -1 && ml.first <= 10) {
            if (ml.second->getTile(tileX, tileY) != ' ') {
                return false;
            }
        } else if (ml.first > 10) {
            return true;
        }
    }

    return true;
}

bool GameLevel::collideLeft(Entity * e) {
    return !isPassable(e->getLocation()->getX() - e->getSpeed() - 2.0f / GameConfig::gridColumn * 0.45f,
                      e->getLocation()->getY())
        || !isPassable(e->getLocation()->getX() - e->getSpeed() - 2.0f / GameConfig::gridColumn * 0.45f,
                       e->getLocation()->getY() + 2.0f / GameConfig::gridRow * 0.5f);
}

bool GameLevel::collideUp(Entity * e) {
    return !isPassable(e->getLocation()->getX() - 2.0f / GameConfig::gridColumn * 0.45f,
                      e->getLocation()->getY() + e->getSpeed() + 2.0f / GameConfig::gridRow * 0.5f)
        || !isPassable(e->getLocation()->getX() + 2.0f / GameConfig::gridColumn * 0.45f,
                       e->getLocation()->getY() + e->getSpeed() + 2.0f / GameConfig::gridRow * 0.5f);
}

bool GameLevel::collideRight(Entity * e) {
    return !isPassable(e->getLocation()->getX() + e->getSpeed() + 2.0f / GameConfig::gridColumn * 0.45f,
                      e->getLocation()->getY())
        || !isPassable(e->getLocation()->getX() + e->getSpeed() + 2.0f / GameConfig::gridColumn * 0.45f,
                       e->getLocation()->getY() + 2.0f / GameConfig::gridRow * 0.5f);
}

bool GameLevel::collideDown(Entity * e) {
    return !isPassable(e->getLocation()->getX() - 2.0f / GameConfig::gridColumn * 0.45f,
                      e->getLocation()->getY() - e->getSpeed())
        || !isPassable(e->getLocation()->getX() + 2.0f / GameConfig::gridColumn * 0.45f,
                       e->getLocation()->getY() - e->getSpeed());
}

void GameLevel::addEntity(Entity * e) {
    allEntities.push_back(e);
}

void GameLevel::removeEntity(Entity * e) {
    allEntities.remove(e);
}

void GameLevel::explode(float x, float y) {
    for (auto& ep : allEntities.getMap()) {
        Entity* e = ep.second;
        float dx = e->getLocation()->getX() - x;
        float dy = e->getLocation()->getY() - y;
        float thresholdRaduisSquared = (6.0f / GameConfig::gridColumn) * (6.0f / GameConfig::gridColumn);
        if (dx * dx + dy + dy < thresholdRaduisSquared) {
            e->kill();
        }
    }
}

/// <summary>
/// This is the only function in GameLevel that is linked to the <see cref="App#refreshDisplay"/>,
/// so it also act as a refresh function for this class.
/// Put anything that need to update every tick in here.
/// </summary>
void GameLevel::draw() {
    if (player) {
        switch (playerDirection) {
        case Direction::MoveDown:
            if (!collideDown(player)) {
                player->move(Direction::MoveDown);
            } else {
                player->turn(Direction::MoveDown);
                player->rest();
            }
            break;
        case Direction::MoveLeft:
            if (!collideLeft(player)) {
                player->move(Direction::MoveLeft);
            } else {
                player->turn(Direction::MoveLeft);
                player->rest();
            }
            break;
        case Direction::MoveRight:
            if (!collideRight(player)) {
                player->move(Direction::MoveRight);
            } else {
                player->turn(Direction::MoveRight);
                player->rest();
            }
            break;
        case Direction::MoveUp:
            if (!collideUp(player)) {
                player->move(Direction::MoveUp);
            } else {
                player->turn(Direction::MoveUp);
                player->rest();
            }
            break;
        case Direction::Resting:
            player->rest();
        }
    }
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

char GameLevel::MapLayer::getTile(unsigned int x, unsigned int y) {
    return gameMapLayer[y][x];
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
