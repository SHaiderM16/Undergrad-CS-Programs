#include <stdio.h>
int main()
{
	float TotalHours, TotalDistance, AvgSpeed;
	
	printf("Enter the number of hours travelled: ");
	scanf("%f", &TotalHours);
	
	printf("Enter the total distance covered: ");
	scanf("%f", &TotalDistance);
	
	AvgSpeed = TotalDistance / TotalHours;
	
	printf("The average speed of the journey is = %.2f km per hour",AvgSpeed);
}