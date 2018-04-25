#pragma once
#include <string>
#include <vector>
#include "../geom/Point.h"
class Tile {
private:
    std::string tilesetName;
    Point tileCoordinate;  // TODO: should not be float. check.
public:
    Tile() {};
    Tile(std::string tileSetName, float x, float y);  // TODO: should not be float. check.
    std::string getTilesetName() const;
    const Point& getTileCoordinate() const;
    unsigned int getTileX() const;
    unsigned int getTileY() const;
    void setTileset(std::string tilesetName);
    void setTile(float x, float y);  // TODO: should not be float. check.
    ~Tile();
};

