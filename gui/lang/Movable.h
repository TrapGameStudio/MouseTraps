#pragma once
class Movable {
public:
	virtual void move(float dx, float dy) = 0;
	virtual ~Movable() {};
};

