#pragma once

#include "../lang/Direction.h"
#include "game\GameConfig.h"
#include "../../gui/components/TextureRect.h"
#include "../../gui/lang/Drawable.h"
#include "../../gui/lang/Animatable.h"
#include <string>
#include <functional>

class Entity :
    public Drawable,
    public Animatable {
private:
    class Builder;
    /// <summary>
    /// Window coordinate distance to move per tick
    /// </summary>
    float speed = 0.04f / GameConfig::gridColumn;

    /// <summary>
    /// Spacing between each refresh in tick
    /// </summary>
    int animationRefreshRate = 25;

    /// <summary>
    /// Counter use to keep track of the refresh spacing.
    /// </summary>
    int frameCounter = 0;

    Direction movingDirection = Direction::Resting;

    /// <summary>
    /// Frame index of which the character is standing
    /// or the animated object is at a resting position
    /// </summary>
    int staticFrame = 1;

    std::function<void(void)> triggerFunction = nullptr;

    TextureRect* shape = 
        TextureRect::builder()
        .ofSize(2.3f / 25, 2.3f / 25)
        .ofTextureType(TextureType::CharacterSet)
        .onAnchor(Anchor::Bottom)
        .ofColumnRow(3, 4)
        .atFrame(1)
        .build();
public:
    static Entity::Builder builder();
    void move(Direction movingDirection);
    void turn(Direction movingDirection);
    void setLocation(float x, float y);
    Point* const getLocation();
    TextureRect* getShape();
    void setTexture(std::string textureFileName);
    void setTextureType(TextureType textureType);
    void setAnimationRefreshRate(int animationRefreshRate);
    //void setStaticFrame(int frameNumber);
    void setSpeed(float speed);
    float getSpeed();
    void changSpeed(float deltaSpeed);
    void draw();
    void advance();
    void rest();
    void setTriggerFunction(std::function<void(void)> triggerFunction);
    void trigger();
    Entity();
    ~Entity();
};

class Entity::Builder {
private:
    Entity * building = new Entity();
public:
    Entity::Builder & ofTexture(std::string textureFileName);
    Entity::Builder & ofTextureType(TextureType textureType);
    Entity::Builder & ofAnimationRefreshRate(int animationRefreshRate);
    Entity::Builder & atLocation(float x, float y);
	Entity::Builder & atLocation(Point* location);
    Entity::Builder & ofDirection(Direction direction);
    Entity::Builder & ofStaticFrame(int frameNumber);
    Entity::Builder & onTrigger(std::function<void(void)> triggerFunction);
    Entity * build();
};