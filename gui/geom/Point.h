#pragma once
/// <summary>
/// A point represents a (x, y) location in space.
/// </summary>
class Point {
private:
    float x;
    float y;
public:
    Point(float x = 0.0f, float y = 0.0f);
    Point(const Point& p);
    static Point* of(float x, float y);
    Point* setX(float x);
    Point* addX(float dx);
    float getX() const;
    Point* setY(float y);
    Point* addY(float dy);
    float getY() const;
    static Point* add(const Point* p1, const Point* p2);
    Point* add(float dx, float dy);
    static Point* subtract(const Point* p1, const Point* p2);
    Point* setTo(const Point* p);
    Point * setTo(float x, float y);
    float getDistanceTo(const Point* p);
    float getDistanceSquareTo(const Point* p);
    Point* deepCopy();
    ~Point();
};

