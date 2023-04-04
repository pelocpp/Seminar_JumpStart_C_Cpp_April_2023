#include <iostream>

bool splitNumber(int number, int* buffer, int length);

int* splitNumber(int number, int* solutionLength);

int numDigits();

int numDigits(int number)
{
    int count = 1;

    while (number / 10 != 0) {

        count++;
        number /= 10;
    }

    return count;
}

bool splitNumber(int number, int* buffer, int length)
{
    int count = numDigits(number);

    // split numer

}

void test_static_style()
{
    int r = numDigits(123);
}

void test_dynamic_style()
{

}

void test_dynamic_vs_static()
{
    test_static_style();
}


