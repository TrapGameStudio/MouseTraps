#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include "gui/util/Texture.h"
class TextureManager {
private:
	static std::unordered_map<std::string, GLuint> textures;
public:
	static GLuint getTextureID(const char* filename) {
		std::string filenameStr = filename;
		if (textures.find(filenameStr) == textures.end()) {
			GLuint id = Texture(filename).getTextureID();
			if (!id) {
				return 0;
			}
			textures[filenameStr] = Texture(filename).getTextureID();
		}
		return textures[filenameStr];
	}
};

