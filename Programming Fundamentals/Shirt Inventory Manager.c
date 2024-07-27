#include <stdio.h>

void main() {
    int totalShirts;

    printf("Enter the number of shirts: ");
    scanf("%d", &totalShirts);

    int ages[totalShirts][1];
    int prices[totalShirts][1];

    printf("\n");
    for (int i = 0; i < totalShirts; i++) {
        printf("Enter age of shirt %d: ", i + 1);
        scanf("%d", &ages[i][0]);
        printf("Enter the price of shirt %d: ", i + 1);
        scanf("%d", &prices[i][0]);
        printf("\n");
    }

    for (int i = 0; i < totalShirts - 1; i++) {
        for (int j = 0; j < totalShirts - i - 1; j++) {
            if (ages[j][0] > ages[j + 1][0]) {
                int tempAge = ages[j][0];
                ages[j][0] = ages[j + 1][0];
                ages[j + 1][0] = tempAge;
            }
        }
    }

    for (int i = 0; i < totalShirts - 1; i++) {
        for (int j = 0; j < totalShirts - i - 1; j++) {
            if (prices[j][0] < prices[j + 1][0]) {
                int tempPrice = prices[j][0];
                prices[j][0] = prices[j + 1][0];
                prices[j + 1][0] = tempPrice;
            }
        }
    }

    printf("\nList (ascending) with respect to age:\n");
    for (int i = 0; i < totalShirts; i++) {
        printf("Shirt %d: Age = %d\n", i + 1, ages[i][0]);
    }

    printf("\nList (descending) with respect to price:\n");
    for (int i = 0; i < totalShirts; i++) {
        printf("Shirt %d: Price = %d\n", i + 1, prices[i][0]);
    }
}