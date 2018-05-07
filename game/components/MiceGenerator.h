#pragma once
#include "game/components/Entity.h"
#include "gui/geom/Point.h"
#include "gui/components/Scene.h"
#include "gui/components/GameLevel.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//class Counter;
//struct State;

class MiceGenerator {
public:
	class Counter;
	struct State;
private:
	std::vector<Entity*> mice;
	std::vector<State*> states;
	std::vector<MiceGenerator::Counter*> counters;
	unsigned int count;
	Point* spawnLocations[4];
public:
	MiceGenerator();

	Entity* accessMouse(int i);
	void moveMice();
	void killMouse(int);
	void addSpawnLocation(Point* spawnLocation); // TODO: use Point
	void spawnMouse(Point* spawnLocation);		 // TODO
	void spawnMouse(float x, float y);
	void updateMice();

	void addCounter(Counter * count);
	void addCounter(unsigned int duration); // TODO

	~MiceGenerator();
};

class MiceGenerator::Counter {
private:
	bool expired = false;
	bool repeating = false;
	unsigned int duration = 0;
	unsigned int remainingTicks = 0;
	std::function<void(void)> execution;
	void reset();
public:
	MiceGenerator::Counter(unsigned int duration, std::function<void(void)> executable, bool repeating = false);
	MiceGenerator::Counter(unsigned int duration);
	void tick();
	bool isExpired();
};

struct MiceGenerator::State {
	Point* location;
	Direction direction;
	MiceGenerator::Counter * counter;

	MiceGenerator::State(Point* location, Direction direction, MiceGenerator::Counter * counter) {
		this->location = location;
		this->direction = direction;
		this->counter = counter;
	}

	void newState(unsigned int duration, Direction direction) {
		this->counter = new MiceGenerator::Counter(duration);
		this->direction = direction;
	}
};
