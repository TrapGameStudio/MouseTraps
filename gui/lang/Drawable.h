#pragma once

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class Drawable {
public:
	virtual void draw() = 0;
	virtual ~Drawable() = 0;
};

inline Drawable::~Drawable() {}
