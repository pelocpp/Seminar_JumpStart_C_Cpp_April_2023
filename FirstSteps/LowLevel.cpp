#include <iostream>
#include <bitset>

void main_low_level_01()
{
    unsigned short words1 = 0b1011'0011;
    unsigned short words2 = 0b1100'1101;
    unsigned short words = words1 & words2;

    std::bitset<16> bs1(words1);
    std::bitset<16> bs2(words2);
    std::bitset<16> bs (words);

    std::cout << words1 << std::endl;
    std::cout << words2 << std::endl;
    std::cout << words << std::endl;

    std::cout << bs1 << std::endl;
    std::cout << bs2 << std::endl;
    std::cout << bs << std::endl;
}

void main_low_level_02()
{
    unsigned short words1 = 0b1011'0011;
    unsigned short words2 = 0b1000'1101;
    unsigned short words = words1 | words2;

    std::bitset<16> bs1(words1);
    std::bitset<16> bs2(words2);
    std::bitset<16> bs(words);

    std::cout << words1 << std::endl;
    std::cout << words2 << std::endl;
    std::cout << words << std::endl;

    std::cout << bs1 << std::endl;
    std::cout << bs2 << std::endl;
    std::cout << bs << std::endl;
}

void main_low_level_03()
{
    unsigned short words1 = 0b1011'0011;
    unsigned short words2 = 0b1000'1101;
    unsigned short words = words1 ^ words2;

    std::bitset<16> bs1(words1);
    std::bitset<16> bs2(words2);
    std::bitset<16> bs(words);

    std::cout << words1 << std::endl;
    std::cout << words2 << std::endl;
    std::cout << words << std::endl;

    std::cout << bs1 << std::endl;
    std::cout << bs2 << std::endl;
    std::cout << bs << std::endl;
}

void main_low_level_04()
{
    unsigned short words = 0b1011'0011;
    unsigned short wordsNegated = ~ words;

    std::bitset<16> bs1(words);
    std::bitset<16> bs2(wordsNegated);

    std::cout << words << std::endl;
    std::cout << wordsNegated << std::endl;

    std::cout << bs1 << std::endl;
    std::cout << bs2 << std::endl;
}

void main_low_level_05()
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
    signed char byte = 0b1010'0011;
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

void main_low_level()
{
    unsigned short s = 0b1011'0011;
    std::bitset<16> bsBefore(s);
    std::cout << bsBefore << std::endl;

    setBitEx(& s, 3);

    std::bitset<16> bsAfter(s);
    std::cout << bsAfter << std::endl;

}