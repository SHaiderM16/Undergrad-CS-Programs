#include <stdio.h>
int main()
{
	int TotalAmount = 368;
	int Quarters, Dimes, Nickels, Pennies, RemainingAmount;
	
	Quarters = TotalAmount / 25;
	RemainingAmount = TotalAmount % 25;
	
	Dimes = RemainingAmount / 10;
	RemainingAmount = RemainingAmount % 10;
	
	Nickels = RemainingAmount / 5;
	Pennies = RemainingAmount % 5;
	
	printf("The best way of carrying 368 pennies is by carrying Quarters = %d\n",Quarters);
	printf("Dimes = %d\n",Dimes);
	printf("Nickels = %d\n",Nickels);
	printf("Pennies = %d",Pennies);
}
