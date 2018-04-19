#include "Line.h"


/// <summary>
/// Construct a line from 2 Points.
/// </summary>
/// <param name="p1">point 1</param>
/// <param name="p2">point 2</param>
Line::Line(Point* p1, Point* p2) {
    this->p1 = p1;
    this->p2 = p2;
}

/// <summary>
/// Construct a line from the coordinate of 2 points.
/// </summary>
/// <param name="x1">x coordinate of the first point</param>
/// <param name="y1">y coordinate of the first point</param>
/// <param name="x2">x coordinate of the second point</param>
/// <param name="y2">y coordinate of the second point</param>
Line::Line(float x1, float y1, float x2, float y2) {
    p1 = new Point(x1, y1);
    p2 = new Point(x2, y2);
}

/// <summary>
/// Get the length of the line.
/// </summary>
/// <returns>the length</returns>
float Line::length() {
    return p1->getDistanceTo(p2);
}

int Line::compareTo(const Line* l) const {
    float diff = this->p1->getDistanceSquareTo(this->p2) - l->p1->getDistanceSquareTo(l->p2);
    if (diff == 0) {
        return 0;
    } else if (diff > 0) {
        return 1;
    } else {
        return -1;
    }
}


Line::~Line() {
    delete p1;
    delete p2;
}
