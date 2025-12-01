//Xavier Santiago
//CS470
//12/1/2025
//Honor Code: "I pledge that this submission is solely my work, and that I have neither given to nor received help from anyone other than the instructor or TA’s."
#ifndef XAVIER_LIBFS_H
#define XAVIER_LIBFS_H

#include <stdio.h>

// File system API
int fileCreate(const char *filename);
FILE* fileOpen(const char *filename, const char *mode);
int fileWrite(FILE *fp, const char *data);
int fileRead(FILE *fp);
int fileClose(FILE *fp);
int fileDelete(const char *filename);


#endif
