#include <stdio.h>
int main()
{
	int UserSalary, TaxAmount, NetIncome;
	float TaxRate;
	
	printf("Enter your salary: ");
	scanf("%d", &UserSalary);
	
	printf("Enter the tax rate: ");
	scanf("%f", &TaxRate);
	
	TaxAmount = UserSalary * (TaxRate/100);
	NetIncome = UserSalary - TaxAmount;
	
	printf("After tax deduction, your net income is %d", NetIncome);
}
