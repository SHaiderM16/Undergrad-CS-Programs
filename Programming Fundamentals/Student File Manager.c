#include <stdio.h>
#include <stdlib.h>

int main()
{
    char userDecision;

    printf("Enter whether you wish to create a new file or modify an existing one(C or M): ");
    scanf(" %c", &userDecision);

    if (userDecision == 'C' || userDecision == 'c')
    {
        int n;
        printf("\nEnter the total number of students: ");
        scanf("%d", &n);

        char **names = (char **)calloc(n, sizeof(char *));
        int *marks = (int *)calloc(n, sizeof(int));

        for (int i = 0; i < n; i++)
        {
            names[i] = (char *)calloc(100, sizeof(char));

            printf("\nEnter data of student %d", i + 1);
            printf("\nName: ");
            getchar();
            gets(names[i]);

            printf("Marks: ");
            scanf("%d", &marks[i]);

            printf("\n");
        }

        FILE *writeFile = fopen("exercise_2.txt", "w");

        if (writeFile != NULL)
        {
            for (int i = 0; i < n; i++)
            {
                fprintf(writeFile, "%s attained %d\n", names[i], marks[i]);
            }

            printf("Data has successfully been stored in a file\n");

            fclose(writeFile);
        }
        else
        {
            printf("File could not be created! Please try again\n");
        }

        for (int i = 0; i < n; i++)
        {
            free(names[i]);
        }
        free(names);
        free(marks);
    }

    else if (userDecision == 'M' || userDecision == 'm')
    {
        int n;
        printf("\nEnter the additional number of students: ");
        scanf("%d", &n);

        char **names = (char **)calloc(n, sizeof(char *));
        int *marks = (int *)calloc(n, sizeof(int));

        for (int i = 0; i < n; i++)
        {
            names[i] = (char *)calloc(100, sizeof(char));

            printf("\nEnter data of student %d", i + 1);
            printf("\nName: ");
            getchar();
            gets(names[i]);

            printf("Marks: ");
            scanf("%d", &marks[i]);

            printf("\n");
        }

        FILE *appendFile = fopen("exercise_2.txt", "a");

        if (appendFile != NULL)
        {
            for (int i = 0; i < n; i++)
            {
                fprintf(appendFile, "%s attained %d\n", names[i], marks[i]);
            }

            printf("Data has successfully been added in the existing file\n");

            fclose(appendFile);
        }
        else
        {
            printf("File could not be created! Please try again\n");
        }

        for (int i = 0; i < n; i++)
        {
            free(names[i]);
        }
        free(names);
        free(marks);
    }
    else
    {
        printf("\nSelect a valid option (C for Create or M for Modify)!\n");
    }
}