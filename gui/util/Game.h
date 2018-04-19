#pragma once
#include "gui/geom/Vector.h"
#include "gui/geom/Point.h"
#include "gui/components/Scene.h"
#include "gui/util/ScenePrototype.h"
#include <memory>
#include <deque>
#include <map>
class Game {
private:
	std::deque<std::unique_ptr<Scene>> currentScenes;
	std::map<unsigned int, std::unique_ptr<ScenePrototype>> gameLevels;
public:
	static const int GridColumn;
	static const int GridRow;
	static void gridCoordinatesToWindowCoordinates(float& x, float& y);
	static void gridCoordinatesToWindowCoordinates(Point* p);
	static void gridCoordinatesToWindowCoordinates(Vector* v);

	void mouseDown(float x, float y);
	void mouseUp(float x, float y);
	void keyUp(unsigned char key);
	void keyPress(unsigned char key);

	void redraw();

	void updateFrame();


	Game();
	~Game();
};

