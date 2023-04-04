#include <iostream>
#include <cstdlib>


#define SIZE 10

// pointers and arrays

// void initializeArray(int arr[], int length);

void initializeArray(int* arr, int length);


void procedureWithArray()
{
    int numbers[10];

    initializeArray(numbers, 10);  // numbers is 
                               // passed by ADDRESS

    for (int i = 0; i < 10; ++i)
    {
        std::cout << numbers[i] << " ";
    }
}

//void initializeArray(int arr[], int length)
//{
//    for (int i = 0; i < length; ++i)
//    {
//        arr[i] = i;
//    }
//}

void initializeArray(int* arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        // we can use [] notation
        arr[i] = i;

        // compiler sees address notation
        * (arr + i)  = i;
    }
}

void main_arrays_and_pointers()
{
    // Startvalue
    srand( (unsigned int) time(0));  // just call ONCE

    int n = rand();  // only returns positive numbers

    // numbers in the range of 1 up to 10
    n = (rand() % 10) + 1;

    std::cout << "Rand: " << n << std::endl;


    // procedureWithArray();
}
