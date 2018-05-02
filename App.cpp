#include "App.h"

static App* singleton;



void refreshDisplay(int value){
    singleton->game->updateFrame();
    singleton->redraw();
    glutTimerFunc(20, refreshDisplay, value);
}


App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables

    singleton = this;
    mx = 0.0;
    my = 0.0;

    refreshDisplay(1);
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

    game->redraw();

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
}

void App::mouseUp(float x, float y) {
    // Update app state
    mx = x;
    my = y;

    game->mouseUp(x, y);
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
}

void App::specialKeyPress(int key) {
    if (key == 100) {
        game->leftArrowDown();
    }
    if (key == 101) {
        game->upArrowDown();
    }
    if (key == 102) {
        game->rightArrowDown();
    }
    if (key == 103) {
        game->downArrownDown();
    }
}

void App::specialKeyUp(int key) {
    if (key == 100) {
        game->leftArrowUp();
    }
    if (key == 101) {
        game->upArrowUp();
    }
    if (key == 102) {
        game->rightArrowUp();
    }
    if (key == 103) {
        game->downArrownUp();
    }
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
