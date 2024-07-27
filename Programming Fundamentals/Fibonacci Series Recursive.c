#include <stdio.h>
#include <stdlib.h>

int calculateFibonacci(int num)
{
    if (num < 0)
    {
        printf("Invalid input! Please enter a positive value.\n");
        exit(0);
    }

    // Base Case
    if (num <= 1)
    {
        return num;
    }
    else
    {
        return calculateFibonacci(num - 1) + calculateFibonacci(num - 2);
    }
}

int main()
{
    int n;

    printf("Enter the number of Fibonacci numbers to be printed: ");
    scanf("%d", &n);

    printf("\nFibonacci series: ");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", calculateFibonacci(i));
    }

    printf("\n");
}