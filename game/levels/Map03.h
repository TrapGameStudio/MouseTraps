#pragma once
#include "gui/components/GameLevel.h"

class Map03 : public GameLevel {
public:
	MiceGenerator * mice = new MiceGenerator();
	Map03();
	~Map03();
};

