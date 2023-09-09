#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c, BracketTerm;
	float SqrtTerm, Root1, Root2;
	printf("As part of quadratic equation, enter term a: ");
	scanf("%d", &a);
	printf("Enter term b: ");
	scanf("%d", &b);
    printf("Enter term c: ");
    scanf("%d", &c);
    BracketTerm = (b*b) - (4*a*c);
    SqrtTerm = sqrt(BracketTerm);
    Root1 = (-b + SqrtTerm) / (2.0 * a);
    Root2 = (-b - SqrtTerm) / (2.0 * a);
    printf("The roots of the quadratic equation are %.2f",Root1);
    printf(" and %.2f",Root2);
}