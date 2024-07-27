#include <stdio.h>

int iterativeGCD(int a, int b)
{
    if (a < 0)
    {
        a = -a;
    }
    if (b < 0)
    {
        b = -b;
    }

    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int recursiveGCD(int a, int b)
{
    if (a < 0)
    {
        a = -a;
    }
    if (b < 0)
    {
        b = -b;
    }

    // Base Case
    if (b == 0)
    {
        return a;
    }
    else
    {
        return recursiveGCD(b, a % b);
    }
}

int main()
{
    int inputNum1, inputNum2;

    printf("Enter first number: ");
    scanf("%d", &inputNum1);

    printf("Enter second number: ");
    scanf("%d", &inputNum2);

    int gcdLoop = iterativeGCD(inputNum1, inputNum2);
    printf("\nThe GCD of %d and %d using loops is %d\n", inputNum1, inputNum2, gcdLoop);

    int gcdRecursion = recursiveGCD(inputNum1, inputNum2);
    printf("\nThe GCD of %d and %d using recursion is %d\n", inputNum1, inputNum2, gcdRecursion);
}