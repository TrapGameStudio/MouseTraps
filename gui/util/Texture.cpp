#include "Texture.h"



Texture::Texture(const char* filename) {
	this->filename = filename;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage textureMap;
	if (textureMap.LoadBmpFile(filename)) {
		glGenTextures(1, &texture_id);
		glBindTexture(GL_TEXTURE_2D, texture_id);

		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureMap.GetNumCols(), textureMap.GetNumRows(),
						  GL_RGB, GL_UNSIGNED_BYTE, textureMap.ImageData());
		this->texture_id = texture_id;
	} else {

	}
}

GLuint Texture::getTextureID() {
	return texture_id;
}


Texture::~Texture() {}
