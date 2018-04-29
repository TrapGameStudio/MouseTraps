#include "DemoSceen.h"
#include <stdio.h>


void DemoSceen::keyPress(unsigned char key) {}

void DemoSceen::keyUp(unsigned char key) {}

void DemoSceen::mouseDown(float x, float y) {
    clickClickables(x, y);
}

void DemoSceen::mouseUp(float x, float y) {}


DemoSceen::DemoSceen() : Scene::Scene() {

    // Preloading texture for faster render
    TextureManager::getTextureID("Graphics/Animations/fireball.png");
    TextureManager::getTextureID("Graphics/Images/mushroom.png");

    Button<TextureRect>* mushroom = Button<TextureRect>::builder()
        .ofShape(
            TextureRect::builder()
            .ofSize(0.5f, 0.5f)
            .onAnchor(Anchor::Center)
            .ofTexture("Graphics/Images/mushroom.png")
            .build()
        )
        .build();

        mushroom->onClickMouseDown([mushroom]() {
            mushroom->getShape()
                ->setTexture("Graphics/Animations/fireball.png");
            mushroom->getShape()
                ->setColumnRow(6, 6);
            mushroom->getShape()
                ->setTextureType(TextureType::Animation);
            mushroom->getShape()
                ->updateTextureInfo();
        });

    pushAnimatedShapesToBack(mushroom->getShape());
    pushClickableToBack(mushroom);
    pushShapeToBack(mushroom);

	TextureRect* temp = TextureRect::builder().atLocation(-1.0, 1.0)
		.ofShade(Color::blue())
		.ofTexture("Graphics/Images/mushroom.png")
		.ofSize(0.5, 0.5)
		.build();

	pushAnimatedShapesToBack(temp);
	pushShapeToBack(temp);
}

DemoSceen::~DemoSceen() {}