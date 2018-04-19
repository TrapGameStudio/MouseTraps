#pragma once
#include "gui/lang/Drawable.h"
#include "gui/geom/Point.h"
#include "lang/Comparable.h"
/// <summary>
/// A 2D Line.
/// </summary>
class Line :
	public Comparable<Line> {
private:
	Point* p1 = nullptr;
	Point* p2 = nullptr;
	float thickness = 0.0f;
public:
	Line(Point* p1, Point* p2);
	Line(float x1, float y1, float x2, float y2);
	float length();
	int compareTo(const Line* o) const;
	~Line();
};

