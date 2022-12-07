#include "timer.h"
timer::timer() 
{
    running = false;
}

timer::timer(timer& t) 
{
    running = t.running;
    start_time = t.start_time;
    stop_time = t.stop_time;
}

void timer::start() 
{
    if (!running) 
    {
        running = true;
        start_time = steady_clock::now();
    }
}

void timer::stop() 
{
    if (running) 
    {
        running = false;
        stop_time = steady_clock::now();
    }
}

double timer::getTime() 
{
    return duration_cast<duration<double> >(stop_time - start_time).count();
}

ostream& operator<<(ostream& out, timer& t) {
    return out << to_string(t.getTime());
}