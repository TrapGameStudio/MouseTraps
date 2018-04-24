#include "TilesetManager.h"

std::unordered_map<std::string, Tileset> TilesetManager::allTilesets;



void TilesetManager::addTileset(std::string fileName, unsigned int column, unsigned int row, TilesetType tilesetType) {
    if (allTilesets.find(fileName) == allTilesets.end()) {
        allTilesets[fileName] = Tileset(fileName, column, row, tilesetType);
    }
    
}

Tile * TilesetManager::getTile(std::string fileName, unsigned int x, unsigned int y) {
    return allTilesets[fileName].getTile(x, y);
    // TODO: return empty tile for not found
}