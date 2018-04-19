#pragma once
#include <cmath>
#include <memory>
#include "gui/geom/Point.h"
#include "lang/Comparable.h"
class Vector :
    public Comparable<Vector> {
private:
    float x, y;
public:
    Vector(float x = 0.0f, float y = 0.0f);
    Vector(const Vector& v);
    float getMagnitude() const;
    float getMagnitudeSquare() const;
    float getX() const;
    Vector* setX(float x);
    float getY() const;
    Vector* setY(float y);
    Vector* setTo(const Vector* v);
    Vector* setTo(float x, float y);
    static Vector* of(float x, float y);
    Vector * ofZeroToPoint(Point * p);
    static Vector* add(const Vector* v1, const Vector* v2);
    Vector* add(float dx, float dy);
    static Vector* subtract(const Vector* v1, const Vector* v2);
    static Vector* multiply(const Vector* v, float s);
    Vector* multiply(float s);
    Vector* getUnitVector() const;
    Vector* deepCopy() const;
    int compareTo(const Vector* v) const;
    ~Vector();
};

