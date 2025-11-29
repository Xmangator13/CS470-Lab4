#include "Lab4_libFS.h"
#include <string.h>

int main() {
    char filename[] = "Lab4_Introduction.txt";
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
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (fileCreate(filename) == 0)
                    printf("File created successfully.\n");
                else
                    printf("Error creating file.\n");
                break;

            case 2:
                fp = fileOpen(filename, "r+");
                if (fp) printf("File opened successfully.\n");
                else printf("Error opening file.\n");
                break;

            case 3:
                fp = fileOpen(filename, "w");
                if (fp) {
                    fileWrite(fp, intro);
                    fileClose(fp);
                    printf("Introduction written.\n");
                } else printf("Error writing file.\n");
                break;

            case 4:
                fp = fileOpen(filename, "r");
                if (fp) {
                    printf("\n--- File Contents ---\n");
                    fileRead(fp);
                    fileClose(fp);
                } else printf("Error reading file.\n");
                break;

            case 5:
                if (fp) {
                    fileClose(fp);
                    fp = NULL;
                    printf("File closed.\n");
                } else printf("No file open.\n");
                break;

            case 6:
                if (fileDelete(filename) == 0)
                    printf("File deleted successfully.\n");
                else
                    printf("Error deleting file.\n");
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
