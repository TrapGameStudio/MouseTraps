#pragma once
#include "../lang/Direction.h"
#include "../../gui/components/TextureRect.h"
#include "../../gui/lang/Drawable.h"
#include "../../gui/lang/Animatable.h"
#include <string>
class Entity :
    public Drawable,
    public Animatable {
private:
    class Builder;
    /// <summary>
    /// Window coordinate distance to move per tick
    /// </summary>
    float speed = 0.04f;

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

    TextureRect* shape = 
        TextureRect::builder()
        .ofSize(2.0f / 25, 2.0f / 25)
        .ofTextureType(TextureType::CharacterSet)
        .ofColumnRow(3, 4)
        .atFrame(1)
        .build();
public:
    static Entity::Builder builder();
    void move(Direction movingDirection);
    void setLocation(float x, float y);
    TextureRect* getShape();
    void setTexture(std::string textureFileName);
    void setTextureType(TextureType textureType);
    void setAnimationRefreshRate(int animationRefreshRate);
    //void setStaticFrame(int frameNumber);
    void setSpeed(float speed);
    float getSpeed(float speed);
    void changSpeed(float deltaSpeed);
    void draw();
    void advance();
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
    Entity::Builder & ofDirection(Direction direction);
    Entity::Builder & ofStaticFrame(int frameNumber);
    Entity * build();
};