#pragma once
#include <unordered_map>
#include <string>
#include "../components/Tileset.h"
#include "../components/Tile.h"
class TilesetManager {
private:
    static std::unordered_map<std::string, Tileset> allTilesets;
public:
    // TODO: make TextureManager consistance with this add file stlye
    // takes in the file name only, not the whole path to the file.
    static void addTileset(std::string fileName, unsigned int column, unsigned int row, TilesetType tilesetType);
    static Tile* getTile(std::string fileName, unsigned int x, unsigned int y);
};

