#compiler and flags
CC = gcc
CFLAGS = -Wall -g

#Target executable
TARGET = Lab4

#Object files
OBJS = Xavier_libFS.o Xavier_menu.o

#Default rule
all: $(TARGET)

#Link object files into final executable
$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
#compile library into object file
Lab4_libFS.o: Xavier_libFS.c Xavier_libFS.h
	$(CC) $(CFLAGS) -c Xavier_libFS.c
#compile menu driver into object file
Lab4_menu.o: Xavier_menu.c Xavier_libFS.h
	$(CC) $(CFLAGS) -c Xavier_menu.c

