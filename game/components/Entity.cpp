#include "Entity.h"



Entity::Entity() {}


Entity::~Entity() {
    delete shape;
}

Entity::Builder Entity::builder() {
    return Entity::Builder();
}

void Entity::move(Direction movingDirection) {
    switch (movingDirection) {
    case Direction::MoveUp:
        shape->setCurrentRow(0);
        shape->move(0.0f, speed);
        break;
    case Direction::MoveLeft:
        shape->setCurrentRow(1);
        shape->move(-speed, 0.0f);
        break;
    case Direction::MoveRight:
        shape->setCurrentRow(2);
        shape->move(speed, 0.0f);
        break;
    case Direction::MoveDown:
        shape->setCurrentRow(3);
        shape->move(0.0f, -speed);
        break;
    }
}

void Entity::setLocation(float x, float y) {
    shape->setAnchorLocation(x, y);
}

TextureRect * Entity::getShape() {
    return shape;
}

/// <summary>
/// Setting the texture of the <see cref="TextureRect"/> this entity uses.
/// </summary>
/// <param name="textureFileName">full path to the texture file</param>
void Entity::setTexture(std::string textureFileName) {
    shape->setTexture(textureFileName.c_str()); // TODO: why const char*
}

void Entity::setTextureType(TextureType textureType) {
    shape->setTextureType(textureType);
}

void Entity::setAnimationRefreshRate(int animationRefreshRate) {
    if (animationRefreshRate > 0) {
        this->animationRefreshRate = animationRefreshRate;
    }
}

// TODO: static frame (resting frame) has been hard coded.
//void Entity::setStaticFrame(int frameNumber) {}

void Entity::setSpeed(float speed) {
    if (speed < 0) {
        this->speed = 0;
    } else {
        this->speed = speed;
    }
}

float Entity::getSpeed(float speed) {
    return this->speed;
}

void Entity::changSpeed(float deltaSpeed) {
    setSpeed(speed + deltaSpeed);
}

void Entity::draw() {
    shape->draw();
}

void Entity::advance() {
    if (movingDirection != Direction::Resting) {
        if (frameCounter == animationRefreshRate - 1) {
            if (shape->getCurrentColumn() == 0) {
                shape->setCurrentColumn(2);
            } else if (shape->getCurrentColumn() == 2) {
                shape->setCurrentColumn(0);
            }
            frameCounter = 0;
        }
        frameCounter++;
    }
}

Entity::Builder & Entity::Builder::ofTexture(std::string textureFileName) {
    building->setTexture(textureFileName);
    return *this;
}

Entity::Builder & Entity::Builder::ofTextureType(TextureType textureType) {
    building->setTextureType(textureType);
    return *this;
}

Entity::Builder & Entity::Builder::ofAnimationRefreshRate(int animationRefreshRate) {
    building->setAnimationRefreshRate(animationRefreshRate);
    return *this;
}

Entity::Builder & Entity::Builder::atLocation(float x, float y) {
    building->setLocation(x, y);
    return *this;
}

Entity::Builder & Entity::Builder::ofDirection(Direction direction) {
    if (direction == Direction::Resting) {
        building->shape->setCurrentRow(0);
    } else {
        switch (direction) {
        case Direction::MoveUp:
            building->shape->setCurrentRow(0);
            break;
        case Direction::MoveLeft:
            building->shape->setCurrentRow(1);
            break;
        case Direction::MoveRight:
            building->shape->setCurrentRow(2);
            break;
        case Direction::MoveDown:
            building->shape->setCurrentRow(3);
            break;
        }
    }
    return *this;
}

Entity::Builder & Entity::Builder::ofStaticFrame(int frameNumber) {
    return *this;
}

Entity * Entity::Builder::build() {
    return building;
}