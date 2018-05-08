#include "Map02.h"



Map02::Map02()
{
    spawnPoints.push_back(gridToMapCoordinate(20, 3));
    spawnPoints.push_back(gridToMapCoordinate(23, 12));

	TilesetManager::addTileset("Inside_A5.png", 8, 16, TilesetType::A5);

	GameLevel::MapLayer* ground = new GameLevel::MapLayer(this);
	ground->mapAddRow("11111111111111111111111..");
	ground->mapAddRow("11111111111111111111111..");
	ground->mapAddRow("11111111111111111111111..");
	ground->mapAddRow("11111111111111111111111..");
	ground->mapAddRow("11111111111111111111111..");
	ground->mapAddRow("11111111111111111111111..");
	ground->mapAddRow("11111111111111111111111..");
	ground->mapAddRow("11111111111111111111111..");
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
	ground->addCharTileMapping('.', Tile("Inside_A5.png", 0, 0));
	ground->addCharTileMapping('1', Tile("Inside_A4.png", 8, 7));
	ground->addCharTileMapping('3', Tile("Inside_A4.png", 12, 7));
	ground->addCharTileMapping('2', Tile("Inside_A5.png", 0, 11));
	addMapLayer(-2, ground);

	GameLevel::MapLayer* wall = new GameLevel::MapLayer(this);
    wall->mapAddRow("#######################  ");
    wall->mapAddRow("#---------#-----------#  ");
	wall->mapAddRow("#---------#-----------#  ");
	wall->mapAddRow("#         #           #  ");
	wall->mapAddRow("#         #           #  ");
	wall->mapAddRow("#         #           #  ");
	wall->mapAddRow("#         #           #  ");
    wall->mapAddRow("#######   #           #  ");
    wall->mapAddRow("#------   #    ##########");
	wall->mapAddRow("#------   -    ---------#");
	wall->mapAddRow("#         -    ---------#");
	wall->mapAddRow("#                       #");
	wall->mapAddRow("#                       #");
    wall->mapAddRow("#       #   #  ##########");
	wall->mapAddRow("#       #   #  --xzQ----#");
	wall->mapAddRow("#########   #  --XZq----#");
	wall->mapAddRow("#--------   #           #");
	wall->mapAddRow("#--------   #           #");
	wall->mapAddRow("#           #           #");
	wall->mapAddRow("#           #           #");
	wall->mapAddRow("#           #           #");
	wall->mapAddRow("#           #           #");
	wall->mapAddRow("#           #           #");
	wall->mapAddRow("#           #           #");
	wall->mapAddRow("#########################");
	
	wall->addCharTileMapping(' ', Tile("Inside_A5.png", 0, 1)); // TODO: space should always be empty tile
	wall->addCharTileMapping('#', Tile("Inside_A4.png", 0, 0)); // TODO: special interpreter
	wall->addCharTileMapping('-', Tile("Inside_A4.png", 0, 4)); // TODO: special interpreter
    wall->addCharTileMapping('X', Tile("Inside_B.png", 13, 15));
    wall->addCharTileMapping('x', Tile("Inside_B.png", 13, 14));
    wall->addCharTileMapping('Z', Tile("Inside_B.png", 14, 15));
    wall->addCharTileMapping('z', Tile("Inside_B.png", 14, 14));
    wall->addCharTileMapping('q', Tile("Inside_B.png", 15, 15));
    wall->addCharTileMapping('Q', Tile("Inside_B.png", 15, 14));

	addMapLayer(0, wall);

    GameLevel::MapLayer* dec = new GameLevel::MapLayer(this);
    dec->mapAddRow("                         ");
    dec->mapAddRow("                    f    ");
    dec->mapAddRow("       TT  N LPR    F    ");
    dec->mapAddRow(" sSjim tt  n lpr%wu      ");
    dec->mapAddRow("                 WU      ");
    dec->mapAddRow(" yy                      ");
    dec->mapAddRow(" yy                      ");
    dec->mapAddRow("                   k     ");
    dec->mapAddRow(" E  Aa                   ");
    dec->mapAddRow(" eH O B                  ");
    dec->mapAddRow("  h o K                  ");
    dec->mapAddRow("                         ");
    dec->mapAddRow("   {{                    ");
    dec->mapAddRow("  >//<                   ");
    dec->mapAddRow("   }}                    ");
    dec->mapAddRow("                         ");
    dec->mapAddRow("                     ??? ");
    dec->mapAddRow(" NN                  ??? ");
    dec->mapAddRow(" nn c%       ***     ??? ");
    dec->mapAddRow("    b        ***         ");
    dec->mapAddRow("       402   ***         ");
    dec->mapAddRow("       513   ***  ^^^^^^ ");
    dec->mapAddRow(" gG               @@@@@@ ");
    dec->mapAddRow(" Gg                      ");
    dec->mapAddRow("                         ");

    //dec->addCharTileMapping('.', Tile("Inside_A5.png", 0, 0));
    dec->addCharTileMapping(' ', Tile("Inside_A5.png", 0, 1)); // TODO: space should always be empty tile
    dec->addCharTileMapping('#', Tile("Inside_A4.png", 0, 0)); // TODO: special interpreter
    dec->addCharTileMapping('-', Tile("Inside_A4.png", 0, 4)); // TODO: special interpreter
    dec->addCharTileMapping('+', Tile("Inside_A5.png", 0, 3));
    dec->addCharTileMapping('c', Tile("Inside_B.png", 0, 10));
    dec->addCharTileMapping('b', Tile("Inside_B.png", 0, 11));
    dec->addCharTileMapping('d', Tile("Inside_B.png", 4, 11));

    // double bed
    dec->addCharTileMapping('w', Tile("Inside_B.png", 1, 10));
    dec->addCharTileMapping('W', Tile("Inside_B.png", 1, 11));
    dec->addCharTileMapping('u', Tile("Inside_B.png", 2, 10));
    dec->addCharTileMapping('U', Tile("Inside_B.png", 2, 11));

    //piyano
    dec->addCharTileMapping('p', Tile("Inside_B.png", 6, 13));
    dec->addCharTileMapping('l', Tile("Inside_B.png", 5, 13));
    dec->addCharTileMapping('r', Tile("Inside_B.png", 7, 13));
    //top of the piyano
    dec->addCharTileMapping('L', Tile("Inside_B.png", 5, 12));
    dec->addCharTileMapping('P', Tile("Inside_B.png", 6, 12));
    dec->addCharTileMapping('R', Tile("Inside_B.png", 7, 12));
    //fire machine
    dec->addCharTileMapping('f', Tile("Inside_B.png", 11, 0));
    dec->addCharTileMapping('F', Tile("Inside_B.png", 11, 1));
    //cabinet
    dec->addCharTileMapping('t', Tile("Inside_B.png", 4, 7));
    dec->addCharTileMapping('T', Tile("Inside_B.png", 4, 8));

    //table
    dec->addCharTileMapping('k', Tile("Inside_B.png", 0, 12));
    //stove
    dec->addCharTileMapping('s', Tile("Inside_B.png", 0, 14));
    dec->addCharTileMapping('S', Tile("Inside_B.png", 1, 14));
    dec->addCharTileMapping('j', Tile("Inside_B.png", 2, 14));
    dec->addCharTileMapping('i', Tile("Inside_B.png", 3, 14));
    dec->addCharTileMapping('m', Tile("Inside_B.png", 4, 14));
    //painting
    
	dec->addCharTileMapping('A', Tile("Inside_B.png", 14, 4));
	dec->addCharTileMapping('a', Tile("Inside_B.png", 15, 4));
	//clock
	dec->addCharTileMapping('e', Tile("Inside_B.png", 8, 5));
	dec->addCharTileMapping('E', Tile("Inside_B.png", 8, 4));
    

    //jar
    dec->addCharTileMapping('y', Tile("Inside_B.png", 8, 9));
    dec->addCharTileMapping('a', Tile("Inside_B.png", 0, 9));
    dec->addCharTileMapping('a', Tile("Inside_B.png", 0, 9));


    dec->addCharTileMapping('t', Tile("Inside_B.png", 13, 15));

    //chair
    dec->addCharTileMapping('v', Tile("Inside_B.png", 11, 6));
    dec->addCharTileMapping('C', Tile("Inside_B.png", 11, 7));
    dec->addCharTileMapping('6', Tile("Inside_B.png", 10, 6));
    dec->addCharTileMapping('7', Tile("Inside_B.png", 10, 7));
    dec->addCharTileMapping('8', Tile("Inside_B.png", 12, 6));
    dec->addCharTileMapping('9', Tile("Inside_B.png", 12, 7));


    dec->addCharTileMapping('X', Tile("Inside_B.png", 13, 15));
    dec->addCharTileMapping('x', Tile("Inside_B.png", 13, 14));
    dec->addCharTileMapping('Z', Tile("Inside_B.png", 14, 15));
    dec->addCharTileMapping('z', Tile("Inside_B.png", 14, 14));
    dec->addCharTileMapping('q', Tile("Inside_B.png", 15, 15));
    dec->addCharTileMapping('Q', Tile("Inside_B.png", 15, 14));


    //bosta

    dec->addCharTileMapping('^', Tile("Inside_B.png", 10, 14));
    dec->addCharTileMapping('@', Tile("Inside_B.png", 10, 15));


    //half bosta

    dec->addCharTileMapping('*', Tile("Inside_B.png", 9, 15));
    dec->addCharTileMapping('?', Tile("Inside_B.png", 9, 10));

    //rect table

    dec->addCharTileMapping('/', Tile("Inside_B.png", 4, 13));
    dec->addCharTileMapping('%', Tile("Inside_B.png", 4, 12));

    //flower
    dec->addCharTileMapping('G', Tile("Inside_C.png", 4, 10));
    dec->addCharTileMapping('g', Tile("Inside_C.png", 5, 10));

    //vertical dec
    dec->addCharTileMapping('.', Tile("Inside_A4.png", 0, 4));

    // bookShelf
    dec->addCharTileMapping('N', Tile("Inside_B.png", 5, 8));
    dec->addCharTileMapping('n', Tile("Inside_B.png", 5, 9));

    // sofa up
    dec->addCharTileMapping('[', Tile("SF_Inside_B.png", 14, 3));
    dec->addCharTileMapping(']', Tile("SF_Inside_B.png", 15, 3));

    //glass table
    dec->addCharTileMapping('(', Tile("SF_Inside_B.png", 13, 5));
    dec->addCharTileMapping(')', Tile("SF_Inside_B.png", 14, 5));

    //vertical glass table
    dec->addCharTileMapping('0', Tile("SF_Inside_B.png", 15, 4));
    dec->addCharTileMapping('1', Tile("SF_Inside_B.png", 15, 5));

    // left sofa
    dec->addCharTileMapping('2', Tile("SF_Inside_B.png", 13, 2));
    dec->addCharTileMapping('3', Tile("SF_Inside_B.png", 13, 3));

    // right sofa
    dec->addCharTileMapping('4', Tile("SF_Inside_B.png", 12, 2));
    dec->addCharTileMapping('5', Tile("SF_Inside_B.png", 12, 3));

    // chair down
    dec->addCharTileMapping('{', Tile("SF_Inside_B.png", 8, 2));

    // chair up
    dec->addCharTileMapping('}', Tile("SF_Inside_B.png", 9, 2));

    // chair right
    dec->addCharTileMapping('>', Tile("SF_Inside_B.png", 10, 2));

    // chair left
    dec->addCharTileMapping('<', Tile("SF_Inside_B.png", 11, 2));
	//treees
	dec->addCharTileMapping('H', Tile("SF_Inside_C.png", 6, 4));
	dec->addCharTileMapping('h', Tile("SF_Inside_C.png", 6, 5));

	dec->addCharTileMapping('O', Tile("SF_Inside_C.png", 7, 4));
	dec->addCharTileMapping('o', Tile("SF_Inside_C.png", 7, 5));

	dec->addCharTileMapping('B', Tile("SF_Inside_C.png", 5, 4));
	dec->addCharTileMapping('K', Tile("SF_Inside_C.png", 5, 5));

    addMapLayer(1, dec);

    Entity* character = Entity::builder()
        .ofTexture("Graphics/Characters/Char3.png")
        .ofDirection(Direction::MoveDown)
        .atLocation(-0.4, 0.4)
        .build();

    character->setKillFunction([this, character]() {
		character->setSpeed(0.0f);
        character->setTexture("Graphics/Characters/Char3-damaged.png");
    });

    setPlayerCharacter(character);
    pushAnimatedShapeToBack(character);
    pushShapeToBack(character);

    setMiceGenerator(this, spawnPoints);
}






Map02::~Map02(){}
