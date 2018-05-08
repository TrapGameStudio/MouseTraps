#pragma once
#include "game/components/Entity.h"
#include "gui/geom/Point.h"
#include "gui/components/Scene.h"
#include "gui/components/GameLevel.h"
#include <stdio.h>
#include <time.h>

class GameLevel;

class MiceGenerator {
public:
	struct State;
private:
	std::vector<Entity*> mice;
	std::vector<State*> states;
	std::vector<Point*> spawnLocations;
	unsigned int miceCount = 0, spawnTime = 1000;
	GameLevel* level;
public:
	MiceGenerator();
	MiceGenerator(GameLevel* level);

	Entity* accessMouse(int i);
	MiceGenerator::State* accessState(int i);
	unsigned int getCount();
	void resetSpawnTime();
	void moveMice();
	void addSpawnLocation(Point* spawnLocation); // TODO: use Point
	void addSpawnLocation(float x, float y);
	void spawnMouse();
	void spawnMouse(Point* spawnLocation);		 // TODO
	void spawnMouse(float x, float y);
	void killMouse(int m);

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
