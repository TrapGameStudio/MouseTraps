#pragma once
#include "gui/components/GameLevel.h"
#include "gui/geom/Point.h"

class Map03 : public GameLevel {
public:
	std::vector<Point*> spawnPoints;
	Map03();
	~Map03();
};

