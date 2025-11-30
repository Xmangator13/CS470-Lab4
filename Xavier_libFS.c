#include "Xavier_libFS.h"
#include <stdlib.h>

// Create a new file
int fileCreate(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return -1;
    fclose(fp);
    return 0;
}

// Open an existing file
FILE* fileOpen(const char *filename, const char *mode) {
    return fopen(filename, mode);
}

// Write data to file
int fileWrite(FILE *fp, const char *data) {
    if (!fp) return -1;
    fprintf(fp, "%s", data);
    return 0;
}

// Read and print file contents
int fileRead(FILE *fp) {
    if (!fp) return -1;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    return 0;
}

// Close file
int fileClose(FILE *fp) {
    if (!fp) return -1;
    fclose(fp);
    return 0;
}

// Delete file
int fileDelete(const char *filename) {
    return remove(filename);
}