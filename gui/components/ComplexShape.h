#pragma once
#include "gui/lang/Drawable.h"
#include "gui/geom/Point.h"
#include "gui/util/Anchor.h"
#include <deque>
#include <initializer_list>
class ComplexShape :
    public Drawable {
private:
    class Builder;
    std::deque<Drawable *> shapes;
    Point * referencePoint = new Point(0.0f, 0.0f);
    Anchor anchor = Anchor::TopLeft;
public:
    ComplexShape();
    void draw();
    void push_front(Drawable* shape);
    void push_back(Drawable* shape);
    void move(float dx, float dy);
    void scale(float x, float y);
    ~ComplexShape();

    static ComplexShape::Builder builder();
};

class ComplexShape::Builder {
private:
    ComplexShape * building = new ComplexShape();
public:
    ComplexShape::Builder & of(Drawable* shape);
    ComplexShape::Builder & of(std::initializer_list<Drawable*> shapes);
    ComplexShape::Builder & ofReferencePoint(float x, float y);
    ComplexShape::Builder & ofReferencePoint(Point* referencePoint);
    ComplexShape::Builder & onAnchor(Anchor anchor);
    ComplexShape * build();
};
