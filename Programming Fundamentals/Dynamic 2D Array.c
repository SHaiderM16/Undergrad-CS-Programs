#include <stdio.h>
#include <stdlib.h>

int main() {
	int rows, columns;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    int** ptr = (int**) calloc(rows, sizeof(int*));

    for (int i = 0; i < rows; i++)
    {
        *(ptr + i) = (int*) calloc(columns, sizeof(int));
    }
    
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Enter element in row %d, column %d: ", i + 1, j + 1);
            scanf("%d", (*(ptr + i) + j));
        }     
    printf("\n");   
    }

    printf("\nEntered 2D array:\n");
	for(int i = 0 ; i < rows; i++)
	{
		for(int j = 0 ; j < columns; j++)
		{
			printf("%d ", *(*(ptr + i) + j));
		}
		printf("\n");
	}

    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < columns; j++) {
            rowSum = rowSum + *(*(ptr + i) + j);
        }
        printf("Row #%d Sum = %d\n", i + 1, rowSum);
    }

    for (int j = 0; j < columns; j++) {
        int columnSum = 0;
        for (int i = 0; i < rows; i++) {
            columnSum = columnSum + *(*(ptr + i) + j);
        }
        printf("Column #%d Sum = %d\n", j + 1, columnSum);
    }

    for (int i = 0; i < rows; i++)
    {
        free(*(ptr + i));
    }
    free(ptr);
}