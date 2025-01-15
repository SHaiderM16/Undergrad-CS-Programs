#include <iostream>
using namespace std;

extern "C" void GCD();

int main()
{
    int inputInteger1, inputInteger2, outputGCD;
    cout << "Enter first number: ";
    cin >> inputInteger1;
    cout << "Enter second number: ";
    cin >> inputInteger2;

    // If either input is negative then reverse sign
    if (inputInteger1 < 0)
    {
        inputInteger1 = -inputInteger1;
    }
    if (inputInteger2 < 0)
    {
        inputInteger2 = -inputInteger2;
    }

    _asm
        {
        MOV EAX, inputInteger1
        MOV EBX, inputInteger2

        CALL GCD

        MOV outputGCD, EAX
        }

    cout << "\nGCD: " << outputGCD << "\n";

    return 0;
}