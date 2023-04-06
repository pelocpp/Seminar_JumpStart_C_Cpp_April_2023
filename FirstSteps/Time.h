// Header File of a Class
#include <iostream>
#include <iomanip>

#pragma once

// Description of a Class

class Time
{
private:
    int m_hours;
    int m_minutes;
    int m_seconds;

public:
    // constructors 
    Time();
    Time(int hours, int minutes, int seconds);

public:
    // setter / getter
    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);

    int getHours() const { return m_hours; }
    int getMinutes() const { return m_minutes; }
    int getSeconds() const { return m_seconds; }

public:
    void print();

    // DESIGN: add -  mutable variant
    void add1(Time t);

    // DESIGN: OR - immutable variant
    Time add2(Time t) const;

    //  Pointers vs References
    Time add3(Time* t) const;
    Time add4(const Time& t) const;
};