#include "Xavier_libFS.h"
#include <string.h>

int main() {
    char filename[] = "Xavier_Introduction.txt";
    FILE *fp = NULL;
    int choice;
    char intro[] =
        "Hello, this is Lab4.\n"
        "This project demonstrates a user-level file system library implementation.\n\n"
        "It shows how to create, write, read, and delete files.\n"
        "The focus is on modular design and error handling.\n";

    while (1) {
        printf("\n--- LibFS Menu ---\n");
        printf("1. Create File\n");
        printf("2. Open File\n");
        printf("3. Write Introduction\n");
        printf("4. Read File\n");
        printf("5. Close File\n");
        printf("6. Delete File\n");
        printf("7. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }
        while (getchar() != '\n'); // clear leftover newline

        switch (choice) {
            case 1: // Create
                if (fileCreate(filename) == 0)
                    printf("File created successfully.\n");
                else
                    printf("Error creating file.\n");
                break;

            case 2: // Open
                fp = fileOpen(filename, "r+");
                if (fp) printf("File opened successfully.\n");
                else printf("Error opening file.\n");
                break;

            case 3: // Write
                fp = fileOpen(filename, "w");
                if (fp) {
                    if (fileWrite(fp, intro) == 0)
                        printf("Introduction written.\n");
                    else
                        printf("Error writing to file.\n");
                    fileClose(fp);
                    fp = NULL; // reset pointer
                } else {
                    printf("Error opening file for writing.\n");
                }
                break;

            case 4: // Read
                fp = fileOpen(filename, "r");
                if (fp) {
                    printf("\n--- File Contents ---\n");
                    fileRead(fp);
                    fileClose(fp);
                    fp = NULL; // reset pointer
                } else {
                    printf("Error opening file for reading.\n");
                }
                break;

            case 5: // Close
                if (fp) {
                    fileClose(fp);
                    fp = NULL;
                    printf("File closed.\n");
                } else {
                    printf("No file open.\n");
                }
                break;

            case 6: // Delete
                if (fileDelete(filename) == 0)
                    printf("File deleted successfully.\n");
                else
                    printf("Error deleting file.\n");
                fp = NULL; // ensure pointer reset
                break;

            case 7: // Exit
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

}
