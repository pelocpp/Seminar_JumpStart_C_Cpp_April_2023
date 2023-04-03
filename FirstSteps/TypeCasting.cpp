#include <iostream>

void main_type_casting()
{
    int n = 123;

    long long ll = 100;

    // syntax: type conversion
    //         type cast
    n = (int) ll;

    int greatest = 0b01111111111111111111111111111111;
    std::cout << greatest << std::endl;

    int another = 0x190AFaf;
    std::cout << another << std::endl;


    greatest = greatest + 1;
    std::cout << greatest << std::endl;

    int greatest2 = 2'147'483'648;
    std::cout << greatest2 << std::endl;


    //int smallest = 0b11111111111111111111111111111111;
    //std::cout << smallest << std::endl;
}

void main_type_casting_01()
{
    int n = 123;

    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(n) << std::endl;

    std::cout << "long: " << sizeof(long) << std::endl;
    std::cout << "long long: " << sizeof(long long) << std::endl;
    std::cout << "short: " << sizeof(short) << std::endl;
    std::cout << "unsigned char: " << sizeof(unsigned char) << std::endl;

    short variable = 100;
    // .....
    variable = variable + 1;
}