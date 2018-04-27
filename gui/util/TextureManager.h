#pragma once
#if defined WIN32
#include <freeglut.h>
#include "../../lib/WindowsSOIL/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
#endif


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

