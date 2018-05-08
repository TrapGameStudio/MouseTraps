#pragma once
#include "gui/components/GameLevel.h"

class Map02 : public GameLevel {

public:
    std::vector<Point*> spawnPoints;
	Map02();
	~Map02();

};


