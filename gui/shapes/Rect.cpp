#include "Rect.h"

/// <summary>
/// Non top-left anchor shapes are hard to draw, so there is a absolute representation
/// which is converted from the user defined anchor and location to the equivalent
/// coordinate as if the shape is using a top-left anchor. I tried to convert negative
/// size, but that is too much to deal with so I just convert negative size values to 
/// their absolute values.
/// </summary>
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

/// <summary>
/// Constructor for builder use only.
/// </summary>
Rect::Rect() {
	this->absoluteSize = this->size->deepCopy();
	this->topLeft = this->anchorLocation->deepCopy();
	updateAbsoluteRepresentation();
}

// TODO: make anchorLocation and color sink parameters
/// <summary>
/// Create a rectangle with specific value.
/// </summary>
/// <param name="size">size of the rectangle in window coordinate</param>
/// <param name="anchor">anchor type. <see cref="Anchor" /></param>
/// <param name="anchorLocation">
/// the location of the anchor of the rectangle in window coordinate.
/// This is a not a sink parameter.
/// </param>
/// <param name="color">
/// color of the rectangle.
/// This is not a skin parameter.
/// </param>
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

/// <summary>
/// Moving the shape by a specific amount.
/// </summary>
/// <param name="dx">distance to move in the x direction</param>
/// <param name="dy">distance to move in the y direction</param>
void Rect::move(float dx, float dy) {
	anchorLocation->add(dx, dy);
	updateAbsoluteRepresentation();
}

/// <summary>
/// Check if a point (x, y) is within this shape.
/// </summary>
/// <param name="x">x coordinate of the point to check</param>
/// <param name="y">y coordinate of the point to check</param>
/// <returns></returns>
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

/// <summary>
/// Magnify or shrink the size of the rectangle by specific magnitude.
/// </summary>
void Rect::zoom(float magnitude) {
	scalingFactor->multiply(magnitude);
	updateAbsoluteRepresentation();
}

/// <summary>
/// Change the aspect ratio of this rectangle.
/// </summary>
void Rect::scale(float x, float y) {
	this->scalingFactor->setTo(x, y);
	updateAbsoluteRepresentation();
}

/// <summary>
/// Set the size of the rectangle with the value specified by a Vector
/// </summary>
/// <param name="size">
/// size to set.
/// This is not a sink parameter.
/// </param>
void Rect::setSize(Vector * size) {
	this->size->setTo(size);
	updateAbsoluteRepresentation();
}

void Rect::setSize(float x, float y) {
	size->setX(x);
	size->setY(y);
	updateAbsoluteRepresentation();
}


Vector * const Rect::getSize() const {
	return this->size;
}

void Rect::setAnchorLocation(float x, float y) {
	anchorLocation->setX(x);
    anchorLocation->setY(y);
	updateAbsoluteRepresentation();
}

void Rect::setAnchorLocation(Point * anchorLocation) {
	this->anchorLocation->setTo(anchorLocation);
	updateAbsoluteRepresentation();
}

Point* const Rect::getAnchorLocation() const {
	return this->anchorLocation;
}

void Rect::setAnchor(Anchor anchor) {
	this->anchor = anchor;
	updateAbsoluteRepresentation();
}

Anchor Rect::getAnchor() const {
	return this->anchor;
}

Point * const Rect::getTopLeft() const {
	return topLeft;
}

void Rect::setColor(Color * color) {
	this->color->setTo(color);
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
