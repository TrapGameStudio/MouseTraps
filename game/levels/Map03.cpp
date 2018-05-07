#include "Map03.h"



Map03::Map03()
{
	TilesetManager::addTileset("Inside_A5.png", 8, 16, TilesetType::A5);

	GameLevel::MapLayer* ground = new GameLevel::MapLayer(this);
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111121111111111121111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111112111111111111111111");
	ground->mapAddRow("1111111111111111211111121");
	ground->mapAddRow("1111111112211111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111121111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111211");
	ground->mapAddRow("1111111211111111111111111");
	ground->mapAddRow("1111111111111111112111111");
	ground->mapAddRow("1112111111111111111111111");
	ground->mapAddRow("1111111221111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("1111111111111111111111111");
	ground->mapAddRow("3333331112111111111111111");
	ground->mapAddRow("3343331112211111111121111");
	ground->mapAddRow("3333331111111111111111111");
	ground->mapAddRow("3333431121111111211111111");
	ground->mapAddRow("3333331111111111111111211");
	ground->mapAddRow("3333331111111111111111111");

	ground->addCharTileMapping('.', Tile("Inside_A5.png", 0, 0));
	ground->addCharTileMapping('1', Tile("Inside_A5.png", 5, 4));
	ground->addCharTileMapping('2', Tile("Inside_A5.png", 5, 12));
	ground->addCharTileMapping('3', Tile("Inside_A5.png", 6, 4));
	ground->addCharTileMapping('4', Tile("Inside_A5.png", 6, 12));

	addMapLayer(-2, ground);

	GameLevel::MapLayer* wall = new GameLevel::MapLayer(this);
	wall->mapAddRow("#########################");
	wall->mapAddRow("#-----------------------#");
	wall->mapAddRow("#=======================#");
	wall->mapAddRow("#_______________________#");
	wall->mapAddRow("#                       #");
	wall->mapAddRow("#                       #");
	wall->mapAddRow("#                       #");
	wall->mapAddRow("#                       #");
	wall->mapAddRow("#######    ##########   #");
	wall->mapAddRow("#------    ----------   #");
	wall->mapAddRow("#======    ==========   #");
	wall->mapAddRow("#______    __________   #");
	wall->mapAddRow("#                       #");
	wall->mapAddRow("#                       #");
	wall->mapAddRow("#           ##########  #");
	wall->mapAddRow("######      #---------  #");
	wall->mapAddRow("#----#      #=========  #");
	wall->mapAddRow("#====#      #_________  #");
	wall->mapAddRow("#____#      #           #");
	wall->mapAddRow("#    #      #           #");
	wall->mapAddRow("#    -      -           #");
	wall->mapAddRow("#    =      =           #");
	wall->mapAddRow("#    _      _           #");
	wall->mapAddRow("#                       #");
	wall->mapAddRow("#########################");

	wall->addCharTileMapping(' ', Tile("Inside_A5.png", 0, 1)); // TODO: space should always be empty tile
	wall->addCharTileMapping('#', Tile("Inside_A4.png", 10, 7)); // TODO: special interpreter
	wall->addCharTileMapping('-', Tile("Inside_A4.png", 10, 8)); // TODO: special interpreter
	wall->addCharTileMapping('=', Tile("Inside_A4.png", 10, 9));
	wall->addCharTileMapping('_', Tile("Inside_A4.png", 10, 10));

	addMapLayer(0, wall);

	GameLevel::MapLayer* dec = new GameLevel::MapLayer(this);
	dec->mapAddRow("                         ");
	dec->mapAddRow("                         ");
	dec->mapAddRow("  P HABCG     DE   T     ");
	dec->mapAddRow("    habcg  NfFdeNz t JKu ");
	dec->mapAddRow(" n y                Ujk  ");
	dec->mapAddRow(" &                    U  ");
	dec->mapAddRow(" nn                      ");
	dec->mapAddRow(" nn&                y    ");
	dec->mapAddRow("                         ");
	dec->mapAddRow("                         ");
	dec->mapAddRow("  Q R H    G q Ww r H    ");
	dec->mapAddRow(" 12zZZh    g        h    ");
	dec->mapAddRow(" 347                     ");
	dec->mapAddRow(" L6  Y       &n&         ");
	dec->mapAddRow(" l6                      ");
	dec->mapAddRow("                         ");
	dec->mapAddRow("        !@      Xx p G   ");
	dec->mapAddRow("   S    $%   JK      g   ");
	dec->mapAddRow(" O  s u      jk          ");
	dec->mapAddRow(" o    n      ^*          ");
	dec->mapAddRow("      n      ^*  Y     7 ");
	dec->mapAddRow("      n      F       125 ");
	dec->mapAddRow(" V               U   34L ");
	dec->mapAddRow(" v y            &&nu 86l ");
	dec->mapAddRow("                         ");

	//dec->addCharTileMapping('.', Tile("Inside_A5.png", 0, 0));
	dec->addCharTileMapping(' ', Tile("Inside_A5.png", 0, 1)); // TODO: space should always be empty tile
	dec->addCharTileMapping('#', Tile("Inside_A4.png", 0, 0)); // TODO: special interpreter
	dec->addCharTileMapping('-', Tile("Inside_A4.png", 0, 4)); // TODO: special interpreter

	// fireplace
	dec->addCharTileMapping('A', Tile("Inside_B.png", 8, 0));
	dec->addCharTileMapping('B', Tile("Inside_B.png", 9, 0));
	dec->addCharTileMapping('C', Tile("Inside_B.png", 10, 0));
	dec->addCharTileMapping('a', Tile("Inside_B.png", 8, 1));
	dec->addCharTileMapping('b', Tile("Inside_B.png", 9, 1));
	dec->addCharTileMapping('c', Tile("Inside_B.png", 10, 1));

	// boxes
	dec->addCharTileMapping('D', Tile("Inside_B.png", 10, 12));
	dec->addCharTileMapping('E', Tile("Inside_B.png", 11, 12));
	dec->addCharTileMapping('d', Tile("Inside_B.png", 10, 13));
	dec->addCharTileMapping('e', Tile("Inside_B.png", 11, 13));
	dec->addCharTileMapping('F', Tile("Inside_B.png", 8, 12));
	dec->addCharTileMapping('f', Tile("Dungeon_B.png", 13, 11));

	// tap
	dec->addCharTileMapping('G', Tile("Inside_B.png", 14, 0));
	dec->addCharTileMapping('g', Tile("Inside_B.png", 14, 1));
	dec->addCharTileMapping('H', Tile("Inside_B.png", 15, 0));
	dec->addCharTileMapping('h', Tile("Inside_B.png", 15, 1));

	// dragon statue
	dec->addCharTileMapping('J', Tile("Dungeon_B.png", 14, 7));
	dec->addCharTileMapping('K', Tile("Dungeon_B.png", 15, 7));
	dec->addCharTileMapping('j', Tile("Dungeon_B.png", 14, 8));
	dec->addCharTileMapping('k', Tile("Dungeon_B.png", 15, 8));
	dec->addCharTileMapping('L', Tile("Dungeon_B.png", 14, 3));
	dec->addCharTileMapping('l', Tile("Dungeon_B.png", 14, 4));

	// mirror
	dec->addCharTileMapping('M', Tile("Inside_B.png", 9, 4));
	dec->addCharTileMapping('m', Tile("Inside_B.png", 9, 5));

	dec->addCharTileMapping('N', Tile("Dungeon_B.png", 14, 11));
	dec->addCharTileMapping('n', Tile("Dungeon_B.png", 14, 13));

	// toilet
	dec->addCharTileMapping('O', Tile("SF_Inside_B.png", 9, 4));
	dec->addCharTileMapping('o', Tile("SF_Inside_B.png", 9, 5));

	// picures
	dec->addCharTileMapping('P', Tile("Inside_B.png", 11, 5));
	dec->addCharTileMapping('p', Tile("Inside_B.png", 10, 4));
	dec->addCharTileMapping('Q', Tile("Inside_B.png", 10, 5));
	dec->addCharTileMapping('q', Tile("Inside_B.png", 10, 8));
	dec->addCharTileMapping('R', Tile("Inside_B.png", 9, 8));
	dec->addCharTileMapping('r', Tile("Inside_B.png", 8, 8));

	// sink
	dec->addCharTileMapping('S', Tile("SF_Inside_B.png", 11, 4));
	dec->addCharTileMapping('s', Tile("SF_Inside_B.png", 11, 5));

	// clock
	dec->addCharTileMapping('T', Tile("Inside_B.png", 8, 4));
	dec->addCharTileMapping('t', Tile("Inside_B.png", 8, 5));

	// dirt piles
	dec->addCharTileMapping('U', Tile("Dungeon_B.png", 1, 6));
	dec->addCharTileMapping('u', Tile("Dungeon_B.png", 1, 7));

	// bath
	dec->addCharTileMapping('V', Tile("SF_Inside_B.png", 12, 4));
	dec->addCharTileMapping('v', Tile("SF_Inside_B.png", 12, 5));

	// pictures
	dec->addCharTileMapping('W', Tile("Inside_B.png", 12, 4));
	dec->addCharTileMapping('w', Tile("Inside_B.png", 13, 4));
	dec->addCharTileMapping('X', Tile("Inside_B.png", 14, 4));
	dec->addCharTileMapping('x', Tile("Inside_B.png", 15, 4));

	dec->addCharTileMapping('Y', Tile("Dungeon_B.png", 10, 14));
	dec->addCharTileMapping('y', Tile("Dungeon_B.png", 10, 15));

	dec->addCharTileMapping('Z', Tile("Dungeon_B.png", 12, 13));
	dec->addCharTileMapping('z', Tile("Dungeon_B.png", 12, 12));

	dec->addCharTileMapping('!', Tile("Dungeon_B.png", 8, 14));
	dec->addCharTileMapping('@', Tile("Dungeon_B.png", 9, 14));
	dec->addCharTileMapping('$', Tile("Dungeon_B.png", 8, 15));
	dec->addCharTileMapping('%', Tile("Dungeon_B.png", 9, 15));

	// gold bars
	dec->addCharTileMapping('*', Tile("Inside_C.png", 8, 9));
	dec->addCharTileMapping('^', Tile("Inside_C.png", 9, 9));

	dec->addCharTileMapping('&', Tile("Dungeon_B.png", 15, 13));

	dec->addCharTileMapping('1', Tile("Dungeon_B.png", 12, 9));
	dec->addCharTileMapping('2', Tile("Dungeon_B.png", 13, 9));
	dec->addCharTileMapping('3', Tile("Dungeon_B.png", 12, 10));
	dec->addCharTileMapping('4', Tile("Dungeon_B.png", 13, 10));
	dec->addCharTileMapping('5', Tile("Dungeon_B.png", 6, 13));
	dec->addCharTileMapping('6', Tile("Dungeon_B.png", 7, 13));
	dec->addCharTileMapping('7', Tile("Dungeon_B.png", 8, 13));
	dec->addCharTileMapping('8', Tile("Dungeon_B.png", 9, 13));

	addMapLayer(1, dec);

	Entity* character = Entity::builder()
		.ofTexture("Graphics/Characters/Char3.png")
		.ofDirection(Direction::MoveDown)
		.atLocation(-0.6, 0.6)
		.build();

	setPlayerCharacter(character);
	pushAnimatedShapesToBack(character);
	pushShapeToBack(character);

	for (int i = 0; i < 5; i++) {
		pushAnimatedShapesToBack(mice->accessMouse(i));
		pushShapeToBack(mice->accessMouse(i));
	}
}

Map03::~Map03() {}
