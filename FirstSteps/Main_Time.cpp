#include "Time.h"

void main_time()
{
    Time now;
    // now.m_hours = 99999;

    now.setHours(10);
    now.print();

    Time nextBreak (9999, 30, 0);
}

void main_break()
{
    Time now (11,15, 0);

    Time distanceToBreak(1, 0, 0);

  //  now.add1(distanceToBreak);

        // or

    Time whenDoesHeFinish = now.add4(distanceToBreak);


}