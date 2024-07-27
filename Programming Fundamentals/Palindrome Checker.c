#include <stdio.h>
#include <string.h>

int isPalindrome(int num) {
    int originalNum = num, reversedNum = 0, digit;

    while (num > 0) {
        digit = num % 10;
        reversedNum = (reversedNum * 10) + digit;
        num = num / 10;
    }

    if (originalNum == reversedNum) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int inputNum;

    printf("Enter the number: ");
    scanf("%d", &inputNum);

    if (isPalindrome(inputNum) == 1) {
        printf("\n%d is a palindrome\n", inputNum);
    }
    else {
        printf("\n%d is not a palindrome\n", inputNum);
    }
}