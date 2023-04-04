#include <iostream>
#include <cstdlib>

void pointer_dynamic_array ()
{
    std::cout << "Pointer Dynamic:" << std::endl;

    int* ip;

    int n = 10;
    std::cin >> n;
    ip = new int [n];   // new allows content of n
                        // provided at runtime

    int array[10];     // static array / compile time

    // -----------------------------------------------

    for (int i = 0; i < n; ++i) {

        *(ip + i) = 123;
        // OR
        ip[i] = 123;
    }

    delete[] ip;
}





void pointer_dynamic()
{
    std::cout << "Pointer Dynamic:" << std::endl;

    int* ip;

    ip = new int;

    delete ip;
}


void usingPointer(int* p)
{
    *p = 456;

    delete p;
}

void pointer_dynamic_02()
{
    std::cout << "Pointer Dynamic:" << std::endl;

    int* ip;

    ip = new int;

    *ip = 123;

    usingPointer(ip);

    delete ip;
}
