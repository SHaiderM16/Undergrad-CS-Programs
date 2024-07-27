#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* sentence = (char*) calloc(1000, sizeof(char));

    printf("Enter a sentence: ");
    gets(sentence);

    int totalWords = 1;
    for (int i = 0; i < strlen(sentence); i++)
    {
        // ' ' means another word present in sentence
        if (sentence[i] == ' ') {
            totalWords = totalWords + 1;
        }
    }

    // [totalWords] of [1000] characters each    
    char** words = (char**) calloc(totalWords, sizeof(char*));
    for (int i = 0; i < totalWords; i++)
    {
        *(words + i) = (char*) calloc(1000, sizeof(char));
    }

    int wordCount = 0;
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            wordCount = wordCount + 1;
        } 
        else {
            strncat(*(words + wordCount), &sentence[i], 1);
        }
    }

    printf("\n2D Array Output:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s\n", *(words + i));
    }

    for (int i = 0; i < totalWords; i++) {
        free(*(words + i));
    }
    free(words);
    free(sentence);
}