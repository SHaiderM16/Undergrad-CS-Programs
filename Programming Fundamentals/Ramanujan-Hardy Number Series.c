#include <stdio.h>

void main() {
    int n;
    printf("Enter the number that, when cubed, is the upper limit of Ramanujan-Hardy number series: ");
    scanf("%d", &n);

	printf("\n");
    for (int i = 1; i <= n * n * n; i++) {
        int count = 0;

        for (int x = 1; x * x * x <= i; x++) {
            for (int y = x; y * y * y <= i; y++) {
                if (x * x * x + y * y * y == i) {
                    count = count + 1;
                    if (count == 2) {
                        printf("%d, ", i);
                        break;
                    }
                }
            }
            if (count == 2) {
                break;
            }
        }
    }
    printf("\n");
}