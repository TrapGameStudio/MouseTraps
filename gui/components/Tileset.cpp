#include "Tileset.h"


Tileset::Tileset(std::string tilesetFileName, unsigned int column, unsigned int row, TilesetType tilesetType) {
    this->tilesetFileName = tilesetFileName;
    textureID = TextureManager::getTextureID(("Graphics/Tilesets/" + tilesetFileName).c_str());
    this->column = column;
    this->row = row;
}

Tile * Tileset::getTile(unsigned int x, unsigned int y) {
    return new Tile(tilesetFileName, x, y);
}

unsigned int Tileset::getColumn() const {
    return column;
}

unsigned int Tileset::getRow() const {
    return row;
}


Tileset::~Tileset() {}
