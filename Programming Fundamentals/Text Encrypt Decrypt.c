#include <stdio.h>
#include <string.h>

void encryptAndWrite(char string[100], char encrypted[100])
{
    FILE *writeFile = fopen("encrypted_info.txt", "w");

    int positionVal = 1, ascii, encryptedASCII;

    if (writeFile != NULL)
    {
        for (int i = 0; i < strlen(string); i++)
        {
            ascii = (int)string[i];
            encryptedASCII = ascii + positionVal;
            encrypted[i] = (char)encryptedASCII;

            fputc(encrypted[i], writeFile);

            positionVal = positionVal + 1;
        }

        printf("\nEncrypted text inserted in file\n");
        printf("%s\n", encrypted);

        fclose(writeFile);
    }
    else
    {
        printf("\nFile could not be created! Please try again\n");
    }
}

void readAndDecrypt()
{
    FILE *readFile = fopen("encrypted_info.txt", "r");

    if (readFile != NULL)
    {
        printf("\nDecrypted text Read then decoded from file\n");

        int positionVal = 1, character;

        while ((character = fgetc(readFile)) != EOF)
        {
            putchar(character - positionVal);
            positionVal = positionVal + 1;
        }
        printf("\n");

        fclose(readFile);
    }
    else
    {
        printf("\nFile could not be read! Please try again\n");
    }
}

int main()
{
    char inputString[100];
    char encryptedString[100];

    printf("Enter String = ");
    gets(inputString);

    printf("\nNormal Text\n");
    printf("%s\n", inputString);

    encryptAndWrite(inputString, encryptedString);

    readAndDecrypt();
}