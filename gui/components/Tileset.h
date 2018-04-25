#pragma once
#include "../util/TextureManager.h"
#include "../lang/TilesetType.h"
#include "Tile.h"
#include <string>
class Tileset {
    GLuint textureID = 0;
    std::string tilesetFileName;
    TilesetType tilesetType;
    unsigned int column = 16;
    unsigned int row = 16;
public:
    Tileset() {};
    Tileset(std::string tilesetFileName, unsigned int column, unsigned int row, TilesetType tilesetType);
    Tile* getTile(unsigned int x, unsigned int y);
    unsigned int getColumn() const;
    unsigned int getRow() const;
    ~Tileset();
};

