#include "Color.h"



Color::Color(float r, float g, float b, float a) {
	setColor(r, g, b, a);
}

Color::Color(int r, int g, int b) {
	setColor(r, g, b);
}

Color::Color(int rgb) {
	setColor(rgb);
}

Color::Color(const Color & c) {
	r = c.r;
	g = c.g;
	b = c.b;
	a = c.a;
}

Color::~Color() {}

Color* Color::of(float r, float g, float b, float a) {
	return new Color(r, g, b, a);
}

Color* Color::of(float r, float g, float b) {
	return new Color(r, g, b);
}

Color* Color::of(int r, int g, int b) {
	return new Color(r, b, b);
}

Color* Color::of(int rgb) {
	return new Color(rgb);
}

void Color::setColor(float r, float g, float b, float a) {
	if (
		r >= 0 && r <= 1 &&
		g >= 0 && g <= 1 &&
		b >= 0 && b <= 1 &&
		a >= 0 && a <= 1
		) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	} else {
		this->r = 0.0f;
		this->g = 0.0f;
		this->b = 0.0f;
		this->a = 1.0f;
	}
}

void Color::setColor(float r, float g, float b) {
	setColor(r, g, b, 1.0);
}

void Color::setColor(int r, int g, int b) {
	setColor(((float)r) / 256, ((float)g) / 256, ((float)b) / 256, 1.0);
}

void Color::setColor(int rgb) {
	int r = (rgb & 0xff0000) >> 16;
	int g = (rgb & 0x00ff00) >> 8;
	int b = (rgb & 0x0000ff);
	setColor(r, g, b);
}

void Color::setTo(Color * c) {
	r = c->r;
	g = c->g;
	b = c->b;
	a = c->a;
}

Color * Color::deepCopy() {
	return new Color(r, g, b, a);
}

float Color::getR() const {
	return this->r;
}

float Color::getG() const {
	return this->g;
}

float Color::getB() const {
	return this->b;
}

float Color::getA() const {
	return this->a;
}
