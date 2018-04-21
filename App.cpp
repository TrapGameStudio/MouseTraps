#include "App.h"

static App* singleton;



void explode(int value){
    singleton->game->updateFrame();
    singleton->redraw();
    glutTimerFunc(20, explode, value);
}


App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables

    singleton = this;
    mx = 0.0;
    my = 0.0;

    //catbox = Button<TextureRect>::builder()
    //    .ofShape(
    //            TextureRect::builder()
    //                .ofSize(0.5f,0.5f)
    //                .onAnchor(Anchor::Center)
    //                .ofTexture("Graphics/Images/mushroom.png")
    //                .build()
    //            )
    //    .onMouseDown([this]() {
    //        catbox->getShape()
    //            ->setTexture("Graphics/Animations/fireball.png");
    //        catbox->getShape()
    //            ->setFrames(6, 6);
    //        catbox->getShape()
    //            ->setTextureType(TextureType::Animation);
    //        catbox->getShape()
    //                ->updateTextureInfo();
    //    })
    //    .build();

    //rect = Rect::builder()
    //        .ofSize(0.6f, 0.6f)
    //        .atLocation(0.8f, 0.8f)
    //        .ofColor(Color::of(0.0f, 0.6f, 0.8f, 0.5f))
    //        .onAnchor(Anchor::Center)
    //        .build();

    //text = TextureRect::builder()
    //        .ofSize(0.33f * 0.2f, 0.70f * 0.2f)
    //        .atLocation(-0.8f, 0.8f)
    //        .ofTexture("Graphics/fonts/Consolas.png")
    //        .ofTextureType(TextureType::LoopedAnimation)
    //        .ofColumnRow(16, 14)
    //        .ofShade(Color::white())
    //        .onAnchor(Anchor::Center)
    //        .build();

    //background = TextureRect::builder()
    //        .ofSize(2.0f, 2.0f)
    //        .ofShade(Color::white())
    //        .onAnchor(Anchor::Center)
    //        .ofTexture("Graphics/Images/Castle1.png")
    //        .build();

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
    //background->draw();
    //catbox->draw();
    //rect->draw();
    //text->draw();
    game->redraw();
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

    game->mouseDown(x, y);

    // Redraw the scene
    redraw();
}

void App::mouseUp(float x, float y) {
    // Update app state
    mx = x;
    my = y;

    game->mouseUp(x, y);

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

//void App::idle(){
//
//}

void App::keyUp(unsigned char key) {

    game->keyUp(key);

}

void App::keyPress(unsigned char key) {

    game->keyPress(key);

    if (key == 27){
        // Exit the app when Esc key is pressed
        delete game;
        //delete background;
        //delete rect;

        exit(0);
    }
}
