/*Write a C program that takes a matrix from the user as input. The dimensions can be (2x2, 4x4, and 8x8). Make sure that your program tackles any of the dimensions. Your program should compute the max value from each 2 x 2 submatrix and save it into a new matrix.
For instance, for a 2 x 2 input matrix resultant matrix would have dimensions 1 x 1, for a 4 x 4 input matrix resultant matrix would have dimensions 2 x 2, and for 8 x 8 input matrix resultant matrix have dimensions 4 x 4.

A) Your solution must have the required functions for matrix processing.

B) Main function that operates and performs operation on the functions. Use your student id as input to the functions. E.g., 23k-1234 then your input array should have your id of 1234 repeatedly.*/

#include <stdio.h>
#include <stdlib.h>

void findMax2x2(int **matrix, int rows, int columns)
{
    int resultRows = 1, resultColumns = 1;

    int **resultMatrix = (int **)calloc(resultRows, sizeof(int *));

    for (int i = 0; i < resultRows; i++)
    {
        *(resultMatrix + i) = (int *)calloc(resultColumns, sizeof(int));
    }

    int max;

    for (int i = 0; i < rows; i = i + 2)
    {
        for (int j = 0; j < columns; j = j + 2)
        {
            max = *(*(matrix + i) + j);

            for (int k = i; k <= i + 1; k++)
            {
                for (int l = j; l <= j + 1; l++)
                {
                    if (*(*(matrix + k) + l) > max)
                    {
                        max = *(*(matrix + k) + l);
                    }
                }
            }

            *(*(resultMatrix + (i / 2)) + (j / 2)) = max;
        }
    }

    printf("\nResultant %dx%d Matrix:\n", resultRows, resultColumns);
    for (int i = 0; i < resultRows; i++)
    {
        for (int j = 0; j < resultColumns; j++)
        {
            printf("%d   ", *(*(resultMatrix + i) + j));
        }
        printf("\n");
    }

    for (int i = 0; i < resultRows; i++)
    {
        free(resultMatrix[i]);
    }
    free(resultMatrix);
}

void findMax4x4(int **matrix, int rows, int columns)
{
    int resultRows = 2, resultColumns = 2;

    int **resultMatrix = (int **)calloc(resultRows, sizeof(int *));

    for (int i = 0; i < resultRows; i++)
    {
        *(resultMatrix + i) = (int *)calloc(resultColumns, sizeof(int));
    }

    int max;

    for (int i = 0; i < rows; i = i + 2)
    {
        for (int j = 0; j < columns; j = j + 2)
        {
            max = *(*(matrix + i) + j);

            for (int k = i; k <= i + 1; k++)
            {
                for (int l = j; l <= j + 1; l++)
                {
                    if (*(*(matrix + k) + l) > max)
                    {
                        max = *(*(matrix + k) + l);
                    }
                }
            }
            *(*(resultMatrix + (i / 2)) + (j / 2)) = max;
        }
    }

    printf("\nResultant %dx%d Matrix:\n", resultRows, resultColumns);
    for (int i = 0; i < resultRows; i++)
    {
        for (int j = 0; j < resultColumns; j++)
        {
            printf("%d   ", *(*(resultMatrix + i) + j));
        }
        printf("\n");
    }

    for (int i = 0; i < resultRows; i++)
    {
        free(resultMatrix[i]);
    }
    free(resultMatrix);
}

void findMax8x8(int **matrix, int rows, int columns)
{
    int resultRows = 4, resultColumns = 4;

    int **resultMatrix = (int **)calloc(resultRows, sizeof(int *));

    for (int i = 0; i < resultRows; i++)
    {
        *(resultMatrix + i) = (int *)calloc(resultColumns, sizeof(int));
    }

    int max;

    for (int i = 0; i < rows; i = i + 2)
    {
        for (int j = 0; j < columns; j = j + 2)
        {
            max = *(*(matrix + i) + j);

            for (int k = i; k <= i + 1; k++)
            {
                for (int l = j; l <= j + 1; l++)
                {
                    if (*(*(matrix + k) + l) > max)
                    {
                        max = *(*(matrix + k) + l);
                    }
                }
            }
            *(*(resultMatrix + (i / 2)) + (j / 2)) = max;
        }
    }

    printf("\nResultant %dx%d Matrix:\n", resultRows, resultColumns);
    for (int i = 0; i < resultRows; i++)
    {
        for (int j = 0; j < resultColumns; j++)
        {
            printf("%d   ", *(*(resultMatrix + i) + j));
        }
        printf("\n");
    }

    for (int i = 0; i < resultRows; i++)
    {
        free(resultMatrix[i]);
    }
    free(resultMatrix);
}

int main()
{
    int inputRows, inputColumns;

    printf("Enter information of the matrix\n");
    printf("Enter the number of rows: ");
    scanf("%d", &inputRows);

    printf("Enter the number of columns: ");
    scanf("%d", &inputColumns);

    if (inputRows == 2 && inputColumns == 2 || inputRows == 4 && inputColumns == 4 || inputRows == 8 && inputColumns == 8)
    {
        int **inputMatrix = (int **)calloc(inputRows, sizeof(int *));

        for (int i = 0; i < inputRows; i++)
        {
            *(inputMatrix + i) = (int *)calloc(inputColumns, sizeof(int));
        }

        printf("\n");
        for (int i = 0; i < inputRows; i++)
        {
            for (int j = 0; j < inputColumns; j++)
            {
                printf("Enter element [%d, %d]: ", i, j);
                scanf("%d", (*(inputMatrix + i) + j));
            }
            printf("\n");
        }

        printf("\nEntered %dx%d Matrix:\n", inputRows, inputColumns);
        for (int i = 0; i < inputRows; i++)
        {
            for (int j = 0; j < inputColumns; j++)
            {
                printf("%d   ", *(*(inputMatrix + i) + j));
            }
            printf("\n");
        }

        if (inputRows == 2 && inputColumns == 2)
        {
            findMax2x2(inputMatrix, inputRows, inputColumns);
        }
        else if (inputRows == 4 && inputColumns == 4)
        {
            findMax4x4(inputMatrix, inputRows, inputColumns);
        }
        else if (inputRows == 8 && inputColumns == 8)
        {
            findMax8x8(inputMatrix, inputRows, inputColumns);
        }

        char studentID[10];

        printf("\nEnter your Student ID (xxK-xxxx): ");
        scanf("%s", studentID);

        inputMatrix = (int **)realloc(inputMatrix, 2 * sizeof(int *));
        for (int i = 0; i < 2; i++)
        {
            inputMatrix[i] = (int *)realloc(inputMatrix[i], 2 * sizeof(int));
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                *(*(inputMatrix + i) + j) = studentID[4 + i * 2 + j] - '0';
            }
        }

        printf("\nEntered Student ID as a 2x2 Matrix:\n");
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                printf("%d   ", *(*(inputMatrix + i) + j));
            }
            printf("\n");
        }

        findMax2x2(inputMatrix, 2, 2);

        for (int i = 0; i < inputRows; i++)
        {
            free(*(inputMatrix + i));
        }
        free(inputMatrix);
    }

    else
    {
        printf("\nDimensions of the matrix can only be 2x2, 4x4, or 8x8! Please try again\n");
        return 1;
    }
}