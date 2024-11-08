#include <stdio.h>
#include <stdlib.h>

#define FILENAME "output.txt"

// Function to write a paragraph to "output.txt"
void writeParagraph() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char paragraph[201];  // 200 characters plus null terminator
    printf("Enter a paragraph (up to 200 characters): ");
    fgets(paragraph, sizeof(paragraph), stdin);

    fprintf(file, "%s", paragraph);
    fclose(file);
    printf("Paragraph written to %s successfully.\n", FILENAME);
}

// Function to read the content of "output.txt" and display it
void readParagraph() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char ch;
    printf("Content of %s:\n", FILENAME);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
    printf("\n");
}

// Function to append a paragraph to "output.txt"
void appendParagraph() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char paragraph[201];
    printf("Enter an additional paragraph (up to 200 characters): ");
    fgets(paragraph, sizeof(paragraph), stdin);

    fprintf(file, "%s", paragraph);
    fclose(file);
    printf("Paragraph appended to %s successfully.\n", FILENAME);
}

int main() {
    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Write paragraph\n");
        printf("2. Read paragraph\n");
        printf("3. Append paragraph\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                writeParagraph();
                break;
            case 2:
                readParagraph();
                break;
            case 3:
                appendParagraph();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}