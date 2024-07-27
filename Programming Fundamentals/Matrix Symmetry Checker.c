#include <stdio.h>
int main()
{
	int rows, columns, isEqual = 1;
	
	printf("Enter the number of rows of matrix: ");
	scanf(" %d", &rows);
	printf("Enter the number of columns of matrix: ");
	scanf(" %d", &columns);
	
	int matrix[rows][columns];
	
	printf("\n");
	
	if (rows == columns) {
		for (int i = 0 ; i < rows ; i = i + 1) {
			for (int j = 0 ; j < columns ; j = j + 1) {
				printf("Enter element at coordinate[%d][%d]: ", i + 1, j + 1);
				scanf(" %d", &matrix[i][j]);
			}
		}
		
		while (isEqual == 1) {
			for (int i = 0 ; i < rows ; i = i + 1) {
				for (int j = 0 ; j < columns ; j = j + 1) {
					if (matrix[i][j] != matrix[j][i]) {
						isEqual = 0;
					}
				}
			}
			break;
		}
		
		if (isEqual == 1) {
			printf("\nArray is Symmetric\n");
		}
		else {
			printf("\narray is not symmetric\n");
		}
	}
	else {
		printf("array is not symmetric\n");
	}
}