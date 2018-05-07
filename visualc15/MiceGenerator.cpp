#include "MiceGenerator.h"



MiceGenerator::MiceGenerator() {
	addSpawnLocation(new Point(-0.3f, 0.0f));
	spawnMouse(spawnLocations[0]);
}


void MiceGenerator::spawnMouse(Point* spawnLocation) {
	Entity* mouse = Entity::builder()
		.ofTexture("Graphics/Characters/whtdragon7.png")
		.ofDirection(Direction::MoveDown)
		.atLocation(spawnLocation)
		.build();

	mice.push_back(mouse);
}

void MiceGenerator::addSpawnLocation(Point* spawnLocation) {
	for (int i = 0; i < 4; i++) {
		if (!spawnLocations[i])
			spawnLocations[i] = spawnLocation;
	}
}

MiceGenerator::~MiceGenerator()
{
}
