#pragma once
#include "../lang/Drawable.h"
#include "../lang/Movable.h"
#include "../geom/Point.h"
#include "../util/Anchor.h"
#include "../util/Color.h"
#include "../geom/Vector.h"
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
	void zoom(float magnitude);
	void scale(float x, float y);
	void setSize(Vector* size);
	void setSize(float x, float y);
	Vector* const getSize() const;
	void setAnchorLocation(float x, float y);
	void setAnchorLocation(Point* anchorLocation);
	Point* const getAnchorLocation() const;
	void setAnchor(Anchor anchor);
	Anchor getAnchor() const;
	Point* const getTopLeft() const;
	void setColor(Color* color);
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
