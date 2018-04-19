#pragma once
#include "gui/lang/Drawable.h"
#include "gui/lang/Movable.h"
#include "gui/geom/Point.h"
#include "lang/Comparable.h"
#include "gui/util/Anchor.h"
#include "gui/util/Color.h"
#include "gui/geom/Vector.h"
#include <memory>
#include <stdio.h>
class Rect :
	public Drawable,
	public Movable {
private:
	class Builder;
protected:
	Anchor anchor = Anchor::TopLeft;
	Point* anchorLocation = new Point(0.0f, 0.0f);
	Vector* size = new Vector(0.0f, 0.0f);
	Vector* scalingFactor = new Vector(1.0f, 1.0f);
	Color* color = Color::white();
	Point* topLeft;
	Vector* absoluteSize;
	Rect();
	void updateAbsoluteRepresentation();
public:
	Rect(
		Vector* size,
		Anchor anchor,
		Point* anchorLocation,
		Color* color);
	Rect* zoom(float magnitude);
	void scale(float x, float y);
	Rect* setSize(Vector* size);
	Rect* setSize(float x, float y);
	Vector* const getSize() const;
	Rect* setAnchorLocation(float x, float y);
	Rect* setAnchorLocation(Point* anchorLocation);
	Point* const getAnchorLocation() const;
	Rect* setAnchor(Anchor anchor);
	Anchor getAnchor() const;
	Point* const getTopLeft() const;
	Rect* setColor(Color* color);
	Color* const getColor() const;
	void draw();
	void move(float dx, float dy);
	bool contains(float x, float y);
	~Rect();
	static Rect::Builder builder();
};

class Rect::Builder {
	Rect * building = new Rect();

public:
	Rect::Builder& ofSize(Vector* size);
	Rect::Builder& ofSize(float x, float y);
	Rect::Builder& atLocation(float x, float y);
	Rect::Builder& atLocation(Point* anchorLocation);
	Rect::Builder& onAnchor(Anchor anchor);
	Rect::Builder& ofColor(Color* color);
	Rect * build();
	~Builder();
};
