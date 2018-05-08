#include "MiceGenerator.h"
#include <stdlib.h>

MiceGenerator::MiceGenerator() {}

MiceGenerator::MiceGenerator(std::vector<Point*> location, GameLevel* level) { //TODO: Accept a list of Points to use as spawn locations 
	for (Point* p : location) {
		addSpawnLocation(p);
	}

	for (Point* p : spawnLocations) {
		spawnMouse(p);
	}

	for (int i = 0; i < getCount(); i++) {
		level->pushAnimatedShapesToBack(mice[i]);
		level->pushShapeToBack(mice[i]);
	}

	this->level = level;
}

void MiceGenerator::spawnMouse(float x, float y) {
	
	State * state = new State();
	state = state->newState();

	Entity* mouse = Entity::builder()
		.ofTexture("Graphics/Characters/whtdragon7.png")
		.ofDirection(Direction::MoveDown)
		.atLocation(x, y)
		.build();

	mouse->getShape()->setSize(4.0f / 25, 4.0f / 25); //Size was too small
	states.push_back(state);
	mice.push_back(mouse);
	level->pushAnimatedShapesToBack(mouse);
	level->pushShapeToBack(mouse);
	miceCount++;
}

void MiceGenerator::spawnMouse(Point * spawnLocation) {

	State * state = new State();
	state = state->newState();
	

	Entity* mouse = Entity::builder()
		.ofTexture("Graphics/Characters/whtdragon7.png")
		.ofDirection(Direction::MoveDown)
		.atLocation(spawnLocation->getX(), spawnLocation->getY())
		.build();

	mouse->getShape()->setSize(4.0f / 25, 4.0f / 25); //Size was too small
	states.push_back(state);
	mice.push_back(mouse);
	//level->pushAnimatedShapesToBack(mice.back());
	//level->pushShapeToBack(mice.back());
	miceCount++;
}

void MiceGenerator::moveMice() {
	for (unsigned int i = 0; i < mice.size(); i++) {
		if (!states[i]->count) {
			states[i] = states[i]->newState();
		}
		Direction d = states[i]->direction;
		switch (d) {
		case Direction::MoveDown:
			if (!level->collideDown(mice[i])) {
				mice[i]->move(d);
			}
			else {
				states[i] = states[i]->newState();
			}
			break;
		case Direction::MoveLeft:
			if (!level->collideLeft(mice[i])) {
				mice[i]->move(d);
			}
			else {
				states[i] = states[i]->newState();
			}
			break;
		case Direction::MoveRight:
			if (!level->collideRight(mice[i])) {
				mice[i]->move(d);
			}
			else {
				states[i] = states[i]->newState();
			}
			break;
		case Direction::MoveUp:
			if (!level->collideUp(mice[i])) {
				mice[i]->move(d);
			}
			else {
				states[i] = states[i]->newState();
			}
			break;
		default:
			mice[i]->rest();
			break;
		}
		states[i]->count--;
	}

	if (!--spawnTimer) {
		resetSpawnTime();
		unsigned int i = rand() % spawnLocations.size();
		spawnMouse(spawnLocations[i]);
		level->pushAnimatedShapesToBack(mice.back());
		level->pushShapeToBack(mice.back());
	}
}

void MiceGenerator::resetSpawnTime() {
	spawnTimer = SPAWNTIME;
}

void MiceGenerator::killMouse(int i) { //Dont use this
	delete states[i];
	delete mice[i];
	miceCount--;
}

Entity* MiceGenerator::accessMouse(int i) {
	return mice[i];
}

MiceGenerator::State * MiceGenerator::accessState(int i) {
	return states[i];
}

unsigned int MiceGenerator::getCount() {
	return this->miceCount;
}

void MiceGenerator::addSpawnLocation(Point* spawnLocation) {
	for (int i = 0; i <= spawnLocations.size(); i++) {
		if (i == spawnLocations.size()) {
			spawnLocations.push_back(spawnLocation);
			break;
		}
		if (!spawnLocations[i])
			spawnLocations[i] = spawnLocation;
	}
}

void MiceGenerator::addSpawnLocation(float x, float y) {
	for (int i = 0; i <= spawnLocations.size(); i++) {
		if (i == spawnLocations.size()) {
			spawnLocations.push_back(new Point(x, y));
			break;
		}
		if (!spawnLocations[i])
			spawnLocations[i] = new Point(x, y);
	}
}

MiceGenerator::~MiceGenerator() {
	for (Point* p : spawnLocations)
		delete p;
	for (Entity* e : mice)
		delete e;
}
