#pragma once
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "lib/lodepng.h"
#include <unordered_map>
#include <iostream>
#include <string>
class TextureManager {
private:
    static std::unordered_map<std::string, GLuint> textures;
    static GLuint addTexture(const char* filename);
public:
    static GLuint getTextureID(const char* filename, bool checkOnly = false);
};

