#include "TextBlock.h"



TextBlock::TextBlock() {}

void TextBlock::addChar(char c) {
    if (c == 10) {

    }
    chars.push_back(
        TextureRect::builder()
        .atLocation(0.0f, 0.0f)
        .ofTexture("Graphics/Fonts/Consolas.png")
        .atFrame((int)c - 40)
        .build()
    );
}

TextBlock::TextBlock(Vector * size, Anchor anchor, Point * anchorLocation, Color * color, const char* string) {}

void TextBlock::setAnchor(Anchor anchor) {
    this->anchor = anchor;
}

void TextBlock::setLocation(float x, float y) {
    this->anchorLocation->setTo(x, y);
}

void TextBlock::setSize(float x, float y) {
    this->size->setTo(x, y);
}

void TextBlock::setColor(Color * color) {
    delete this->color;
    this->color = color;
}

void TextBlock::setText(const char * string) {
    text = string;
}

void TextBlock::updateShapes() {
    chars.clear();
    for (const char& c : text) {

    }
}

void TextBlock::draw() {}


TextBlock::~TextBlock() {}


TextBlock::Builder & TextBlock::Builder::ofSize(Vector* size) {
    delete building->size;
    building->size = size;
    return *this;
}


TextBlock::Builder & TextBlock::Builder::ofSize(float x, float y) {
    building->size->setTo(x, y);
    return *this;
}


TextBlock::Builder & TextBlock::Builder::atLocation(float x, float y) {
    building->anchorLocation->setTo(x, y);
    return *this;
}


TextBlock::Builder & TextBlock::Builder::atLocation(Point * anchorLocation) {
    delete building->anchorLocation;
    building->anchorLocation = anchorLocation;
    return *this;
}


TextBlock::Builder & TextBlock::Builder::onAnchor(Anchor anchor) {
    building->anchor = anchor;
    return *this;
}

TextBlock::Builder & TextBlock::Builder::ofText(const char * string) {
    building->text = string;
    return *this;
}

TextBlock * TextBlock::Builder::build() {
    return building;
}
