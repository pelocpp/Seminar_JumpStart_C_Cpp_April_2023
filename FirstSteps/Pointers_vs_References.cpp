#include <iostream>

void multiplyByTwo_01(int value)
{
    value = 2 * value;
}

// pointer style
void multiplyByTwo_02(int* pvalue)
{
    *pvalue = 2 * *pvalue;
}

// reference style
void multiplyByTwo_03(int& value)
{
    value = 2 * value;
}

void main_pointers_vs_references()
{
    int n = 100;

    std::cout << n << std::endl;

    multiplyByTwo_01(n);

    std::cout << n << std::endl;

    multiplyByTwo_02(&n);  // pointer

    std::cout << n << std::endl;

    multiplyByTwo_03(n);   // reference

    std::cout << n << std::endl;
}

// Comparison: Pointers and References
void main_pointers_vs_references_02()
{
    int n = 123;

    // pointer
    int* ip;
    ip = &n;

    // using the pointer (increment n by one)
    (*ip)++;

    // Using ip with ++:  "Pointer Arithmetic"
    ip++;     // new ..... new and array
    (*ip)++;

    // reference
    int& ri = n;

    // using the reference (increment n by one)
    ri++;
}