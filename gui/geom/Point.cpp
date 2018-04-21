#include "Point.h"
#include <cmath>

Point::Point(float x, float y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point & p) {
    x = p.x;
    y = p.y;
}

Point * Point::of(float x, float y) {
    return new Point(x, y);
}

void Point::setX(float x) {
    this->x = x;
}

void Point::addX(float dx) {
    this->x += dx;
}

float Point::getX() const {
    return x;
}

void Point::setY(float y) {
    this->y = y;
}

void Point::addY(float dy) {
    this->y += dy;
}

Point * Point::add(const Point * p1, const Point * p2) {
    return new Point(p1->x + p2->x, p1->y + p2->y);
}

void Point::add(float dx, float dy) {
    x += dx;
    y += dy;
}

Point * Point::subtract(const Point * p1, const Point * p2) {
    return new Point(p1->x - p2->x, p1->y - p2->y);
}

void Point::setTo(const Point * p) {
    x = p->x;
    y = p->y;
}

void Point::setTo(float x, float y) {
    this->x = x;
    this->y = y;
}

float Point::getY() const {
    return y;
}

float Point::getDistanceTo(const Point * p) {
    return sqrt(getDistanceSquareTo(p));
}

float Point::getDistanceSquareTo(const Point * p) {
    float dx = this->x - p->x;
    float dy = this->y - p->y;
    return dx * dx + dy * dy;
}

Point * Point::deepCopy() {
    return new Point(x, y);
}


Point::~Point() {}
