#include <iostream>

//class Calculator
//{
//public:
//    static int add(int n, int m) { return n + m; }
//    static int sub(int n, int m) { return n - m; }
//    static int mul(int n, int m) { return n * m; }
//    static int div(int n, int m) { return n / m; }
//};

// primary template
template <typename T>
class Calculator
{
public:
    static T add(T n, T m) { return n + m; }
    static T sub(T n, T m) { return n - m; }
    static T mul(T n, T m) { return n * m; }
    static T div(T n, T m) 
    { 
        return n / m;
    }
};

// full template specialization:   T = int
template <>
class Calculator <int>
{
public:
    static int add(int n, int m) { return n + m; }
    static int sub(int n, int m) { return n - m; }
    static int mul(int n, int m) { return n * m; }
    static int div(int n, int m)
    {
        // different implementation
        return  (int) ((n / (double)m) + 0.5);
    }
};


//class DoubleCalculator
//{
//public:
//    static double add(double n, double m) { return n + m; }
//    static double sub(double n, double m) { return n - m; }
//    static double mul(double n, double m) { return n * m; }
//    static double div(double n, double m) { return n / m; }
//};

void test_gp()
{
    Calculator<int> calculator;

    double dsum = Calculator<double>::add(3.3, 4.4); // T = double
    std::cout << dsum << std::endl;

    int result = Calculator<int>::div(1, 4);   // T = int
    std::cout << result << std::endl;

    int sum = Calculator<int>::div(3, 4);   // T = int
    std::cout << sum << std::endl;

}