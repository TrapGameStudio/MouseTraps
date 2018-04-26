#include "DemoLevel.h"



DemoLevel::DemoLevel() {
    TilesetManager::addTileset("Inside_A5.png", 8, 16, TilesetType::A5);

    GameLevel::MapLayer* ground = new GameLevel::MapLayer(this);
    ground->mapAddRow(".........................");
    ground->mapAddRow(".........................");
    ground->mapAddRow(".........................");
    ground->mapAddRow("1111111111111111111111111");
    ground->mapAddRow("1111111111111111111111111");
    ground->mapAddRow("1111111111111111111111111");
    ground->mapAddRow("1111121111111111111111111");
    ground->mapAddRow("1111111111111111111111111");
    ground->mapAddRow("1111111111111111111111111");
    ground->mapAddRow("............1............");
    ground->mapAddRow(".........................");
    ground->mapAddRow(".........................");
    ground->mapAddRow(".........................");
    ground->addCharTileMapping('.', Tile("Inside_A5.png", 0, 0));
    ground->addCharTileMapping('1', Tile("Inside_A5.png", 0, 2));
    ground->addCharTileMapping('2', Tile("Inside_A5.png", 0, 11));
    addMapLayer(-2, ground);

    GameLevel::MapLayer* wall = new GameLevel::MapLayer(this);
    wall->mapAddRow("                         ");
    wall->mapAddRow("                         ");
    wall->mapAddRow("                         ");
    wall->mapAddRow("#########################");
    wall->mapAddRow("#-----------------------#");
    wall->mapAddRow("#                       #");
    wall->mapAddRow("#             ###########");
    wall->mapAddRow("#             #---------#");
    wall->mapAddRow("############ ############");
    wall->mapAddRow("------------ ------------");
    wall->mapAddRow("+++++++++++++++++++++++++");
    wall->mapAddRow("                         ");
    wall->mapAddRow("                         ");
    wall->addCharTileMapping(' ', Tile("Inside_A5.png", 0, 1)); // TODO: space should always be empty tile
    wall->addCharTileMapping('#', Tile("Inside_A4.png", 0, 0)); // TODO: special interpreter
    wall->addCharTileMapping('-', Tile("Inside_A4.png", 0, 4)); // TODO: special interpreter
    wall->addCharTileMapping('+', Tile("Inside_A5.png", 0, 3));
    addMapLayer(0, wall);
}


DemoLevel::~DemoLevel() {}
