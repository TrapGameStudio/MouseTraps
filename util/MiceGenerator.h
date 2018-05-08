#pragma once
#include "game/components/Entity.h"
#include "gui/geom/Point.h"
#include "gui/components/Scene.h"
#include "gui/components/GameLevel.h"
#include "gui/util/SearchableQueue.h"
#include <unordered_map>
#include <stdio.h>
#include <time.h>

class GameLevel;

class MiceGenerator {
public:
	struct State;
private:
	SearchableQueue<Entity*> mice;
	std::unordered_map<Entity*, State*> states;
	std::vector<Point*> spawnLocations;
	const unsigned int SPAWNTIME = 300, MAX_MICE = 25;
	unsigned int miceCount = 0, totalSpawned = 0, spawnTimer = SPAWNTIME;
	bool generate = true, control = true;
	GameLevel* level;
public:
	MiceGenerator();
	MiceGenerator(std::vector<Point*> locations, GameLevel* level);

	//Entity* accessMouse(int i);
	//MiceGenerator::State* accessState(Entity* e);
	//unsigned int getCount();
	void resetSpawnTime();
	void moveMice();
	void addSpawnLocation(Point* spawnLocation); // TODO: use Point
	void addSpawnLocation(float x, float y);
	//void spawnMouse();
	void spawnMouse(Point* spawnLocation);		 // TODO
	void spawnMouse(float x, float y);
	void killMouse(Entity* e);
	//bool isGenerating();
	void stopGenerator();
		
	~MiceGenerator();
};

struct MiceGenerator::State {
	Point* location;
	Direction direction;
	unsigned int count;

	MiceGenerator::State() {
		this->location = location;
		this->direction = direction;
		this->count = 0;
	}

	MiceGenerator::State(Point* location, Direction direction, unsigned int count) {
		this->location = location;
		this->direction = direction;
		this->count = count;
	}

	MiceGenerator::State * newState() {
		unsigned int steps, dir;

		steps = rand() % 250 + 10;
		rand(); dir = rand() % 5;

		return new MiceGenerator::State(this->location, Direction(dir), steps);
	}
};
