#include <iostream>

class Rectangle
{
public:
    // c'tors
    Rectangle()
    {
        m_top = 1;
        m_left = 1;
        m_width = 1;
        m_height = 1;
    }

    Rectangle(int top, int left, int width, int height)
    {
        m_top = top;
        m_left = left;
        m_width = width;
        m_height = height;
    }

private:
    int m_top;
    int m_left;
    int m_width;
    int m_height;

public:
    // public interface
    virtual void paint() {
        std::cout << "in Class Rectangle" << std::endl;
    }
};

class ColoredRectangle : public Rectangle
{
public:
    // memberwise initialization list
    ColoredRectangle() :
        // Rectangle(1, 1, 1, 1), m_color(0)
        // or: Redirecting to a neighboured constructor
        // -- Note: C++ 17 or higher
        ColoredRectangle (1, 1, 1, 1, 0)
    { }

    ColoredRectangle(int top, int left, int width, int height, int color) 
        : Rectangle (top, left, width, height), m_color (color)
    { }

private:
    int m_color;

public:
    // public interface
    void paint() {

        Rectangle::paint();

        std::cout << "in class ColoredRectangle: additional stuff" << std::endl;
    }
};

void main_inheritance_01()
{
    Rectangle r (10, 10, 20, 10);
    ColoredRectangle cr (10, 10, 20, 10, 99);

    cr.paint ();
}

void main_inheritance()
{
    ColoredRectangle cr(10, 10, 20, 10, 99);

    Rectangle* rp;

    rp = &cr;   // is - a Relationship

    rp->paint();   // A) ColoredRectangle.paint
                   //    because cr points to a ColoredRectangle
}                  // B) Rectangle.paint
                   //    because rp is type of Rectangle

// ==================================

//class Line
//{ };
//
//// Verification by DESIGN: 
//class Point : public Line
//{};
