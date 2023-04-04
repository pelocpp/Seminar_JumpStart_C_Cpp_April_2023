#include <iostream>

#pragma warning( disable : 6386 )

// same name allowed - if parameter list are distinct
// overloading functions

bool splitNumber(int number, int* buffer, int length);

int* splitNumber(int number, int* solutionLength);

int numDigits(int number);

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

    // is buffer large enough?
    if (count >= length) {
        return false;
    }

    // split number
    int index = 0;

    while (number != 0) {

        int digit = number % 10;
        
        number = number / 10;

        buffer[index] = digit;
        index++;
    }

    return true;
}

int* splitNumber(int number, int* solutionLength)
{
    int count = numDigits(number);

    int* buffer = new int[count];

    *solutionLength = count;

    // split number
    int index = 0;

    while (number != 0) {

        int digit = number % 10;

        number = number / 10;

        buffer[index] = digit;

        index++;
    }

    // delete[] buffer;

    return buffer;
}

void test_static_style()
{
    int buffer[5] = { -1, -1, -1, -1, -1 };   // 5 digits

    bool success = splitNumber(999, buffer, 5);

    if (success) {

        for (int i = 0; i < 5; ++i) {

            if (buffer[i] == -1) {
                break;
            }

            std::cout << i << ": " << buffer[i] << std::endl;
        }
    }
    else {

        std::cout << "Error: Buffer too small" << std::endl;
    }
}


void test_dynamic_style()
{
    int bufferLength = 0;

    int* buffer = splitNumber(885511, &bufferLength);

    for (int i = 0; i < bufferLength; ++i) {
        std::cout << i << ": " << buffer[i] << std::endl;
    }

    delete[] buffer;
}

void test_dynamic_vs_static()
{
    test_static_style();

    std::cout << std::endl;

    test_dynamic_style();
}
