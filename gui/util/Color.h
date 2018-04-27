#pragma once
class Color {
    float r, g, b, a;
public:
    Color(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a=1.0f);
    Color(int r, int g, int b);
    Color(int rgb);
    Color(const Color& c);
    ~Color();

    /// <summary>
    /// Create a color from 4 (0.0f-1.0f) float values of R, G, B, and A.
    /// </summary>
    /// <param name="r">intensity of color red (0.0f-1.0f)</param>
    /// <param name="g">intensity of color green (0.0f-1.0f)</param>
    /// <param name="b">intensity of color blue (0.0f-1.0f)</param>
    /// <param name="a">
    /// value (0.0f-1.0f) for alpha
    /// (0.0f for opaque, 1.0f for transparent)
    /// </param>
    /// <returns></returns>
    static Color* of(float r, float g, float b, float a);

    /// <summary>
    /// Create a color from 3 (0.0f-1.0f) float values of R, G, and B.
    /// </summary>
    /// <param name="r">intensity of color red (0.0f-1.0f)</param>
    /// <param name="g">intensity of color green (0.0f-1.0f)</param>
    /// <param name="b">intensity of color blue (0.0f-1.0f)</param>
    /// <returns>a new instance of the specified color</returns>
    static Color* of(float r, float g, float b);

    /// <summary>
    /// Create a color from 3 (0-255) integer values of R, G, and B
    /// </summary>
    /// <param name="r">intensity of color red (0-255)</param>
    /// <param name="g">intensity of color green (0-255)</param>
    /// <param name="b">intensity of color blue (0-255)</param>
    /// <returns>a new instance of the specified color</returns>
    static Color* of(int r, int g, int b);

    /// <summary>
    /// Create a color from a rgb hex value
    /// </summary>
    /// <param name="rgb">a hex color value as in the form of 0xRRGGBB</param>
    /// <returns>a new instance of the specified color.</returns>
    static Color* of(int rgb);

    /// <summary>
    /// A static methods to get a new instance of aqua color (0.0f, 1.0f, 1.0f, 0.0f)
    /// </summary>
    /// <returns>a new instance of aqua color with 0 alpha</returns>
    static Color* aqua() { return new Color(0.0f, 1.0f, 1.0f); }

    /// <summary>
    /// A static methods to get a new instance of black color (0.0f, 0.0f, 0.0f, 0.0f)
    /// </summary>
    /// <returns>a new instance of black color with 0 alpha</returns>
    static Color* black() { return new Color(0.0f, 0.0f, 0.0f); }

    /// <summary>
    /// A static methods to get a new instance of blue color (0.0f, 0.0f, 1.0f, 0.0f)
    /// </summary>
    /// <returns>a new instance of blue color with 0 alpha</returns>
    static Color* blue() { return new Color(0.0f, 0.0f, 1.0f); }

    /// <summary>
    /// A static methods to get a new instance of fuchsia color (1.0f, 0.0f, 1.0f, 0.0f)
    /// </summary>
    /// <returns>a new instance of fuchsia color with 0 alpha</returns>
    static Color* fuchsia() { return new Color(1.0f, 0.0f, 1.0f); }

    /// <summary>
    /// A static methods to get a new instance of gray color (0.5f, 0.5f, 0.5f, 0.0f)
    /// </summary>
    /// <returns>a new instance of gray color with 0 alpha</returns>
    static Color* gray() { return new Color(0.5f, 0.5f, 0.5f); }

    /// <summary>
    /// A static methods to get a new instance of green color (0.0f, 0.5f, 0.0f, 0.0f)
    /// </summary>
    /// <returns>a new instance of green color with 0 alpha</returns>
    static Color* green() { return new Color(0.0f, 0.5f, 0.0f); }

    /// <summary>
    /// A static methods to get a new instance of lime color (0.0f, 1.0f, 0.0f, 0.0f)
    /// </summary>
    /// <returns>a new instance of lime color with 0 alpha</returns>
    static Color* lime() { return new Color(0.0f, 1.0f, 0.0f); }

    /// <summary>
    /// A static methods to get a new instance of maroon color (0.5f, 0.0f, 0.0f, 0.0f)
    /// </summary>
    /// <returns>a new instance of maroon color with 0 alpha</returns>
    static Color* maroon() { return new Color(0.5f, 0.0f, 0.0f); }

    /// <summary>
    /// A static methods to get a new instance of navy color (0.0f, 0.0f, 0.5f, 0.0f)
    /// </summary>
    /// <returns>a new instance of navy color with 0 alpha</returns>
    static Color* navy() { return new Color(0.0f, 0.0f, 0.5f); }

    /// <summary>
    /// A static methods to get a new instance of olive color (0.5f, 0.5f, 0.0f, 0.0f)
    /// </summary>
    /// <returns>a new instance of olive color with 0 alpha</returns>
    static Color* olive() { return new Color(0.5f, 0.5f, 0.0f); }

    /// <summary>
    /// A static methods to get a new instance of purple color (0.5f, 0.0f, 0.5f, 0.0f)
    /// </summary>
    /// <returns>a new instance of purple color with 0 alpha</returns>
    static Color* purple() { return new Color(0.5f, 0.0f, 0.5f); }

    /// <summary>
    /// A static methods to get a new instance of red color (1.0f, 0.0f, 0.0f, 0.0f)
    /// </summary>
    /// <returns>a new instance of red color with 0 alpha</returns>
    static Color* red() { return new Color(1.0f, 0.0f, 0.0f); }

    /// <summary>
    /// A static methods to get a new instance of silver color (0.75f, 0.75f, 0.75f, 0.0f)
    /// </summary>
    /// <returns>a new instance of silver color with 0 alpha</returns>
    static Color* silver() { return new Color(0.75f, 0.75f, 0.75f); }

    /// <summary>
    /// A static methods to get a new instance of teal color (0.0f, 0.5f, 0.5f, 0.0f)
    /// </summary>
    /// <returns>a new instance of teal color with 0 alpha</returns>
    static Color* teal() { return new Color(0.0f, 0.5f, 0.5f); }

    /// <summary>
    /// A static methods to get a new instance of white color (1.0f, 1.0f, 1.0f, 0.0f)
    /// </summary>
    /// <returns>a new instance of white color with 0 alpha</returns>
    static Color* white() { return new Color(1.0f, 1.0f, 1.0f); }

    /// <summary>
    /// A static methods to get a new instance of yellow color (1.0f, 1.0f, 0.0f, 0.0f)
    /// </summary>
    /// <returns>a new instance of yellow color with 0 alpha</returns>
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

