#include <iostream>
#include "timer.h"
using namespace std;
int main (void) 
{
    timer t;
    t.start();
    for (int i = 0; i < 1000000000; i++) {}
    t.stop();
    cout << t << endl;
    cout << t.getTime() << endl;
}