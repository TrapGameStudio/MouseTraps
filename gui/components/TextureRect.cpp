#include "TextureRect.h"



void TextureRect::updateTextureInfo() {
    if (textureColumn > 0 && textureRow > 0) {
        textureTileSize->setTo(1.0f / textureColumn, 1.0f / textureRow);
        currentTextureCoordinate->setTo(
            currentTextureColumn * textureTileSize->getX(),
             1 - (currentTextureRow * textureTileSize->getY()));
    }
}


TextureRect::TextureRect() : Rect::Rect() {}

TextureRect::TextureRect(
    std::string textureFileName,
    TextureType textureType,
    unsigned int textureColumn,
    unsigned int textureRow,
    Vector * size,
    Anchor anchor,
    Point * anchorLocation,
    Color * color) :
    Rect::Rect(
        size,
        anchor,
        anchorLocation,
        color) {

    this->textureFileName = textureFileName;
    this->textureType = textureType;
    this->textureColumn = textureColumn;
    this->textureRow = textureRow;
    updateTextureInfo();
}


TextureRect::~TextureRect() {}

TextureRect::Builder TextureRect::builder() {
    return TextureRect::Builder();
}

TextureRect * TextureRect::setColor(Color * color) {
    Rect::setColor(color);
    return this;
}

TextureRect * TextureRect::setTexture(const char* textureFileName) {
    this->textureFileName = textureFileName;
    textureID = 0;	// Force the program to get a new textureID
    updateTextureInfo();
    return this;
}

TextureRect * TextureRect::setTextureType(TextureType textureType) {
    this->textureType = textureType;
    return this;
}

TextureRect * TextureRect::setTextureColumn(unsigned int textureColumn) {
    this->textureColumn = textureColumn;
    return this;
}

TextureRect * TextureRect::setTextureRow(unsigned int textureRow) {
    this->textureRow = textureRow;
    return this;
}

TextureRect * TextureRect::setFrames(unsigned int textureColumn, unsigned int textureRow) {
    this->textureColumn = textureColumn;
    this->textureRow = textureRow;
    return this;
}

void TextureRect::draw() {
    if (!textureID) {
        textureID = TextureManager::getTextureID(textureFileName.c_str());

    }
    if (textureID) {
        glBindTexture(GL_TEXTURE_2D, textureID);
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    }
    glColor4f(
        color->getR(),
        color->getG(),
        color->getB(),
        color->getA()
    );

    glBegin(GL_QUADS);
    glTexCoord2f(currentTextureCoordinate->getX(),
                 currentTextureCoordinate->getY());
    glVertex2f(topLeft->getX(), topLeft->getY());

    glTexCoord2f(currentTextureCoordinate->getX() + textureTileSize->getX(),
                 currentTextureCoordinate->getY());
    glVertex2f(topLeft->getX() + absoluteSize->getX(), topLeft->getY());

    glTexCoord2f(currentTextureCoordinate->getX() + textureTileSize->getX(),
                 currentTextureCoordinate->getY() - textureTileSize->getY());
    glVertex2f(topLeft->getX() + absoluteSize->getX(), topLeft->getY() - absoluteSize->getY());

    glTexCoord2f(currentTextureCoordinate->getX(),
                 currentTextureCoordinate->getY() - textureTileSize->getY());
    glVertex2f(topLeft->getX(), topLeft->getY() - absoluteSize->getY());
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void TextureRect::advance() {
    switch (textureType) {
    case TextureType::Test:
        currentTextureColumn = 1;
        currentTextureRow = 1;
        break;
    case TextureType::CharacterSet:
        currentTextureColumn = (currentTextureColumn + 1) % textureColumn;
        updateTextureInfo();
        break;
    case TextureType::Animation:
        if (textureColumn - 1 == currentTextureColumn && textureRow - 1 == currentTextureRow) {
            break;
        }
    case TextureType::LoopedAnimation:
        if (!(currentTextureColumn = (currentTextureColumn + 1) % textureColumn)) {
            currentTextureRow = (currentTextureRow + 1) % textureRow;
        }

    }
    updateTextureInfo();
}



TextureRect::Builder & TextureRect::Builder::ofSize(Vector* size) {
    delete building->size;
    building->size = size;
    return *this;
}


TextureRect::Builder & TextureRect::Builder::ofSize(float x, float y) {
    building->size->setTo(x, y);
    return *this;
}


TextureRect::Builder & TextureRect::Builder::atLocation(float x, float y) {
    building->anchorLocation->setTo(x, y);
    return *this;
}


TextureRect::Builder & TextureRect::Builder::atLocation(Point * anchorLocation) {
    delete building->anchorLocation;
    building->anchorLocation = anchorLocation;
    return *this;
}


TextureRect::Builder & TextureRect::Builder::onAnchor(Anchor anchor) {
    building->anchor = anchor;
    return *this;
}


TextureRect::Builder & TextureRect::Builder::ofShade(Color * color) {
    delete building->color;
    building->color = color;
    return *this;
}

TextureRect::Builder & TextureRect::Builder::ofTexture(const char * textureFileName) {
    building->setTexture(textureFileName);
    return *this;
}

TextureRect::Builder & TextureRect::Builder::ofTextureType(TextureType textureType) {
    building->setTextureType(textureType);
    return *this;
}

TextureRect::Builder & TextureRect::Builder::ofTextureColumn(unsigned int textureColumn) {
    building->setTextureColumn(textureColumn);
    return *this;
}

TextureRect::Builder & TextureRect::Builder::ofTextureRow(unsigned int textureRow) {
    building->setTextureRow(textureRow);
    return *this;
}

TextureRect::Builder & TextureRect::Builder::ofFrames(unsigned int textureColumn, unsigned int textureRow) {
    building->setFrames(textureColumn, textureRow);
    return *this;
}


TextureRect * TextureRect::Builder::build() {
    building->updateAbsoluteRepresentation();
    building->updateTextureInfo();
    return building;
}

TextureRect::Builder::~Builder() {}
