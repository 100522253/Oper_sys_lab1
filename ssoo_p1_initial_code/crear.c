#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define EXPECTED_ARGC 3 //crear , fichero and modo are the arguments


int main(int argc, char *argv[]) {
    if (argc != EXPECTED_ARGC) {
		// Check if the number of arguments is incorrect
        printf("Error: Invalid number of arguments.\n");
		printf("Program running with %d arguments, the program must tun with %d arguments.\n", argc - 1, EXPECTED_ARGC - 1);
        return -1;
    }
    return 0;
}


