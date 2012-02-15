//      Author: jschueths
// Description: A library to deal with timing code. Really just a simplification for use.

#ifndef __TIMER_H__
#define __TIMER_H__

#include <iostream>
#include <ctime>
#include <vector>

using std::ostream;
using std::vector;
using std::endl;
using std::cerr;

class Timer;

ostream& operator<<(ostream &out, const Timer &data);

class Timer
{
  public:
    Timer();
    Timer(long double x);
    void start();
    void end();
    bool expired();
    void lap(); // Right now doesn't do anything.
    friend ostream& operator<<(ostream &out, const Timer &data);
  
  private:
    clock_t m_start;
    clock_t m_end;
    bool m_expired;
    bool m_up;
    bool m_stopped;
    long double m_duration;
    vector<clock_t> m_laps;
};

#include "timer.hpp"
#endif
