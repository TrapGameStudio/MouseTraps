#include "MiceGenerator.h"
#include <stdlib.h>

MiceGenerator::MiceGenerator() {}

MiceGenerator::MiceGenerator(std::vector<Point*> location, GameLevel* level) { //TODO: Accept a list of Points to use as spawn locations 
    for (Point* p : location) {
        addSpawnLocation(p);
    }
    // due to some issue with the entity queue not being initilized when these are called,
    // I need to comment these out for the program to work

    //for (Point* p : spawnLocations) {
    //    spawnMouse(p);
    //}

    //for (int i = 0; i < getCount(); i++) {
    //    level->removeShape(level->getPlayer());
    //    level->pushAnimatedShapeToBack(mice[i]);
    //    level->pushShapeToBack(mice[i]);
    //    level->pushShapeToBack(level->getPlayer());
    //}

    this->level = level;
}

void MiceGenerator::spawnMouse(float x, float y) {
    
    State * state = new State();
    state = state->newState();

    Entity* mouse = Entity::builder()
        .ofTexture("Graphics/Characters/whtdragon7.png")
        .ofDirection(Direction::MoveDown)
        .atLocation(x, y)
        .ofStaticFrame(0)
        .build();

    // turn mice into bbq charcoal mice when bombed
   /* mouse->setKillFunction([this, mouse]() {
        mouse->setTexture("Graphics/Characters/whtdragon3.png");
        mice.remove(mouse);
        states.erase(mouse);
        level->addTimer(25, [this, mouse]() {
            level->removeShape(mouse);
            level->removeAnimatedShape(mouse);
            miceCount--;
        });
    });
	*/
    level->addEntity(mouse);

    mouse->getShape()->setSize(3.0f / 25, 3.0f / 25); //Size was too small
    states[mouse] = state;
    mice.push_back(mouse);

    //level->pushAnimatedShapeToBack(mice.back());  // didn't understand why not pushing here
    //level->pushShapeToBack(mice.back());

    level->removeShape(level->getPlayer());
    level->pushAnimatedShapeToBack(mouse);
    level->pushShapeToBack(mouse);
    level->pushShapeToBack(level->getPlayer());


    miceCount++;
}

void MiceGenerator::spawnMouse(Point * spawnLocation) {
    spawnMouse(spawnLocation->getX(), spawnLocation->getY());
}

void MiceGenerator::moveMice() {
    for (auto& ep : mice.getMap()) {
        Entity* e = ep.second;
        if (!states[e]->count) {
            states[e] = states[e]->newState();
        }
        Direction d = states[e]->direction;
        switch (d) {
        case Direction::MoveDown:
            if (!level->collideDown(e)) {
                e->move(d);
            } else {
                states[e] = states[e]->newState();
            }
            break;
        case Direction::MoveLeft:
            if (!level->collideLeft(e)) {
                e->move(d);
            } else {
                states[e] = states[e]->newState();
            }
            break;
        case Direction::MoveRight:
            if (!level->collideRight(e)) {
                e->move(d);
            } else {
                states[e] = states[e]->newState();
            }
            break;
        case Direction::MoveUp:
            if (!level->collideUp(e)) {
                e->move(d);
            } else {
                states[e] = states[e]->newState();
            }
            break;
        default:
            e->rest();
            break;
        }
        states[e]->count--;
    }

    if (!--spawnTimer) {
        resetSpawnTime();
        unsigned int i = rand() % spawnLocations.size();
        spawnMouse(spawnLocations[i]);
        //level->removeShape(level->getPlayer());
        //level->pushAnimatedShapeToBack(mice.back());
        //level->pushShapeToBack(mice.back());
        //level->pushShapeToBack(level->getPlayer());
    }
}

void MiceGenerator::resetSpawnTime() {
    spawnTimer = SPAWNTIME;
}

void MiceGenerator::killMouse(Entity* e) { //Dont use this
    delete states[e];
    states.erase(e);
    mice.remove(e);
    delete e;
    miceCount--;
}

//Entity* MiceGenerator::accessMouse(int i) {
//    return mice[i];
//}

MiceGenerator::State * MiceGenerator::accessState(Entity* e) {
    return states[e];
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
    //for (Entity* e : mice)
    //    delete e;
}
