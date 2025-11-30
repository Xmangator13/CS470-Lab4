#compiler and flags
CC = gcc
CFLAGS = -Wall -g

#Target executable
TARGET = Lab4

#Object files
OBJS = Lab4_libFS.o Lab4_menu.o

#Default rule
all: $(TARGET)

#Link object files into final executable
$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
#compile library into object file
Lab4_libFS.o: Lab4_libFS.c Lab4_libFS.h
	$(CC) $(CFLAGS) -c Lab4_libFS.c
#compile menu driver into object file
Lab4_menu.o: Lab4_menu.c Lab4_libFS.h
	$(CC) $(CFLAGS) -c Lab4_menu.c

