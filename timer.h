#ifndef TIMER_H
#define TIMER_H
#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;
class timer 
{
    public:
        timer();
        timer(timer& myTimer);
        void start();
        void stop();
        double getTime();

    private:
        steady_clock::time_point start_time, stop_time;
        bool running;
};
ostream& operator<<(ostream& theStream, timer& theTimer);
#endif