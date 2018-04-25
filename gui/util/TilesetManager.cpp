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

unsigned int TilesetManager::getTilesetColumn(std::string name) {
    return allTilesets[name].getColumn();
}

unsigned int TilesetManager::getTilesetRow(std::string name) {
    return allTilesets[name].getRow();
}

TextureRect * TilesetManager::getTextureRect(Tile & tile) {
    TextureRect* newTextureRect = TextureRect::builder()
        .ofTexture(("Graphics/Tilesets/" + tile.getTilesetName()).c_str())
        .ofColumnRow(getTilesetColumn(tile.getTilesetName()), getTilesetRow(tile.getTilesetName()))
        .ofCurrentColumnRow(tile.getTileX(), tile.getTileY())
        .ofSize(2.0f / 30, 2.0f / 30)  // TODO: make configurable
        .ofTextureType(TextureType::TileSet)
        .ofShade(Color::white())
        .build();
    return newTextureRect;
}

