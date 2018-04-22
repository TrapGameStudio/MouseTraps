#pragma once
#include "TextureRect.h"
#include "../lang/Drawable.h"
#include <deque>
#include <string>
class TextBlock :
    public Rect {
private:
    class Builder;
    std::deque<TextureRect*> chars;
    std::string text;
    GLuint textureID = 0;

    Anchor anchor = Anchor::TopLeft;
    Point* anchorLocation = new Point(0.0f, 0.0f);
    Vector* size = new Vector(0.0f, 0.0f);
    float maxHeight;
    float maxWidth;
    Color* color = Color::white();
    TextBlock();
    void addChar(char c);

public:
    TextBlock(Vector* size, Anchor anchor, Point* anchorLocation, Color* color, const char* string);
    void setAnchor(Anchor anchor);
    void setLocation(float x, float y);
    void setSize(float x, float y);
    void setColor(Color * color);
    void setText(const char* string);
    void updateShapes();
    void draw();
    ~TextBlock();
};

class TextBlock::Builder {
private:
    TextBlock * building = new TextBlock();
public:
    TextBlock::Builder& ofSize(Vector* size);
    TextBlock::Builder& ofSize(float x, float y);
    TextBlock::Builder& atLocation(float x, float y);
    TextBlock::Builder& atLocation(Point* anchorLocation);
    TextBlock::Builder& onAnchor(Anchor anchor);
    TextBlock::Builder& ofColor(Color* color);
    TextBlock::Builder& ofText(const char* string);
    TextBlock * build();
};
