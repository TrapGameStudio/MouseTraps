#pragma once
#include <string>
#include "../shapes/Rect.h"
#include "../util/TextureManager.h"
#include "../lang/TextureType.h"
#include "../lang/Animatable.h"
class TextureRect :
    public Rect,
    public Animatable {
private:
    /// <summary>
    /// The texture id given by freeglut that this texture rectangle will be using
    /// </summary>
    GLuint textureID = 0;

    /// <summary>
    /// The full path to the texture file
    /// </summary>
    std::string textureFileName;

    /// <summary>
    /// The type of texture of this rectangle. <see cref="TextureType"/>
    /// </summary>
    TextureType textureType = TextureType::Static;

    /// <summary>
    /// The size of the texture in texture coordinate this rectangle will be using.
    /// 1.0f, 1.0f means the whole texture will be mapped onto this rectangle.
    /// Should not be directly set. <see cref="TextureRect#updateTextureInfo" />
    /// </summary>
    Vector * textureTileSize = new Vector(1.0f, 1.0f);

    /// <summary>
    /// The number of texture per column the texture file has.
    /// </summary>
    unsigned int textureColumn = 1;

    /// <summary>
    /// The number of texture per row the texture file has.
    /// </summary>
    unsigned int textureRow = 1;

    /// <summary>
    /// The index of column of the texture.
    /// </summary>
    unsigned int currentTextureColumn = 0;

    /// <summary>
    /// The index of row of the texture.
    /// </summary>
    unsigned int currentTextureRow = 0;

    /// <summary>
    /// The actual texture coordinate of the texture is on.
    /// Should not be directly set. <see cref="TextureRect#updateTextureInfo" />
    /// </summary>
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
    void setColor(Color* color);
    void setTexture(const char* textureFileName);
    void setTextureType(TextureType textureType);
    void setTextureColumn(unsigned int textureColumn);
    void setTextureRow(unsigned int textureRow);
    void setColumnRow(unsigned int textureColumn, unsigned int textureRow);
    void setCurrentColumn(unsigned int textureColumn);
    unsigned int getCurrentColumn();
    void setCurrentRow(unsigned int textureRow);
    void setCurrentColumnRow(unsigned int textureColumn, unsigned int textureRow);
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
    TextureRect::Builder& ofColumnRow(unsigned int textureColumn, unsigned int textureRow);
    TextureRect::Builder& ofCurrentColumnRow(unsigned int textureColumn, unsigned int textureRow);
    TextureRect::Builder& atFrame(unsigned int frame);
    TextureRect * build();
    ~Builder();
};
