#include "TextureManager.h"

std::unordered_map<std::string, GLuint> TextureManager::textures;

GLuint TextureManager::addTexture(const char * filename) {
    GLuint texture_id = 0;
    std::vector<GLubyte> image; //the raw pixels
    unsigned width, height;

    //decode
    unsigned error = lodepng::decode(image, width, height, filename);

    //if there's an error, display it
    if (error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

    if (!error) {
        glEnable(GL_TEXTURE_2D);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glGenTextures(1, &texture_id);
        glBindTexture(GL_TEXTURE_2D, texture_id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
        gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height,
                          GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
        glDisable(GL_TEXTURE_2D);
    }
    return texture_id;
}

GLuint TextureManager::getTextureID(const char * filename, bool checkOnly) {
    GLuint id = 0;
    std::string filenameStr = filename;
    if (textures.find(filenameStr) == textures.end()) {
        if (!checkOnly) {
            id = addTexture(filename);
        }
        if (!id) {
            return 0;
        }
        textures[filenameStr] = id;
    }
    return textures[filenameStr];
}
