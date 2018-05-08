#include "game/components/Entity.h"
#include "gui/geom/Point.h"
#include "gui/components/GameLevel.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


class MiceGenerator {
	std::vector<Entity*> mice;
	Point* spawnLocations[4];

public:
	MiceGenerator();

	void addSpawnLocation(Point* spawnLocation);
	void spawnMouse(Point* spawnLoation);


	~MiceGenerator();
};

