#include "Map01.h"

Map01::Map01() {
	TilesetManager::addTileset("Inside_A5.png", 8, 16, TilesetType::A5);

	GameLevel::MapLayer* ground = new GameLevel::MapLayer(this);
	ground->mapAddRow("11111111111111111111"); // Row 1
	ground->mapAddRow("11111111111111111111"); // Row 2
	ground->mapAddRow("11121111111111111111"); // Row 3
	ground->mapAddRow("11111111111111111111"); // Row 4
	ground->mapAddRow("11111111111111111111"); // Row 5
	ground->mapAddRow("11111111111111111111"); // Row 6
	ground->mapAddRow("11111111111111112111"); // Row 7
	ground->mapAddRow("11111111111111111111"); // Row 8
	ground->mapAddRow("11111111111111111111"); // Row 9
	ground->mapAddRow("11111211111111111111"); // Row 10
	ground->mapAddRow("11111111111111111111"); // Row 12
	ground->mapAddRow("11111111111111211111"); // Row 13
	ground->mapAddRow("11111111111111111111"); // Row 14
	ground->mapAddRow("11111111111111111111"); // Row 15
	ground->mapAddRow("11111111111111111111"); // Row 16
	ground->mapAddRow("11111111111111111111"); // Row 17
	ground->mapAddRow("11111111111111111211"); // Row 18
	ground->mapAddRow("11211111111111111111"); // Row 19
	ground->mapAddRow("11111111111111111111"); // Row 20
	ground->addCharTileMapping('.', Tile("Inside_A5.png", 0, 0));
	ground->addCharTileMapping('1', Tile("Inside_A5.png", 0, 2));
	ground->addCharTileMapping('2', Tile("Inside_A5.png", 0, 11));
	addMapLayer(-1, ground);

	GameLevel::MapLayer* wall = new GameLevel::MapLayer(this);
	wall->mapAddRow("####################"); // Row 1
	wall->mapAddRow("#-------#----------#"); // Row 2
	wall->mapAddRow("#       -          #"); // Row 3
	wall->mapAddRow("#             #    #"); // Row 4
	wall->mapAddRow("#       #  ####    #"); // Row 5
	wall->mapAddRow("#### ####  #---    #"); // Row 6
	wall->mapAddRow("#--- ----  #       #"); // Row 7
	wall->mapAddRow("#          #       #"); // Row 8
	wall->mapAddRow("#          #       #"); // Row 9
	wall->mapAddRow("#          #### ####"); // Row 10
	wall->mapAddRow("#          ---- ---#"); // Row 12
	wall->mapAddRow("## ###             #"); // Row 13
	wall->mapAddRow("#- --#             #"); // Row 14
	wall->mapAddRow("#    ######        #"); // Row 15
	wall->mapAddRow("#    -----#        #"); // Row 16
	wall->mapAddRow("#         -        #"); // Row 17
	wall->mapAddRow("#                  #"); // Row 18
	wall->mapAddRow("#         #        #"); // Row 19
	wall->mapAddRow("####################"); // Row 20
	wall->addCharTileMapping(' ', Tile("Inside_A5.png", 0, 1)); // TODO: space should always be empty tile
	wall->addCharTileMapping('#', Tile("Inside_A4.png", 0, 0)); // TODO: special interpreter
	wall->addCharTileMapping('-', Tile("Inside_A4.png", 0, 4)); // TODO: special interpreter
	wall->addCharTileMapping('+', Tile("Inside_A5.png", 0, 3));
	addMapLayer(1, wall);
}

Map01::~Map01() {}