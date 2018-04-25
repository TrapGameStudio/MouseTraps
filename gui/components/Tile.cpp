#include "Tile.h"



Tile::Tile(std::string tilesetName, float x, float y) {
    setTileset(tilesetName);
    setTile(x, y);
}

std::string Tile::getTilesetName() const {
    return tilesetName;
}

const Point & Tile::getTileCoordinate() const {
    return tileCoordinate;
}

unsigned int Tile::getTileX() const {
    return tileCoordinate.getX();
}

unsigned int Tile::getTileY() const {
    return tileCoordinate.getY();
}

void Tile::setTileset(std::string tilesetName) {
    this->tilesetName = tilesetName;
}


void Tile::setTile(float x, float y) {
    this->tileCoordinate = Point(x, y);
}


Tile::~Tile() {}
