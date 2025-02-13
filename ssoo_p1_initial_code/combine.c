#include <stdio.h>    // i/o lib
#include <unistd.h>   // linux lib
#include <stdlib.h>   // dynamic mem lib
#include <sys/types.h>// ??
#include <sys/stat.h> // ??
#include <fcntl.h>    // ??
#include <string.h>   // string lib

#define EXPECTED_ARGC 4
#define MAX_STUDENTS 100

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

void read_file(const char *arg_file, struct alumno *students, int *num_students) {
    int file = open(arg_file, O_RDONLY);
    if (file == -1) {
        printf("Error reading the file %s", arg_file);
        exit(1);
    }
    
    while (*num_students < MAX_STUDENTS) {
		ssize_t student_data = read(file, &students[*num_students], sizeof(struct alumno));
		if (student_data == -1) {
			perror("Error reading file");
			exit(1);
		}
		if (student_data == 0) {
            break; // End of file reached
		}
        (*num_students)++;
    }
    
    if (close(file)<0){
		perror("close error");
		exit(1);
	}
}

int main(int argc, char *argv[]){
	if (argc != EXPECTED_ARGC) {
		// Check if the number of arguments is incorrect
        perror("Error: Invalid number of arguments.\n");
		printf("Program running with %d arguments, the program must tun with %d arguments.\n", argc - 1, EXPECTED_ARGC - 1);
        return -1;
    }
    
    struct alumno students[MAX_STUDENTS];
	int num_students = 0;

	read_file(argv[1],&students,num_students);
	read_file(argv[2],&students,num_students);
	if (num_students < MAX_STUDENTS){
		perror("Maximun number of students reached");
		return -1;
	}
	

    
	//if(numb_students > 100) return;
	return 0;
}
