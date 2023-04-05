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

void incrementEx(Time* time)
{
    time->second++;

    if (time->second >= 60)
    {
        time->second = 0;
        time->minute++;

        if (time->minute >= 60)
        {
            time->minute = 0;
            time->hour++;

            if (time->hour >= 24)
            {
                time->hour = 0;
            }
        }
    }
}

bool lessThan(Time* t1, Time* t2)
{
    if (t1->hour < t2->hour) {
        return true;
    }
    else if (t1->hour == t2->hour && t1->minute < t2->minute) {
        return true;
    }
    else if (t1->hour == t2->hour && t1->minute == t2->minute && t1->second < t2->second)
    {
        return true;
    }
    else {
        return false;
    }
}

// Amount of seconds of a Time variable
int timeToSeconds(Time* t)
{
    return t->hour * 3600 + t->minute * 60 + t->second;
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