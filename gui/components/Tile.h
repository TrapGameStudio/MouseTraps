#pragma once
#include <string>
#include <vector>
#include "../geom/Point.h"
#include "TextureRect.h"
class Tile {
private:
    std::string tilesetName;
    Point tileCoordinate;  // TODO: should not be float. check.
public:
    Tile(std::string tileSetName, float x, float y);  // TODO: should not be float. check.
    void setTileset(std::string tilesetName);
    void setTile(float x, float y);  // TODO: should not be float. check.
    TextureRect* getTextureRect();
    ~Tile();
};

