#include <iostream>
#include <cstdlib>

#define SIZE 10

void main_arrays_exercise();
void initArray(int* arr, int length);
void outputArray(int* arr, int length);
int  minimumArray(int* arr, int length);
int  maximumArray(int* arr, int length);
int  averageArray(int* arr, int length);

void main_arrays_exercise()
{
    // Startvalue
    srand( (unsigned int)  time(0));  // just call ONCE

    int numbers[SIZE];

    initArray(numbers, SIZE);

    outputArray(numbers, SIZE);

    int minimum = minimumArray(numbers, SIZE);
    std::cout << "Minimum: " << minimum << std::endl;

    int maximum = maximumArray(numbers, SIZE);
    std::cout << "Maximum: " << maximum << std::endl;

    int average = averageArray(numbers, SIZE);
    std::cout << "Average: " << average << std::endl;
}

void initArray(int* arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        arr [i] = (rand() % 100) + 1;
    }
}

void outputArray(int* arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int minimumArray(int* arr, int length)
{
    int minimum = 200;

    for (int i = 0; i < length; ++i)
    {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    return minimum;
}

int maximumArray(int* arr, int length)
{
    int maximum = -1;

    for (int i = 0; i < length; ++i)
    {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }

    return maximum;
}

int averageArray(int* arr, int length)
{
    int average = 0;

    for (int i = 0; i < length; ++i)
    {
        average += arr[i];
    }

    average = average / length;

    return average;
}









