#include "Vector.h"



Vector::Vector(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector::Vector(const Vector & v) {
	x = v.x;
	y = v.y;
}

float Vector::getMagnitude() const {
	return sqrtf(getMagnitudeSquare());
}

float Vector::getMagnitudeSquare() const {
	return x * x + y * y;
}

float Vector::getX() const {
	return x;
}

Vector * Vector::setX(float x) {
	this->x = x;
	return this;
}

float Vector::getY() const {
	return y;
}

Vector * Vector::setY(float y) {
	this->y = y;
	return this;
}

Vector * Vector::setTo(const Vector * v) {
	x = v->x;
	y = v->y;
	return this;
}

Vector * Vector::setTo(float x, float y) {
	this->x = x;
	this->y = y;
	return this;
}

Vector * Vector::of(float x, float y) {
	return new Vector(x, y);
}

Vector * Vector::ofZeroToPoint(Point * p) {
	return new Vector(p->getX(), p->getY());
}

Vector * Vector::add(const Vector * v1, const Vector * v2) {
	return new Vector(v1->x + v2->x, v1->y + v2->y);
}

Vector * Vector::add(float dx, float dy) {
	x += dx;
	y += dy;
	return this;
}

Vector * Vector::subtract(const Vector * v1, const Vector * v2) {
	return new Vector(v1->x - v2->x, v1->y - v2->y);
}

Vector * Vector::multiply(const Vector * v, float s) {
	return new Vector(v->x * s, v->y * s);
}

Vector * Vector::multiply(float s) {
	x *= s;
	y *= s;
	return this;
}

Vector * Vector::getUnitVector() const {
	float magnitude = getMagnitude();
	return new Vector(x / magnitude, y / magnitude);
}
Vector * Vector::deepCopy() const {
	return new Vector(x, y);
}

int Vector::compareTo(const Vector* v) const {
	if (this->getMagnitudeSquare() == v->getMagnitudeSquare()) {
		return 0;
	} else if (this->getMagnitudeSquare() > v->getMagnitudeSquare()) {
		return 1;
	} else {
		return -1;
	}
}


Vector::~Vector() {}
