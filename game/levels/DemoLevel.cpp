#include "DemoLevel.h"



DemoLevel::DemoLevel() {
    GameMapLayer floor(this);
    floor.mapAddRow("..............................");
    floor.mapAddRow("..............................");
    floor.mapAddRow("..............................");
    floor.mapAddRow("111111111111111111111111111111");
    floor.mapAddRow("111111111111111111111111111111");
    floor.mapAddRow("111111111111111111111111111111");
    floor.mapAddRow("111111111111111111111111111111");
    floor.mapAddRow("#11111111111111111111111111111");
    floor.mapAddRow("111111111111111111111111111111");
    floor.mapAddRow("...............1..............");
    floor.mapAddRow("..............................");
    floor.mapAddRow("..............................");
    floor.mapAddRow("..............................");
    floor.addCharTileMapping('.', Tile("Inside_A5.png", 0, 0));
    floor.addCharTileMapping('1', Tile("Inside_A5.png", 2, 0));
    addMapLayer(-2, floor);

    GameMapLayer wall(this);
    floor.mapAddRow("                              ");
    floor.mapAddRow("                              ");
    floor.mapAddRow("                              ");
    floor.mapAddRow("##############################");
    floor.mapAddRow("#                            #");
    floor.mapAddRow("#                            #");
    floor.mapAddRow("#                            #");
    floor.mapAddRow("#                            #");
    floor.mapAddRow("############### ##############");
    floor.mapAddRow("--------------- --------------");
    floor.mapAddRow("++++++++++++++++++++++++++++++");
    floor.mapAddRow("                              ");
    floor.mapAddRow("                              ");
    floor.addCharTileMapping('#', Tile("Inside_A4.png", 0, 0)); // TODO: special interpreter
    floor.addCharTileMapping('-', Tile("Inside_A4.png", 0, 1)); // TODO: special interpreter
    floor.addCharTileMapping('+', Tile("Inside_A5.png", 3, 0));
    addMapLayer(0, floor);
}


DemoLevel::~DemoLevel() {}
