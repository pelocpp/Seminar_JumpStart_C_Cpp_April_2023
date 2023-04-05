#include <iostream>
#include <algorithm>
#include <vector>

// ===================================================

// function prototypes
void setBit(int* value, int position);
void clearBit(int* value, int position);
void setBit(int value, int position);
void clearBit(int value, int position);

// helper functions
// at position: == 1
bool isBitSet(int value, int position);

// at position: == 0
bool isBitCleared(int value, int position);

int countOnes(int value);
int countZeros(int value);

void powerOfTwo();
void printIntAsBinary(int value);

void low_level_01_set_clear_bit();
void low_level_02_set_clear_bit();
void low_level_03_count_ones_and_zeros();
void low_level_04_print_binary();
void low_level_05_testPowerOfTwo();
void low_level_06_testSignedVsUnsignedShift();

// ===================================================

void setBit(int* value, int position)
{
    unsigned int mask = 1 << position;

    *value = *value | mask;
}

void clearBit(int* value, int position)
{
    unsigned int mask = ~(1 << position);

    *value = *value & mask;
}

void setBit(int value, int position)
{
    std::cout << value << std::endl;

    unsigned int mask = 1 << position;

    value = value | mask;

    std::cout << value << std::endl;
}

void clearBit(int value, int position)
{
    std::cout << value << std::endl;

    unsigned int mask = ~(1 << position);

    value = value & mask;

    std::cout << value << std::endl;
}

bool isBitSet(int value, int position)
{
    unsigned int mask = 1;

    mask = mask << position;

    // 10101 101010
    // 00000 100000
    // ------------
    // 00000 100000

    unsigned int tmp = value & mask;

    if (tmp != 0) {
        return true;
    }
    else {
        return false;
    }
}


bool isBitCleared(int value, int position)
{
    unsigned int mask = 1;

    mask = mask << position;

    // 10101 001010     // 0 & 1  ==> 0
    // 00000 100000     // 1 & 1  ==> 1
    // ------------
    // 00000 100000

    unsigned int tmp = value & mask;

    if (tmp == 0) {
        return true;
    }
    else {
        return false;
    }
}

void low_level_01_set_clear_bit()
{
    // test setBit
    int number = 33;
    std::cout << number << std::endl;
    setBit(&number, 4);
    std::cout << number << std::endl;

    // test clearBit
    number = 33;
    clearBit(&number, 4);
    std::cout << number << std::endl;
}

void low_level_02_set_clear_bit()
{
    setBit(33, 4);
    clearBit(49, 4);
}

// ===================================================

int countOnes(int value)
{
    int result = 0;

    // word size in bits
    int numBits = 8 * sizeof(int);

    unsigned int mask = 1;

    do
    {
        int tmp = value & mask;

        if (tmp != 0) {
            result++;
        }

        //if ((value & mask) != 0) {
        //    result++;
        //}

        --numBits;

        mask = mask << 1;

    } while (numBits != 0);

    return result;
}

int countOnesEx(int value)
{
    int result = 0;

    // word size in bits
    int numBits = 8 * sizeof(int);   // int ==> sizeof(int) = 4
                                     // 8 * 4 == 32 : number bits

    unsigned int mask = 1;

    for (int pos = 0; pos < numBits; ++pos) {

        if (isBitSet(value, pos)) {
            ++result;
        }
    }

    return result;
}

int countZeros(int value)
{
    int result = 0;

    // word size in bits
    int numBits = 8 * sizeof(int);

    unsigned int mask = 1;

    do
    {
        int tmp = value & mask;

        if (tmp == 0) {
            result++;
        }

        --numBits;

        mask = mask << 1;

    } while (numBits != 0);

    return result;
}

int countZerosEx(int value)
{
    int result = 0;

    // word size in bits
    int numBits = 8 * sizeof(int);

    unsigned int mask = 1;

    for (int pos = 0; pos < numBits; ++pos) {

        if (isBitCleared(value, pos)) {
            ++result;
        }
    }

    return result;
}

void low_level_03_count_ones_and_zeros()
{
    int value = 7;
    int count = countOnes(value);
    std::cout << "1's found in " << value << ": " << count << std::endl;

    value = -1;
    count = countOnes(value);
    std::cout << "1's found in " << value << ": " << count << std::endl;

    value = 7;
    count = countZeros(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;

    value = -1;
    count = countZeros(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;

    value = 0;
    count = countZeros(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;
}

void low_level_03_count_ones_and_zeros_ex()
{
    int value = 7;
    int count = countOnesEx(value);
    std::cout << "1's found in " << value << ": " << count << std::endl;

    value = -1;
    count = countOnesEx(value);
    std::cout << "1's found in " << value << ": " << count << std::endl;

    value = 7;
    count = countZerosEx(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;

    value = -1;
    count = countZerosEx(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;

    value = 0;
    count = countZerosEx(value);
    std::cout << "0's found in " << value << ": " << count << std::endl;
}

// ===================================================

void printIntAsBinary(int value)
{
    // word size in bits
    int numBits = 8 * sizeof(int);

    // create initial mask: 1 in leftmost position
    unsigned int mask = 1 << (numBits - 1);

    for (int i = 0; i < numBits; ++i)
    {
        int bit = 0;
        
        if ((value & mask) != 0) {
            bit = 1;
        }

        std::cout << bit;

        // print blank after every 4th digit
        if ((i+1) % 4 == 0) {
            std::cout << ' ';
        }

        // shift mask 1 position to the right
        mask = mask >> 1;
    }
}

void low_level_04_print_binary()
{
    printIntAsBinary(7);
    std::cout << std::endl;

    printIntAsBinary(-1);
    std::cout << std::endl;

    printIntAsBinary(2'147'483'647);
    std::cout << std::endl;

    printIntAsBinary(-2'147'483'648);
    std::cout << std::endl;
}

// ===================================================

void powerOfTwo()
{
    // word size in bits
    int numBits = 8 * sizeof(int);

    // create initial mask: 1 in leftmost position
    unsigned int mask = 1;

    do
    {
        std::cout << mask << std::endl;

        mask = mask << 1;

        --numBits;

    } while (numBits != 0);
}

void low_level_05_testPowerOfTwo()
{
    powerOfTwo();
}

// ===================================================

void low_level_06_testSignedVsUnsignedShift()
{
    // create initial mask: 1 in leftmost position
    // note: study output of this program using 'int' vs 'unsigned int' mask
    unsigned int mask = 1 << 31;
    std::cout << mask << std::endl;

    // shift mask 1 position to the right
    mask = mask >> 1;
    std::cout << mask << std::endl;

    // shift mask 1 position to the right
    mask = mask >> 1;
    std::cout << mask << std::endl;

    // shift mask 1 position to the right
    mask = mask >> 1;
    std::cout << mask << std::endl;
}

// ===================================================

void exercise_low_level()
{
    //low_level_01_set_clear_bit();
    //low_level_02_set_clear_bit();
    //low_level_03_count_ones_and_zeros();
   low_level_04_print_binary();
    //low_level_05_testPowerOfTwo();
    //low_level_06_testSignedVsUnsignedShift();

    //low_level_03_count_ones_and_zeros();
    //std::cout << std::endl;
    //low_level_03_count_ones_and_zeros_ex();
}

// ===================================================
