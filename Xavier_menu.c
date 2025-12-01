#include "Xavier_libFS.h"
#include <string.h>
#include <stdio.h>

int main() {
    // File name used throughout the program
    char filename[] = "Xavier_Introduction.txt";

    // Persistent file pointer for open/close lifecycle
    FILE *fp = NULL;

    // Menu choice variable
    int choice;

    // Introduction text to write into the file
    char intro[] =
        "Hello, this is Lab4.\n"
        "This project demonstrates a user-level file system library implementation.\n\n"
        "It shows how to create, write, read, and delete files.\n"
        "The focus is on modular design and error handling.\n";

    while (1) {
        // Display menu
        printf("\n--- LibFS Menu ---\n");
        printf("1. Create File\n");
        printf("2. Open File\n");
        printf("3. Write Introduction\n");
        printf("4. Read File\n");
        printf("5. Close File\n");
        printf("6. Delete File\n");
        printf("7. Exit\n");
        printf("Enter choice: ");

        // Input validation
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }
        while (getchar() != '\n'); // clear leftover newline

        switch (choice) {
            // Create file
            case 1:
                if (fileCreate(filename) == 0)
                    printf("File created successfully.\n");
                else
                    printf("Error creating file.\n");
                break;

            // Open file
            case 2:
                fp = fileOpen(filename, "r+");
                if (fp) printf("File opened successfully.\n");
                else printf("Error opening file.\n");
                break;

            // Write introduction text
            case 3:
                if (fp) {
                    if (fileWrite(fp, intro) == 0)
                        printf("Introduction written.\n");
                    else
                        printf("Error writing to file.\n");
                } else {
                    printf("No file open. Please open first.\n");
                }
                break;

            // Read file contents
            case 4:
                if (fp) {
                    printf("\n--- File Contents ---\n");
                    fileRead(fp);
                } else {
                    printf("No file open. Please open first.\n");
                }
                break;

            // Close file
            case 5:
                if (fp) {
                    fileClose(fp);
                    fp = NULL;
                    printf("File closed.\n");
                } else {
                    printf("No file open.\n");
                }
                break;

            // Delete file
            case 6:
                if (fileDelete(filename) == 0)
                    printf("File deleted successfully.\n");
                else
                    printf("Error deleting file.\n");
                fp = NULL; // ensure pointer reset
                break;

            // Exit program
            case 7:
                if (fp) { // clean up if still open
                    fileClose(fp);
                    fp = NULL;
                }
                printf("Exiting...\n");
                return 0;

            // Handle invalid choice
            default:
                printf("Invalid choice.\n");
        }
    }
}

