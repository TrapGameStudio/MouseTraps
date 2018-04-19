#include "Rect.h"

void Rect::updateAbsoluteRepresentation() {
	absoluteSize->setTo(size);
	absoluteSize->setX(absoluteSize->getX() * scalingFactor->getX());
	absoluteSize->setY(absoluteSize->getY() * scalingFactor->getY());
	topLeft->setTo(anchorLocation);
	if (size->getX() < 0.0f) {
		absoluteSize->setX(-(size->getX()));
	}
	if (size->getY() < 0.0f) {
		absoluteSize->setY(-(size->getY()));
	}
	switch (anchor) {
	case Top:
		topLeft->addX(-0.5f * absoluteSize->getX());
		break;
	case TopRight:
		topLeft->addX(-absoluteSize->getX());
		break;
	case Left:
		topLeft->addY(0.5f * absoluteSize->getY());
		break;
	case Center:
		topLeft->addX(-0.5f * absoluteSize->getX());
		topLeft->addY(0.5f * absoluteSize->getY());
		break;
	case Right:
		topLeft->addX(-absoluteSize->getX());
		topLeft->addY(0.5f * absoluteSize->getY());
		break;
	case BottomLeft:
		topLeft->addY(absoluteSize->getY());
		break;
	case Bottom:
		topLeft->addX(-0.5f * absoluteSize->getX());
		topLeft->addY(absoluteSize->getY());
		break;
	case BottomRight:
		topLeft->addX(-absoluteSize->getX());
		topLeft->addY(absoluteSize->getY());
	}
}

Rect::Rect() {
	this->absoluteSize = this->size->deepCopy();
	this->topLeft = this->anchorLocation->deepCopy();
	updateAbsoluteRepresentation();
}

Rect::Rect(Vector* size, Anchor anchor, Point* anchorLocation, Color* color) {
	this->anchor = anchor;
	if (anchorLocation) { this->anchorLocation->setTo(anchorLocation); }
	if (size) { this->size->setTo(size); }
	if (color) { this->color->setTo(color); }
	this->absoluteSize = this->size->deepCopy();
	this->topLeft = this->anchorLocation->deepCopy();
	updateAbsoluteRepresentation();
}

void Rect::draw() {
    glPushMatrix();
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(
        color->getR(),
        color->getG(),
        color->getB(),
        color->getA()
    );
    glBegin(GL_QUADS);
    glVertex2f(topLeft->getX(), topLeft->getY());
    glVertex2f(topLeft->getX() + absoluteSize->getX(), topLeft->getY());
    glVertex2f(topLeft->getX() + absoluteSize->getX(), topLeft->getY() - absoluteSize->getY());
    glVertex2f(topLeft->getX(), topLeft->getY() - absoluteSize->getY());
    glEnd();
    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
    glPopMatrix();
}

void Rect::move(float dx, float dy) {
	anchorLocation->add(dx, dy);
}

bool Rect::contains(float x, float y) {
	return (x >= topLeft->getX()
			&& x <= topLeft->getX() + absoluteSize->getX()
			&& y <= topLeft->getY()
			&& y >= topLeft->getY() - absoluteSize->getY());
}

Rect::~Rect() {
	delete size;
	delete anchorLocation;
	delete color;
	delete absoluteSize;
	delete topLeft;
}

Rect::Builder Rect::builder() {
	return Rect::Builder();
}

Rect* Rect::zoom(float magnitude) {
	scalingFactor->multiply(magnitude);
	updateAbsoluteRepresentation();
	return this;
}

void Rect::scale(float x, float y) {
	this->scalingFactor->setTo(x, y);
	updateAbsoluteRepresentation();
}

Rect* Rect::setSize(Vector * size) {
	this->size->setTo(size);
	updateAbsoluteRepresentation();
	return this;
}

Rect* Rect::setSize(float x, float y) {
	size->setX(x);
	size->setY(y);
	updateAbsoluteRepresentation();
	return this;
}


Vector * const Rect::getSize() const {
	return this->size;
}

Rect * Rect::setAnchorLocation(float x, float y) {
	size->setX(x);
	size->setY(y);
	updateAbsoluteRepresentation();
	return this;
}

Rect* Rect::setAnchorLocation(Point * anchorLocation) {
	this->anchorLocation->setTo(anchorLocation);
	updateAbsoluteRepresentation();
	return this;
}

Point* const Rect::getAnchorLocation() const {
	return this->anchorLocation;
}

Rect* Rect::setAnchor(Anchor anchor) {
	this->anchor = anchor;
	updateAbsoluteRepresentation();
	return this;
}

Anchor Rect::getAnchor() const {
	return this->anchor;
}

Point * const Rect::getTopLeft() const {
	return topLeft;
}

Rect* Rect::setColor(Color * color) {
	this->color->setTo(color);
	return this;
}

Color* const Rect::getColor() const {
	return this->color;
}



Rect::Builder & Rect::Builder::ofSize(Vector* size) {
	delete building->size;
	building->size = size;
	return *this;
}


Rect::Builder & Rect::Builder::ofSize(float x, float y) {
	building->size->setTo(x, y);
	return *this;
}


Rect::Builder & Rect::Builder::atLocation(float x, float y) {
	building->anchorLocation->setTo(x, y);
	return *this;
}


Rect::Builder & Rect::Builder::atLocation(Point * anchorLocation) {
	delete building->anchorLocation;
	building->anchorLocation = anchorLocation;
	return *this;
}


Rect::Builder & Rect::Builder::onAnchor(Anchor anchor) {
	building->anchor = anchor;
	return *this;
}


Rect::Builder & Rect::Builder::ofColor(Color * color) {
	delete building->color;
	building->color = color;
	return *this;
}


Rect * Rect::Builder::build() {
	building->updateAbsoluteRepresentation();
	return building;
}


Rect::Builder::~Builder() {}
