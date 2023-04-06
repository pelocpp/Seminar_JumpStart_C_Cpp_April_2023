#include <iostream>
#include <bitset>

void low_level_01_bitwise_and()
{
    unsigned short word1 = 0b1011'0011;
    unsigned short word2 = 0b1100'1101;

    unsigned short word = word1 & word2;

    std::bitset<16> bs1(word1);
    std::bitset<16> bs2(word2);
    std::bitset<16> bs (word);

    std::cout << word1 << std::endl;
    std::cout << word2 << std::endl;
    std::cout << word << std::endl;

    std::cout << bs1 << std::endl;
    std::cout << bs2 << std::endl;
    std::cout << bs << std::endl;
}

void low_level_02_bitwise_or()
{
    unsigned short word1 = 0b1011'0011;
    unsigned short word2 = 0b1000'1101;

    unsigned short word = word1 | word2;

    std::bitset<16> bs1(word1);
    std::bitset<16> bs2(word2);
    std::bitset<16> bs(word);

    std::cout << word1 << std::endl;
    std::cout << word2 << std::endl;
    std::cout << word << std::endl;

    std::cout << bs1 << std::endl;
    std::cout << bs2 << std::endl;
    std::cout << bs << std::endl;
}

void low_level_03_bitwise_xor()
{
    unsigned short word1 = 0b1011'0011;
    unsigned short word2 = 0b1000'1101;

    unsigned short word = word1 ^ word2;

    std::bitset<16> bs1(word1);
    std::bitset<16> bs2(word2);
    std::bitset<16> bs(word);

    std::cout << word1 << std::endl;
    std::cout << word2 << std::endl;
    std::cout << word << std::endl;

    std::cout << bs1 << std::endl;
    std::cout << bs2 << std::endl;
    std::cout << bs << std::endl;
}

void low_level_04_bitwise_negate()
{
    unsigned short word = 0b1011'0011;

    unsigned short wordNegated = ~ word;

    std::bitset<16> bsWord(word);
    std::bitset<16> bsWordNegated(wordNegated);

    std::cout << word << std::endl;
    std::cout << wordNegated << std::endl;

    std::cout << bsWord << std::endl;
    std::cout << bsWordNegated << std::endl;
}

void low_level_05_bitwise_negate()
{
    unsigned char byte = 0b0010'0011;
    std::bitset<8> bs(byte);

    unsigned char byteShifted = byte << 1;
    std::bitset<8> bsShifted(byteShifted);

    std::cout << byte << std::endl;
    std::cout << byteShifted << std::endl;

    std::cout << bs << std::endl;
    std::cout << bsShifted << std::endl;
}

void main_low_level_06_unsigned()
{
    unsigned char byte = 0b1010'0011;
    std::bitset<8> bs(byte);

    unsigned char byteShifted = byte >> 1;
    std::bitset<8> bsShifted(byteShifted);

    std::cout << byte << std::endl;
    std::cout << byteShifted << std::endl;

    std::cout << bs << std::endl;
    std::cout << bsShifted << std::endl;
}

void main_low_level_07_signed()
{
    signed char byte = 0b0010'0011;
    std::bitset<8> bs(byte);

    signed char byteShifted = byte >> 1;
    std::bitset<8> bsShifted(byteShifted);

    std::cout << byte << std::endl;
    std::cout << byteShifted << std::endl;

    std::cout << bs << std::endl;
    std::cout << bsShifted << std::endl;
}

// ===========================================

void setBit(unsigned short value, int pos)
{
    unsigned short mask = 1 << pos;

    value = value | mask;
}

void setBitEx(unsigned short* value, int pos)
{
    unsigned short mask = 1 << pos;

    *value = *value | mask;
}

void main_low_level_08_setBit()
{
    unsigned short s = 0b1011'0011;
    std::bitset<16> bsBefore(s);
    std::cout << bsBefore << std::endl;

    setBitEx(&s, 3);

    std::bitset<16> bsAfter(s);
    std::cout << bsAfter << std::endl;
}

// ===========================================

void clearBit(unsigned short value, int pos)
{
    unsigned short mask = 1 << pos;
    mask = ~ mask;

    // or 

    // unsigned short mask = ~ (1 << pos);

    value = value & mask;
}


void clearBitEx(unsigned short* value, int pos)
{
    unsigned short mask = 1 << pos;

    mask = ~mask;

    // or 

    // unsigned short mask = ~ (1 << pos);

    *value = *value & mask;
}


void main_low_level_09_clearBit()
{
    unsigned short s = 0b1011'0111;
    std::bitset<16> bsBefore(s);
    std::cout << bsBefore << std::endl;

    clearBitEx(& s, 2);

    std::bitset<16> bsAfter(s);
    std::cout << bsAfter << std::endl;
}

// ===========================================


// ===========================================

void main_low_level()
{
    main_low_level_09_clearBit();
}