#include <iostream>
using namespace std;
bool checkprime(unsigned int p) 
{
    if (p <= 1) 
        return false;
    if (p == 2) 
        return true;
    if (p % 2 == 0) 
        return false;
    for (int i = 3; i*i <= p; i += 2)
        if (p % i == 0)
            return false;
    return true;
}

int getNextPrime (unsigned int n) 
{
    while (!checkprime(++n));
    return n;
}

int main() 
{
    int x;
    cout << "Enter number: ";
    cin >> x;
    cout << x << " is prime: " << checkprime(x) << endl;
    cout << "next higest prime: " << getNextPrime(x) << endl;
}