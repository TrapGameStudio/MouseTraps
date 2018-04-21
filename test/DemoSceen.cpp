#include "DemoSceen.h"
#include <stdio.h>


void DemoSceen::keyPress(unsigned char key) {}

void DemoSceen::keyUp(unsigned char key) {}

void DemoSceen::mouseDown(float x, float y) {
    clickClickables();
}

void DemoSceen::mouseUp(float x, float y) {}


DemoSceen::DemoSceen() : Scene::Scene() {
    // Preloading texture for faster render

    TextureManager::getTextureID("Graphics/Animations/fireball.png");
    TextureManager::getTextureID("Graphics/Images/mushroom.png");

    mushroom = Button<TextureRect>::builder()
        .ofShape(
            TextureRect::builder()
            .ofSize(0.5f, 0.5f)
            .onAnchor(Anchor::Center)
            .ofTexture("Graphics/Images/mushroom.png")
            .build()
        )
        .onMouseDown([this]() {
            mushroom->getShape()
                ->setTexture("Graphics/Animations/fireball.png");
            mushroom->getShape()
                ->setFrames(6, 6);
            mushroom->getShape()
                ->setTextureType(TextureType::Animation);
            mushroom->getShape()
                ->updateTextureInfo();
        })
        .build();

        pushAnimatedShapesToBack(mushroom->getShape());
        pushClickableToBack(mushroom);
        pushShapeToBack(mushroom);
}


DemoSceen::~DemoSceen() {}
