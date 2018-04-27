#include "TextureManager.h"

std::unordered_map<std::string, GLuint> TextureManager::textures;

GLuint TextureManager::addTexture(const char * filename) {
    GLuint texture_id = SOIL_load_OGL_texture
    (
        filename,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
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
