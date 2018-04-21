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
    void setX(float x);
    void addX(float dx);
    float getX() const;
    void setY(float y);
    void addY(float dy);
    float getY() const;
    static Point* add(const Point* p1, const Point* p2);
    void add(float dx, float dy);
    static Point* subtract(const Point* p1, const Point* p2);
    void setTo(const Point* p);
    void setTo(float x, float y);
    float getDistanceTo(const Point* p);
    float getDistanceSquareTo(const Point* p);
    Point* deepCopy();
    ~Point();
};

