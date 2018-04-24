#include "Tileset.h"


Tileset::Tileset(std::string tilesetFileName, unsigned int column, unsigned int row, TilesetType tilesetType) {
    this->tilesetFileName = tilesetFileName;
    textureID = TextureManager::getTextureID(("Graphics/Tilesets/" + tilesetFileName).c_str());
}

Tile * Tileset::getTile(unsigned int x, unsigned int y) {
    return new Tile(tilesetFileName, x, y);
}


Tileset::~Tileset() {}
