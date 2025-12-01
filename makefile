#compiler and flags
CC = gcc
CFLAGS = -Wall -g

#Default target
all: Xavier_testapp
	@echo "--------------------------------------------------"
	@echo "Build complete!"
	@echo "To run the program, type: ./Xavier_testapp"
	@echo "--------------------------------------------------"

#Link objects into executable
Xavier_testapp: Xavier_libFS.o Xavier_testFS.o
	$(CC) $(CFLAGS) -o Xavier_testapp Xavier_libFS.o Xavier_testFS.o

#Compile library source
Xavier_libFS.o: Xavier_libFS.c Xavier_libFS.h
	$(CC) $(CFLAGS) -c Xavier_libFS.c

#Compile test application source
Xavier_testFS.o: Xavier_testFS.c Xavier_libFS.h
	$(CC) $(CFLAGS) -c Xavier_testFS.c

#Clean up build artifacts
clean:
	rm -f *.o Xavier_testapp

