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

    //TextureRect* chara = TextureRect::builder()
    //    .ofTexture("Graphics/Characters/mouseTrapsChar.png")
    //    .ofTextureType(TextureType::Static)
    //    .ofTextureColumn(3)
    //    .ofTextureRow(4)
    //    .atFrame(1)
    //    .onAnchor(Anchor::Center)
    //    .ofSize(0.3, 0.3)
    //    .atLocation(0.8, 0.6)
    //    .build();

    //pushAnimatedShapesToBack(chara);
    //pushShapeToBack(chara);

    Entity* character = Entity::builder()
        .ofTexture("Graphics/Characters/mouseTrapsChar.png")
        .ofDirection(Direction::MoveDown)
        .atLocation(-0.4, 0.4)
        .build();

    pushAnimatedShapesToBack(character);
    pushShapeToBack(character);
}


DemoSceen::~DemoSceen() {}
