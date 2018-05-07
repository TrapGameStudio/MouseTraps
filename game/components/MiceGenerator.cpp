#include "MiceGenerator.h"

MiceGenerator::MiceGenerator() {
	spawnMouse(-0.6f, 0.6);
	spawnMouse(0.0f, 0.0f);
	spawnMouse(0.0f, 0.5f);
	spawnMouse(0.4f, -0.6f);
	spawnMouse(-0.7f, -0.7f);
}


void MiceGenerator::spawnMouse(float x, float y) {
	Entity* mouse = Entity::builder()
		.ofTexture("Graphics/Characters/whtdragon7.png")
		.ofDirection(Direction::MoveDown)
		.atLocation(x, y)
		.build();

	mouse->getShape()->setSize(4.0f / 25, 4.0f / 25); //Size was too small
	states.push_back(new State(mouse->getLocation(), Direction::MoveDown, new Counter(100)));
	mice.push_back(mouse);
}

void MiceGenerator::moveMice(void) {
	// TODO: One function that is clled by the Timer and used to control all mice.
	// Change the state of each mouse (randomly) only if the Timer has run out. 
	for (int i = 0; i < mice.size(); i++) {
		mice[i]->move(states[i]->direction);
		if (states[i]->counter->isExpired()) {
			states[i]->newState(50, Direction::MoveRight);
			mice[i]->move(states[i]->direction);
		}
		else {
			mice[i]->move(states[i]->direction);
		}
//		for (auto& sh : )
	}
}

void MiceGenerator::killMouse(int i) {
	delete states[i];
	delete mice[i];
}

Entity* MiceGenerator::accessMouse(int i) {
	return mice[i];
}

void MiceGenerator::addSpawnLocation(Point* spawnLocation) {
	for (int i = 0; i < 4; i++) {
		if (!spawnLocations[i])
			spawnLocations[i] = spawnLocation;
	}
}

void MiceGenerator::addCounter(MiceGenerator::Counter * counter) {
	counters.push_back(counter);
}

void MiceGenerator::addCounter(unsigned int duration) {
	counters.push_back(new Counter(duration, NULL));
}

MiceGenerator::~MiceGenerator() {
	for (Point* p : spawnLocations)
		delete p;
	for (Entity* e : mice)
		delete e;
}

void MiceGenerator::Counter::reset() {
	remainingTicks = duration;
}


MiceGenerator::Counter::Counter(unsigned int duration, std::function<void(void)> executable, bool repeating) {
	if (duration) {
		this->remainingTicks = duration;
		this->execution = executable;
	}
	else {
		expired = true;
	}
}

MiceGenerator::Counter::Counter(unsigned int duration) {
	if (duration) {
		this->remainingTicks = duration;
		this->execution = execution;
	}
	else {
		expired = true;
	}
}

void MiceGenerator::Counter::tick() {
	if (!expired && !--remainingTicks) {
		if (execution) {
			execution();
			if (repeating) {
				reset();
			}
			else {
				expired = true;
			}
		}
	}
}

bool MiceGenerator::Counter::isExpired() {
	return expired;
}

