#include "App.h"

static App* singleton;



void explode(int value){
	singleton->expl->advance();
	singleton->mushroomThatExplodesWhenYouClickOnIt->getShape()->advance();
	singleton->redraw();
	glutTimerFunc(32, explode, value);
}


App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables

    singleton = this;
    mx = 0.0;
    my = 0.0;

	// Preloading texture for faster render
	TextureManager::getTextureID("Graphics/Animations/fireball.bmp");
	TextureManager::getTextureID("Graphics/Images/mushroom.bmp");

	mushroomThatExplodesWhenYouClickOnIt = Button<TextureRect>::builder()
		.ofShape(
				TextureRect::builder()
					.ofSize(0.5f, 0.5f)
					.onAnchor(Anchor::Center)
					.ofTexture("Graphics/Images/mushroom.bmp")
					.build()
				)
		.onMouseDown([this]() {
		mushroomThatExplodesWhenYouClickOnIt->getShape()
				->setTexture("Graphics/Animations/fireball.bmp")
				->setFrames(6, 6)
				->setTextureType(TextureType::Animation)
				->updateTextureInfo();
		})
		.build();

	rect = Rect::builder()
			.ofSize(0.01f, 0.01f)
			.atLocation(0.8f, 0.8f)
			.ofColor(Color::yellow())
			.onAnchor(Anchor::Center)
			.build();



	expl = TextureRect::builder()
			//.ofSize(0.5f, 0.5f)
			//.ofShade(Color::white())
			//.onAnchor(Anchor::Center)
			//.ofTexture("Graphics/Animations/explode.bmp")
			//.ofTextureType(TextureType::LoopedAnimation)
			//.ofFrames(5, 5)
			.build();

	//rect->zoom(2.0f);

	explode(1);
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set Color
    glColor3d(1.0, 1.0, 1.0);
	mushroomThatExplodesWhenYouClickOnIt->draw();
	expl->draw();
	rect->draw();

    //background->draw();

    glDisable(GL_TEXTURE_2D);

    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

	if (mushroomThatExplodesWhenYouClickOnIt->contains(x, y)) {
		mushroomThatExplodesWhenYouClickOnIt->clickMouseDown();
	}
    // Redraw the scene
    redraw();
}

void App::mouseUp(float x, float y) {
	// Update app state
	mx = x;
	my = y;

	// Redraw the scene
	redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;

    // Redraw the scene
    redraw();
}

void App::idle(){

}

void App::keyUp(unsigned char key) {

}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
		delete game;
		delete expl;
		delete rect;

        exit(0);
    }
}
