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

void main_low_level()
{
    main_low_level_04();
}