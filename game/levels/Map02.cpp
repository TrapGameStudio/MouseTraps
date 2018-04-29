#include "Map02.h"



Map02::Map02()
{
	TilesetManager::addTileset("Inside_A5.png", 8, 16, TilesetType::A5);

	GameLevel::MapLayer* ground = new GameLevel::MapLayer(this);
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111113333333333333");
	ground->mapAddRow("1111111111113333333333333");
	ground->mapAddRow("1111111111113333333333333");
	ground->mapAddRow("1111111111113333333333333");
	ground->mapAddRow("1111111111113333333333333");
	ground->mapAddRow("1111111111113333333333333");
	ground->mapAddRow("1111111111113333333333333");
	ground->mapAddRow("1111111111113333333333333");
	ground->mapAddRow("1111111111113333333333333");
	ground->mapAddRow("1111111111113333333333333");
	ground->mapAddRow("1111111111113333333333333");
	ground->addCharTileMapping('.', Tile("Inside_A5.png", 0, 0));
	ground->addCharTileMapping('1', Tile("Inside_A4.png", 8, 7));
	ground->addCharTileMapping('3', Tile("Inside_A4.png", 12, 7));
	ground->addCharTileMapping('2', Tile("Inside_A5.png", 0, 11));
	addMapLayer(-2, ground);

	GameLevel::MapLayer* wall = new GameLevel::MapLayer(this);
	wall->mapAddRow("#####################f####");
	wall->mapAddRow("#sSjim  t ###########F####");
	wall->mapAddRow("#         ## LPR%c t  ###");
	wall->mapAddRow("#         ## lpr d T  ###");
	wall->mapAddRow("#yy       ##          ###");
	wall->mapAddRow("#yy       ##      6v8 ###");
	wall->mapAddRow("#         ##      7C9 ###");
	wall->mapAddRow("##A###e   ##       k  ###");
	wall->mapAddRow("# a w E   ##          ###");
	wall->mapAddRow("#         ##   ##########");
	wall->mapAddRow("#         ##   ##########");
	wall->mapAddRow("# ~;<~;<                #");
	wall->mapAddRow("# :>{:>{                #");
	wall->mapAddRow("#  /    ##  #  ##xzQ#####");
	wall->mapAddRow("#       ##  #    XZq    #");
	wall->mapAddRow("##########  #        ???#");
	wall->mapAddRow("##########  #        ???#");
	wall->mapAddRow("# c%        #***     ???#");
	wall->mapAddRow("# b         #***     ???#");
	wall->mapAddRow("#           #***        #");
	wall->mapAddRow("#       gG  #***        #");
	wall->mapAddRow("# 6v8   Gg  #     ^^^^^^#");
	wall->mapAddRow("# 7C9       #     @@@@@@#");
	wall->mapAddRow("#  }        #############");
	wall->mapAddRow("#########################");
	
	wall->addCharTileMapping('.', Tile("Inside_A5.png", 0, 0));
	wall->addCharTileMapping(' ', Tile("Inside_A5.png", 0, 1)); // TODO: space should always be empty tile
	wall->addCharTileMapping('#', Tile("Inside_A4.png", 0, 0)); // TODO: special interpreter
	wall->addCharTileMapping('-', Tile("Inside_A4.png", 0, 4)); // TODO: special interpreter
	wall->addCharTileMapping('+', Tile("Inside_A5.png", 0, 3));
	wall->addCharTileMapping('c', Tile("Inside_B.png", 0, 10));
	wall->addCharTileMapping('b', Tile("Inside_B.png", 0, 11));
	wall->addCharTileMapping('d', Tile("Inside_B.png", 4, 11));
	//piyano
	wall->addCharTileMapping('p', Tile("Inside_B.png", 6, 13));
	wall->addCharTileMapping('l', Tile("Inside_B.png", 5, 13));
	wall->addCharTileMapping('r', Tile("Inside_B.png", 7, 13));
	//top of the piyano
	wall->addCharTileMapping('L', Tile("Inside_B.png", 5, 12));
	wall->addCharTileMapping('p', Tile("Inside_B.png", 6, 12));
	wall->addCharTileMapping('R', Tile("Inside_B.png", 7, 12));
	//fire machine
	wall->addCharTileMapping('f', Tile("Inside_B.png", 11, 0));
	wall->addCharTileMapping('F', Tile("Inside_B.png", 11, 1));
	//cabinet
	wall->addCharTileMapping('t', Tile("Inside_B.png", 4, 7));
	wall->addCharTileMapping('T', Tile("Inside_B.png", 4, 8));

	//table
	wall->addCharTileMapping('k', Tile("Inside_B.png", 0, 12));
	//stove
	wall->addCharTileMapping('s', Tile("Inside_B.png", 0, 14));
	wall->addCharTileMapping('S', Tile("Inside_B.png", 1, 14));
	wall->addCharTileMapping('j', Tile("Inside_B.png", 2, 14));
	wall->addCharTileMapping('i', Tile("Inside_B.png", 3, 14));
	wall->addCharTileMapping('m', Tile("Inside_B.png", 4, 14));
	//fruit
	wall->addCharTileMapping('A', Tile("Inside_B.png", 0, 8));
	wall->addCharTileMapping('a', Tile("Inside_B.png", 0, 9));
	wall->addCharTileMapping('w', Tile("Inside_B.png", 0, 15));
	wall->addCharTileMapping('e', Tile("Inside_B.png", 1, 8));
	wall->addCharTileMapping('E', Tile("Inside_B.png", 1, 9));

	//jar
	wall->addCharTileMapping('y', Tile("Inside_B.png", 8, 9));
	wall->addCharTileMapping('a', Tile("Inside_B.png", 0, 9));
	wall->addCharTileMapping('a', Tile("Inside_B.png", 0, 9));


	wall->addCharTileMapping('t', Tile("Inside_B.png", 13, 15));

	//chair
	wall->addCharTileMapping('v', Tile("Inside_B.png", 11, 6));
	wall->addCharTileMapping('C', Tile("Inside_B.png", 11, 7));
	wall->addCharTileMapping('6', Tile("Inside_B.png", 10, 6));
	wall->addCharTileMapping('7', Tile("Inside_B.png", 10, 7));
	wall->addCharTileMapping('8', Tile("Inside_B.png", 12, 6));
	wall->addCharTileMapping('9', Tile("Inside_B.png", 12, 7));
	//chair
	wall->addCharTileMapping('~', Tile("Inside_B.png", 13, 6));
	wall->addCharTileMapping(':', Tile("Inside_B.png", 13, 7));
	wall->addCharTileMapping(';', Tile("Inside_B.png", 14, 6));
	wall->addCharTileMapping('>', Tile("Inside_B.png", 14, 7));
	wall->addCharTileMapping('<', Tile("Inside_B.png", 15, 6));
	wall->addCharTileMapping('{', Tile("Inside_B.png", 15, 7));

	wall->addCharTileMapping('X', Tile("Inside_B.png", 13, 15));
	wall->addCharTileMapping('x', Tile("Inside_B.png", 13, 14));
	wall->addCharTileMapping('Z', Tile("Inside_B.png", 14, 15));
	wall->addCharTileMapping('z', Tile("Inside_B.png", 14, 14));
	wall->addCharTileMapping('q', Tile("Inside_B.png", 15, 15));
	wall->addCharTileMapping('Q', Tile("Inside_B.png", 15, 14));


	//bosta
	
	wall->addCharTileMapping('^', Tile("Inside_B.png", 10, 14));
	wall->addCharTileMapping('@', Tile("Inside_B.png", 10, 15));
	
	
	//half bosta
	
	wall->addCharTileMapping('*', Tile("Inside_B.png", 9, 15));
	wall->addCharTileMapping('?', Tile("Inside_B.png", 9, 10));

	//rect table

	wall->addCharTileMapping('/', Tile("Inside_B.png", 4, 13));
    wall->addCharTileMapping('}', Tile("Inside_B.png", 3, 13));
	wall->addCharTileMapping('%', Tile("Inside_B.png", 4, 12));

	//flower
	wall->addCharTileMapping('G', Tile("Inside_C.png", 4, 10));
	wall->addCharTileMapping('g', Tile("Inside_C.png", 5, 10));

	addMapLayer(0, wall);
}




Map02::~Map02(){}
