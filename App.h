#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "gui/shapes/Rect.h"
#include "gui/components/TextureRect.h"
#include "gui/components/ComplexShape.h"
#include "gui/components/Button.h"
#include "gui/util/Game.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
	Game* game = new Game();

public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);

    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void keyUp(unsigned char key);
    void mouseDown(float x, float y);
	void mouseUp(float x, float y);
    void mouseDrag(float x, float y);
    void idle();



	//void resize(int w, int h);

	Rect * rect;
	TextureRect * expl;
	Button<TextureRect>* mushroomThatExplodesWhenYouClickOnIt;
    //TexRect* background;
};

#endif
