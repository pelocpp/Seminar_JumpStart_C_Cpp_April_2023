#include <iostream>
#include <iomanip>

#include "Common.h"

// Structs // Struktur

struct Time
{
    int second;
    int minute;
    int hour;
};

void printTime(Time time)
{
    std::cout 
        << std::setw(2) << std::setfill('0') << time.hour << ":"
        << std::setw(2) << std::setfill('0') << time.minute << ":"
        << std::setw(2) << std::setfill('0') << time.second << std::endl;
}

// increment the second by 1
// 15:54:58 ====> 15:54:59  ===> 15:55:00#

void increment (Time* time)
{
   // very, very simple - mostly wrong
    //time.second += 1;

    // Syntax:
    // Variant A)

    // (*time).second++;
    // or
    // (*time).second = (*time).second + 1;

    // Variant B)

    // time->second = time->second + 1;
    // or

    time->second++;
}


void main_structs_01()
{
    Time now;

    now.hour = 15;
    now.minute = 56;
    now.second = 30;

    printTime(now);

    increment(& now);

    printTime(now);
}

void main_structs()
{
    main_structs_01();
}