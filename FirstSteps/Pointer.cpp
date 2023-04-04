#include <iostream>

void main_pointer_01()
{
    std::cout << "Pointer:" << std::endl;

    int n;
    int value = 123;

    n = value;   // direct access

    int* ip;

    ip = & n;      // give me the address / reference n

                   // indirect access

    int m = *ip;   // give me the value behind the address of  a pointer
                   // dereference the pointer

    //int** ipp;
    //ipp = &ip;

    // void* vp;
}

void doesSomething01(int x, int y)
{
    int tmp;

    tmp = x;
    x = y;
    y = tmp;
}

void doesSomething02(int* x, int *y)
{
    int tmp;

    tmp = *x;

    *x = *y;
    
    *y = tmp;
}

void callingDoesSomething()
{
    int n = 5;
    int m = 6;

    std::cout << n << ", " << m << std::endl;

    doesSomething01(n, m);

    doesSomething02(& n, & m);

    std::cout << n << ", " << m << std::endl;

}

void main_pointer()
{
    main_pointer_01();
}