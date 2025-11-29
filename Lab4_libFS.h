#ifndef LAB4_LIBFS_H
#define LAB4_LIBFS_H

#include <stdio.h>

// File system API
int fileCreate(const char *filename);
FILE* fileOpen(const char *filename, const char *mode);
int fileWrite(FILE *fp, const char *data);
int fileRead(FILE *fp);
int fileClose(FILE *fp);
int fileDelete(const char *filename);

#endif