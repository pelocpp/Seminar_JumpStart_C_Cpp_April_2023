#include <iostream>

// Concept / Interface
class IRectangleConcept
{
public:
    virtual void paint() = 0;   // NO IMPLEMENTATION
    virtual void eraseBackground() = 0;   // NO IMPLEMENTATION
    virtual void drawBorder() = 0;

private:
    int m_data;
};

// ==========================================

class Rectangle : public IRectangleConcept
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

    // Extremely short implementation
    void eraseBackground() override {}
    void drawBorder() override {}
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
    void paint() override {

     //   Rectangle::paint();

        std::cout << "in class ColoredRectangle: additional stuff" << std::endl;
    }
};

class TransparantRectangle : public Rectangle
{
public:
    // memberwise initialization list
    TransparantRectangle() :
        // Rectangle(1, 1, 1, 1), m_color(0)
        // or: Redirecting to a neighboured constructor
        // -- Note: C++ 17 or higher
        TransparantRectangle(1, 1, 1, 1, 0)
    { }

    TransparantRectangle(int top, int left, int width, int height, int opaque)
        : Rectangle(top, left, width, height), m_opaque(opaque)
    { }

private:
    int m_opaque;

public:
    // public interface
    void paint() override {

     //   Rectangle::paint();

        std::cout << "in class TransparantRectangle" << std::endl;
    }
};

void main_inheritance_01()
{
    Rectangle r (10, 10, 20, 10);
    ColoredRectangle cr (10, 10, 20, 10, 99);

    cr.paint ();
}

void main_inheritance_02()
{
    ColoredRectangle cr(10, 10, 20, 10, 99);

    Rectangle* rp;

    rp = &cr;   // is - a Relationship

    rp->paint();    // A) ColoredRectangle.paint
                    //    because cr points to a ColoredRectangle
                    // B) Rectangle.paint
                    //    because rp is type of Rectangle
}

void main_inheritance_03()
{
    ColoredRectangle cr1;
    TransparantRectangle tr1;
    ColoredRectangle cr2;
    TransparantRectangle tr2;
    ColoredRectangle cr3;

    Rectangle* rectangles[5] = { &cr1, &tr1, &cr2, &tr2, &cr3 };

    for (int i = 0; i < 5; ++i)
    {
        // Greece:  poly
        // Body:    Morphus
        //    Polymorphism
        rectangles[i]->paint();
    }

    // WITHOUT Virtual // WITHOUT Polymorphism
    //for (int i = 0; i < 5; ++i)
    //{
    //    if (rectangles[i] isTypeOf ColoredRectangle) {
    //        rectangles[i]->paintOfColoredRectangle();
    //    }
    //    else if (rectangles[i] isTypeOf TransparantRectangle) {
    //        rectangles[i]->paintOfTransparantRectangle();
    //    }
    //    else ...

    //}
}

void main_inheritance_04()
{
    ColoredRectangle cr(10, 10, 20, 10, 99);

    ColoredRectangle* crp = &cr;

    crp->paint();
}


IRectangleConcept* FactoryForColoredRectangle()
{
    // ........ hidden implementation
    ColoredRectangle* crp =
        new ColoredRectangle(10, 10, 20, 10, 99);

    return crp;
}

void main_inheritance_05()
{
    // ColoredRectangle cr(10, 10, 20, 10, 99);

    // decoupling  // Entkopplung // loose coupling

    IRectangleConcept* crp;  // interface pointer

    crp = FactoryForColoredRectangle();
    crp->drawBorder();
    crp->eraseBackground();
    crp->paint();
}

void main_inheritance()
{
    // main_inheritance_01();
    //main_inheritance_02();
    main_inheritance_03();
}

// ==================================

//class Line
//{ };
//
//// Verification by DESIGN: 
//class Point : public Line
//{};
