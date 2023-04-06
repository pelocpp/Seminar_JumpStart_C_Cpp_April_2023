#include <iostream>
#include <iomanip>

#include "Time.h"

// Implementation of class Time

Time::Time()
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
}

Time::Time(int hours, int minutes, int seconds) : Time ()
{
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}


void Time::print()
{
    std::cout
        << std::setw(2) << std::setfill('0') << m_hours << ":"
        << std::setw(2) << std::setfill('0') << m_minutes << ":"
        << std::setw(2) << std::setfill('0') << m_seconds << std::endl;
}

void Time::setHours(int hours)
{
    // validate the parameter
    if (hours >= 0 && hours < 24) {

        m_hours = hours;
    }
    else {
        // Silent Error Recovery
        std::cout << "Wrong value: " << hours << std::endl;
    }
}

void Time::setMinutes(int minutes)
{
    // validate the parameter
    if (m_minutes >= 0 && minutes < 60) {

        m_minutes = minutes;
    }
    else {
        // Silent Error Recovery
        std::cout << "Wrong value: " << minutes << std::endl;
    }
}

void Time::setSeconds(int seconds)
{
    // validate the parameter
    if (seconds >= 0 && seconds < 60) {

        m_seconds = seconds;
    }
    else {
        // Silent Error Recovery
        std::cout << "Wrong value: " << seconds << std::endl;
    }
}

// mutable // current object can be changed / modified
void Time::add1(Time t)
{
    // No overflow implemented :(
    //
    m_hours = m_hours + t.m_hours;
    m_minutes = m_minutes + t.m_minutes;
    m_seconds = m_seconds + t.m_seconds;
}

// immutable // current object cannot be changed / modified with this method
Time Time::add2( Time t ) const
{
    Time result;

    result.m_hours = this->m_hours + t.m_hours;
    result.m_minutes = this->m_minutes + t.m_minutes;
    result.m_seconds = this->m_seconds + t.m_seconds;

    return result;
}

// Style: C
Time Time::add3(Time* t) const
{
    Time result;

    result.m_hours = this->m_hours + t->m_hours;
    result.m_minutes = this->m_minutes + t->m_minutes;
    result.m_seconds = this->m_seconds + t->m_seconds;

    return result;
}

// Style: C++
Time Time::add4(const Time& t) const
{
    Time result;

   // t.m_hours = 12;

    result.m_hours =   this->m_hours + t.m_hours;
    result.m_minutes = this->m_minutes + t.m_minutes;
    result.m_seconds = this->m_seconds + t.m_seconds;

    return result;
}

// ======================================================

//Time Time::operator+ (const Time& other) const
//{
//    Time result;
//
//    // There is no Overflow handled
//    // Left as exercise to you
//    result.m_hours = this->m_hours + other.m_hours;
//    result.m_minutes = this->m_minutes + other.m_minutes;
//    result.m_seconds = this->m_seconds + other.m_seconds;
//
//    return result;
//}

Time operator+ (const Time& t1, const Time& t2)
{
    Time result;

    // There is no Overflow handled
    // Left as exercise to you
    result.m_hours = t1.m_hours + t2.m_hours;
    result.m_minutes = t1.m_minutes + t2.m_minutes;
    result.m_seconds = t1.m_seconds + t2.m_seconds;

    return result;
}

//Time operator+ (const Time& t1, const Time& t2)
//{
//    // There is no Overflow handled
//    // Left as exercise to you
//    int hours = t1.getHours() + t2.getHours();
//    int minutes = t1.getMinutes() + t2.getMinutes();
//    int seconds = t1.getSeconds() + t2.getSeconds();
//
//    Time result (hours, minutes, seconds);
//    return result;
//
//    // return Time (hours, minutes, seconds);
//}