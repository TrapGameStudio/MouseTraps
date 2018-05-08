#pragma once
#include "gui/components/GameLevel.h"
class Map01 :
	public GameLevel {
private:
    std::vector<Point*> spawnPoints;
public:
	Map01();
	~Map01();
};

