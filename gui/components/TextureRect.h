#pragma once
#include <string>
#include "gui/shapes/Rect.h"
#include "gui/util/TextureManager.h"
#include "gui/lang/TextureType.h"
class TextureRect :
    public Rect {
private:
    GLuint textureID = 0;
    std::string textureFileName;
    TextureType textureType = TextureType::Static;
    Vector * textureTileSize = new Vector(1.0f, 1.0f);
    unsigned int textureColumn = 1;
    unsigned int textureRow = 1;
    unsigned int currentTextureColumn = 0;
    unsigned int currentTextureRow = 0;
    Point * currentTextureCoordinate = new Point(0.0f, 0.0f);
    TextureRect();
public:
    TextureRect(
        std::string textureFileName,
        TextureType textureType,
        unsigned int textureColumn,
        unsigned int textureRow,
        Vector* size,
        Anchor anchor,
        Point* anchorLocation,
        Color* color = Color::white());
    class Builder;
    ~TextureRect();
    static TextureRect::Builder builder();
    TextureRect* setColor(Color* color);
    TextureRect* setTexture(const char* textureFileName);
    TextureRect* setTextureType(TextureType textureType);
    TextureRect* setTextureColumn(unsigned int textureColumn);
    TextureRect* setTextureRow(unsigned int textureRow);
    TextureRect* setFrames(unsigned int textureColumn, unsigned int textureRow);
    void updateTextureInfo();
    void draw();
    void advance();
};

class TextureRect::Builder {
private:
    TextureRect * building = new TextureRect();
public:
    TextureRect::Builder& ofSize(Vector* size);
    TextureRect::Builder& ofSize(float x, float y);
    TextureRect::Builder& atLocation(float x, float y);
    TextureRect::Builder& atLocation(Point* anchorLocation);
    TextureRect::Builder& onAnchor(Anchor anchor);
    TextureRect::Builder& ofShade(Color* color);
    TextureRect::Builder& ofTexture(const char* textureFileName);
    TextureRect::Builder& ofTextureType(TextureType textureType);
    TextureRect::Builder& ofTextureColumn(unsigned int textureColumn);
    TextureRect::Builder& ofTextureRow(unsigned int textureRow);
    TextureRect::Builder& ofFrames(unsigned int textureColumn, unsigned int textureRow);
    TextureRect * build();
    ~Builder();
};
