#pragma once
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.h"
#include <string>
class Texture {
    std::string filename;
    GLuint texture_id;
public:
    Texture(const char* filename);
    GLuint getTextureID();
    ~Texture();
};

