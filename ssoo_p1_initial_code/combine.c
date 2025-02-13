#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define EXPECTED_ARGC 4

struct alumno{
	char nombre[50];
	int nota;
	int convocatoria;
};

char scoring_marks(int mark){
	/*Given a mark(integer) the functions convert it into a char*/
	//Reminder in C the 'char' type uses: ' not "
	switch (mark)
	{
	case 10:
		return 'M';
	case 9:
		return 'S';
	case 8: case 7:
		return 'N';
	case 6: case 5:
		return 'A';
	case 4: case 3: case 2: case 1: case 0:
		return 'F';
	default:
		printf("Error: Invalid mark.\n");
		printf("The mark: %d is not in the range of [0,10]", mark);
		return -1; //I'm not sure of this
	}
}

int main(int argc, char *argv[]){
	if (argc != EXPECTED_ARGC) {
		// Check if the number of arguments is incorrect
        printf("Error: Invalid number of arguments.\n");
		printf("Program running with %d arguments, the program must tun with %d arguments.\n", argc - 1, EXPECTED_ARGC - 1);
        return -1;
    }
    
    // Rest of the program logic
    
	//if(numb_students > 100) return;
	return 0;
}
