#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *text = (char *)calloc(1000, sizeof(char));

    printf("Enter the sentence to be written into a file: ");
    gets(text);

    FILE *writefile = fopen("exercise_5.txt", "w");

    if (writefile != NULL)
    {
        fprintf(writefile, "%s", text);

        fclose(writefile);
    }
    else
    {
        printf("File could not be created! Please try again\n");
        return 1;
    }

    FILE *readfile = fopen("exercise_5.txt", "r");

    if (readfile != NULL)
    {
        char searchLetter;

        printf("\nEnter letter to be counted: ");
        scanf(" %c", &searchLetter);

        int letterCount = 0;
        char characterIndex;

        while ((characterIndex = fgetc(readfile)) != EOF)
        {
            if (characterIndex == searchLetter)
            {
                letterCount = letterCount + 1;
            }
        }

        printf("\n'%c' appears %d times in the file\n", searchLetter, letterCount);

        fclose(readfile);

        free(text);
    }
    else
    {
        printf("\nFile could not be read! Please try again\n");
        free(text);
        return 1;
    }
}