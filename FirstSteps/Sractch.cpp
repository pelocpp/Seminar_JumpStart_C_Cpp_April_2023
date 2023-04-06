#include <iostream>
#include <iomanip>

struct Time
{
    int second;
    int minute;
    int hour;

    // C++
    void decrement( /* this */ )
    {
        this->second++;
        second++;
    }

    // Python
    //void decrement ( self )
    //{
    //    this->second++;
    //    second++;
    //}
};

void decrement(Time* time)
{
    time->second++;
}

void scratch()
{
    // NON   OO Programming
    Time now;
    decrement(&now);

    //   OO Programming
    now.decrement();

    decrement( & now );   // View after Compile
}