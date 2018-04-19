#include "ComplexShape.h"



ComplexShape::ComplexShape() {}

void ComplexShape::draw() {}

void ComplexShape::push_front(Drawable * shape) {}

void ComplexShape::push_back(Drawable * shape) {}

void ComplexShape::move(float dx, float dy) {}

void ComplexShape::scale(float x, float y) {}


ComplexShape::~ComplexShape() {}

ComplexShape::Builder ComplexShape::builder() {
	return ComplexShape::Builder();
}

ComplexShape::Builder & ComplexShape::Builder::of(Drawable *shape) {
	building->shapes.push_back(shape);
	return *this;
}

ComplexShape::Builder & ComplexShape::Builder::of(std::initializer_list<Drawable*> shapes) {
	for (Drawable* s : shapes) {
		building->shapes.push_back(s);
	}
	return *this;
}

ComplexShape::Builder & ComplexShape::Builder::ofReferencePoint(float x, float y) {
	building->referencePoint->setTo(x, y);
	return *this;
}

ComplexShape::Builder & ComplexShape::Builder::ofReferencePoint(Point * referencePoint) {
	delete building->referencePoint;
	building->referencePoint = referencePoint;
	return *this;
}

ComplexShape::Builder & ComplexShape::Builder::onAnchor(Anchor anchor) {
	building->anchor = anchor;
	return *this;
}

ComplexShape * ComplexShape::Builder::build() {
	return building;
}
