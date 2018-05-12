// This is the map to the basement level of the Mouse Traps

#include "Map01.h"

Map01::Map01() {
    spawnPoints.push_back(gridToMapCoordinate(19, 3));
    spawnPoints.push_back(gridToMapCoordinate(5, 3));
    spawnPoints.push_back(gridToMapCoordinate(12, 3));

	TilesetManager::addTileset("Inside_A5.png", 8, 16, TilesetType::A5);

	// Floor Schematic
	GameLevel::MapLayer* ground = new GameLevel::MapLayer(this);
	ground->mapAddRow("1111111111111111111111111"); // Row 1
	ground->mapAddRow("1111111111111111111111111"); // Row 2
	ground->mapAddRow("1111111111111111111111111"); // Row 3
	ground->mapAddRow("1111111111111111111111111"); // Row 4
	ground->mapAddRow("1111111111111111111111111"); // Row 5
	ground->mapAddRow("1111111111111111111111111"); // Row 6
	ground->mapAddRow("1111111111111111111111111"); // Row 7
	ground->mapAddRow("1111111111111111111111111"); // Row 8
	ground->mapAddRow("1111111111111111111111111"); // Row 9
	ground->mapAddRow("1111111111111111111111111"); // Row 10
	ground->mapAddRow("1111111111111111111111111"); // Row 11
	ground->mapAddRow("1111111111111111111111111"); // Row 12
	ground->mapAddRow("1111111111111111111111111"); // Row 13
	ground->mapAddRow("1111111111111111111111111"); // Row 14
	ground->mapAddRow("1111111111111111111111111"); // Row 15
	ground->mapAddRow("1111111111111111111111111"); // Row 16
	ground->mapAddRow("1111111111111111111111111"); // Row 17
	ground->mapAddRow("1111111111111111111111111"); // Row 18
	ground->mapAddRow("1111111111111111111111111"); // Row 19
	ground->mapAddRow("1111111111111111111111111"); // Row 20
	ground->mapAddRow("1111111111111111111111111"); // Row 21
	ground->mapAddRow("1111111111111111111111111"); // Row 22
	ground->mapAddRow("1111111111111111111111111"); // Row 23
	ground->mapAddRow("1111111111111111111111111"); // Row 24
	ground->mapAddRow("1111111111111111111111111"); // Row 25
	ground->addCharTileMapping(' ', Tile("Inside_A5.png", 0, 0));
	ground->addCharTileMapping('1', Tile("Inside_A5.png", 7, 11));
	ground->addCharTileMapping('2', Tile("Inside_A5.png", 0, 11));
	addMapLayer(-1, ground);

	// Wall Schematic
	GameLevel::MapLayer* wall = new GameLevel::MapLayer(this);
	wall->mapAddRow("#########################"); // Row 1
	wall->mapAddRow("#-----------------------#"); // Row 2
	wall->mapAddRow("#-----------------------#"); // Row 3
	wall->mapAddRow("#                       #"); // Row 4
	wall->mapAddRow("#                       #"); // Row 5
	wall->mapAddRow("#                       #"); // Row 6
	wall->mapAddRow("#                       #"); // Row 7
	wall->mapAddRow("#                       #"); // Row 8
	wall->mapAddRow("#####  ####   ####  #####"); // Row 9
	wall->mapAddRow("#----  ---#   #---  ----#"); // Row 10
	wall->mapAddRow("#----  ---#   #---  ----#"); // Row 11
	wall->mapAddRow("#         #   #         #"); // Row 12
	wall->mapAddRow("#         #   #         #"); // Row 13
	wall->mapAddRow("#         #   #         #"); // Row 14
	wall->mapAddRow("#         #   #         #"); // Row 15
	wall->mapAddRow("#####  ####   ####  #####"); // Row 16
	wall->mapAddRow("#----  ----   ----  ----#"); // Row 17
	wall->mapAddRow("#----  ----   ----  ----#"); // Row 18
	wall->mapAddRow("#                       #"); // Row 19
	wall->mapAddRow("#                       #"); // Row 20
	wall->mapAddRow("#                       #"); // Row 21
	wall->mapAddRow("#                       #"); // Row 22
	wall->mapAddRow("#                       #"); // Row 23
	wall->mapAddRow("#                       #"); // Row 24
	wall->mapAddRow("#########################"); // Row 25
	wall->addCharTileMapping(' ', Tile("Inside_A5.png", 0, 1)); // No Wall
	wall->addCharTileMapping('#', Tile("Inside_A4.png", 0, 0)); // Top Wall
	wall->addCharTileMapping('-', Tile("Inside_A4.png", 1, 4)); // Dark Wall
	wall->addCharTileMapping('+', Tile("Inside_A5.png", 0, 3)); // Wood Wall
	addMapLayer(1, wall);

	// Interior Decorations
	GameLevel::MapLayer* dec = new GameLevel::MapLayer(this);
	dec->mapAddRow("                         "); // Row 1
	dec->mapAddRow(" a  464    282    464  a "); // Row 2
	dec->mapAddRow("   a575    393 a  575    "); // Row 3
	dec->mapAddRow("                         "); // Row 4
	dec->mapAddRow("                         "); // Row 5
	dec->mapAddRow("                         "); // Row 6
	dec->mapAddRow("                         "); // Row 7
	dec->mapAddRow("                         "); // Row 8
	dec->mapAddRow("                         "); // Row 9
	dec->mapAddRow("   a            a        "); // Row 10
	dec->mapAddRow("                      a  "); // Row 11
	dec->mapAddRow("               100       "); // Row 12
	dec->mapAddRow(" 000           100   011 "); // Row 13
	dec->mapAddRow(" 010   111           110 "); // Row 14
	dec->mapAddRow("       011               "); // Row 15
	dec->mapAddRow("                         "); // Row 16
	dec->mapAddRow("          a         a    "); // Row 17
	dec->mapAddRow("  a     a              a "); // Row 18
	dec->mapAddRow("                         "); // Row 19
	dec->mapAddRow("                         "); // Row 20
	dec->mapAddRow("                         "); // Row 21
	dec->mapAddRow("                         "); // Row 22
	dec->mapAddRow("                         "); // Row 23
	dec->mapAddRow("                         "); // Row 24
	dec->mapAddRow("                         "); // Row 25

	// No Decoration
	dec->addCharTileMapping(' ', Tile("Inside_A5.png", 0, 1));   // Default

	// Barrels and Jars
	dec->addCharTileMapping('0', Tile("Inside_B.png", 10, 9));   // Jar
	dec->addCharTileMapping('1', Tile("Inside_B.png", 10, 10));  // Barrel

	// Curtains
	dec->addCharTileMapping('2', Tile("Inside_B.png", 12, 2));  // Long Upper
	dec->addCharTileMapping('3', Tile("Inside_B.png", 12, 3));  // Long Lower
	dec->addCharTileMapping('4', Tile("Inside_B.png", 13, 2));  // Short Upper
	dec->addCharTileMapping('5', Tile("Inside_B.png", 13, 3));  // Short Lower

	// Holes in the Wall
	dec->addCharTileMapping('6', Tile("Inside_B.png", 13, 12));  // Long Upper
	dec->addCharTileMapping('7', Tile("Inside_B.png", 13, 13));  // Long Lower
	dec->addCharTileMapping('8', Tile("Inside_B.png", 14, 12));  // Big Upper
	dec->addCharTileMapping('9', Tile("Inside_B.png", 14, 13));  // Big Lower
	dec->addCharTileMapping('a', Tile("Inside_B.png", 15, 12));  // Bad Wall

	addMapLayer(2, dec);

    Entity* character = Entity::builder()
        .ofTexture("Graphics/Characters/Char3.png")
        .ofDirection(Direction::MoveDown)
        .atLocation(-0.6, 0.6)
        .build();

    character->setKillFunction([this, character]() {
        character->setTexture("Graphics/Characters/Char3-damaged.png");
    });

    setPlayerCharacter(character);
    pushAnimatedShapeToBack(character);
    pushShapeToBack(character);

    setMiceGenerator(this, spawnPoints);
}

Map01::~Map01() {}