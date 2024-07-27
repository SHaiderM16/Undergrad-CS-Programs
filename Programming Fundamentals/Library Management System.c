#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    int accessionNumber;
    char author[100];
    char title[100];
    int isIssued;
};

struct Book *library;

int totalBooks = 0;

void checkIssued(int issue)
{
    if (issue == 1)
    {
        printf("Status: Issued\n\n");
    }
    else
    {
        printf("Status: Not Issued\n\n");
    }
}

void displayBookInfo()
{
    int searchAccessionNum;

    printf("Enter accession number: ");
    scanf("%d", &searchAccessionNum);

    printf("\nBook Information:\n");
    for (int i = 0; i < totalBooks; i++)
    {
        if (library[i].accessionNumber == searchAccessionNum)
        {
            printf("Author: %s\n", library[i].author);
            printf("Title: %s\n", library[i].title);
            checkIssued(library[i].isIssued);
            return;
        }
    }
    printf("Book with accession number %d not found\n", searchAccessionNum);
}

void addBook()
{
    // Reallocate memory by increasing memory by 1 sizeof(struct Book)
    library = realloc(library, (totalBooks + 1) * sizeof(struct Book));

    printf("Enter Accession Number: ");
    scanf("%d", &library[totalBooks].accessionNumber);

    fflush(stdin);

    printf("Enter Author: ");
    gets(library[totalBooks].author);

    printf("Enter Title: ");
    gets(library[totalBooks].title);

    library[totalBooks].isIssued = 0;
    totalBooks = totalBooks + 1;

    printf("\nBook Added!\n");
}

void displayAuthorBook()
{
    char searchAuthor[100];
    printf("Enter Author's Name: ");
    gets(searchAuthor);

    printf("\nBooks by Author %s:\n", searchAuthor);
    for (int i = 0; i < totalBooks; i++)
    {
        if (strcmp(library[i].author, searchAuthor) == 0)
        {
            printf("Accession Number: %d\n", library[i].accessionNumber);
            printf("Title: %s\n\n", library[i].title);
            checkIssued(library[i].isIssued);
        }
    }
}

void displayTitleQuantity()
{
    char searchTitle[100];
    printf("Enter Title: ");
    gets(searchTitle);

    int titleCount = 0;
    for (int i = 0; i < totalBooks; i++)
    {
        if (strcmp(library[i].title, searchTitle) == 0)
        {
            titleCount = titleCount + 1;
        }
    }

    printf("\nNumber of Books with Title '%s': %d\n", searchTitle, titleCount);
}

void displayTotalQuantity()
{
    printf("\nTotal Number of Books in the Library: %d\n", totalBooks);
}

void issueBook()
{
    int issueAccession;
    printf("Enter Accession Number: ");
    scanf("%d", &issueAccession);

    for (int i = 0; i < totalBooks; i++)
    {
        if (library[i].accessionNumber == issueAccession)
        {
            if (library[i].isIssued == 0)
            {
                library[i].isIssued = 1;
                printf("\nBook Issued Successfully! Kindly return it within the stated time period.\n");
            }
            else
            {
                printf("\nBook is already Issued!\n");
            }
            return;
        }
    }

    printf("\nBook with Accession Number %d not found!\n", issueAccession);
}

int main()
{
    while (1)
    {
        printf("0 - Quit Menu\n");
        printf("1 - Display book information\n");
        printf("2 - Add a new book\n");
        printf("3 - Display all the books in the library of a particular author\n");
        printf("4 - Display the number of books of a particular title\n");
        printf("5 - Display the total number of books in the library\n");
        printf("6 - Issue a book\n");

        int menuOption;
        printf("\nSelect an option(0-6): ");
        scanf("%d", &menuOption);

        switch (menuOption)
        {
        case 0:
            printf("\nThank You for visiting! Have a nice day");
            free(library);
            exit(0);
        case 1:
            displayBookInfo();
            break;
        case 2:
            addBook();
            break;
        case 3:
            displayAuthorBook();
            break;
        case 4:
            displayTitleQuantity();
            break;
        case 5:
            displayTotalQuantity();
            break;
        case 6:
            issueBook();
            break;
        default:
            printf("Invalid option entered! Please try again");
            break;
        }
        printf("\n\n");
    }
}