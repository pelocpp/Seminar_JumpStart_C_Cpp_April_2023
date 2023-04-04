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
    srand( (unsigned int) time(0));  // just call ONCE

    int numbers[SIZE];

    initArray(numbers, 2 * SIZE);

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
        // exercising purposes
        * (arr + i) = (rand() % 100) + 1;

        arr[i] = (rand() % 100) + 1;
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
    //int minimum = 200;  // a better choice: 
    //                    // Largest possible integer

    //for (int i = 0; i < length; ++i)
    //{
    //    if (arr[i] < minimum) {
    //        minimum = arr[i];
    //    }
    //}

    int minimum = arr[0];

    for (int i = 1; i < length; ++i)
    {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    return minimum;
}

int maximumArray(int* arr, int length)
{
    int maximum = arr[0];

    for (int i = 1; i < length; ++i)
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
        // arithmetic - assignment operator

        // average = average + arr[i];
        average += arr[i];
    }

    average /= length;
    // or
    //average = average / length;

    return average;
}









