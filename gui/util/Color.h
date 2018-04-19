#pragma once
class Color {
	float r, g, b, a;
public:
	Color(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a=1.0f);
	Color(int r, int g, int b);
	Color(int rgb);
	Color(const Color& c);
	~Color();
	static Color* of(float r, float g, float b, float a);
	static Color* of(float r, float g, float b);
	static Color* of(int r, int g, int b);
	static Color* of(int rgb);
	static Color* aqua() { return new Color(0.0f, 1.0f, 1.0f); }
	static Color* black() { return new Color(0.0f, 0.0f, 0.0f); }
	static Color* blue() { return new Color(0.0f, 0.0f, 1.0f); }
	static Color* fuchsia() { return new Color(1.0f, 0.0f, 1.0f); }
	static Color* gray() { return new Color(0.5f, 0.5f, 0.5f); }
	static Color* green() { return new Color(0.0f, 0.5f, 0.0f); }
	static Color* lime() { return new Color(0.0f, 1.0f, 0.0f); }
	static Color* maroon() { return new Color(0.5f, 0.0f, 0.0f); }
	static Color* navy() { return new Color(0.0f, 0.0f, 0.5f); }
	static Color* olive() { return new Color(0.5f, 0.5f, 0.0f); }
	static Color* purple() { return new Color(0.5f, 0.0f, 0.5f); }
	static Color* red() { return new Color(1.0f, 0.0f, 0.0f); }
	static Color* silver() { return new Color(0.75f, 0.75f, 0.75f); }
	static Color* teal() { return new Color(0.0, 0.5f, 0.5f); }
	static Color* white() { return new Color(1.0f, 1.0f, 1.0f); }
	static Color* yellow() { return new Color(1.0f, 1.0f, 0.0f); }
	void setColor(float r, float g, float b, float a);
	void setColor(float r, float g, float b);
	void setColor(int r, int g, int b);
	void setColor(int rgb);
	void setTo(Color* c);
	Color* deepCopy();
	float getR() const;
	float getG() const;
	float getB() const;
	float getA() const;
};

