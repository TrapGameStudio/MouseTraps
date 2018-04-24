#include "Tile.h"



Tile::Tile(std::string tilesetName, float x, float y) {
    setTileset(tilesetName);
    setTile(x, y);
}

void Tile::setTileset(std::string tilesetName) {
    this->tilesetName = tilesetName;
}


void Tile::setTile(float x, float y) {
    this->tileCoordinate = Point(x, y);
}

TextureRect * Tile::getTextureRect() {
    TextureRect* newTextureRect = TextureRect::builder()
        .ofTexture(("Graphics/Tilesets/" + tilesetName).c_str())
        .build();
    return newTextureRect;
}


Tile::~Tile() {}
