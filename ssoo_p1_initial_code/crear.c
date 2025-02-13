#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define EXPECTED_ARGC 3 //crear , fichero and modo are the arguments

mode_t get_mode(char *arg_mode){
    /*Gets the octal mode from the string*/
    //me quiero morir
    // Cheack if length =3 or =4 with a 0 at the begining
    if (strlen(arg_mode) != 3 || (strlen(arg_mode) != 4 && arg_mode[0] == '0')) return -1;

    for (size_t i = 0; i < strlen(arg_mode); i++) // Check if the octal code has correct characters
    {
        if (!(arg_mode[i] >= '0' && arg_mode[i] <= '7')) return -1;
    }
    mode_t mode = strtol(arg_mode, NULL, 8); //change from string to base 8
    return mode;
}


int main(int argc, char *argv[]) {
    if (argc != EXPECTED_ARGC) {
		// Check if the number of arguments is incorrect
        printf("Error: Invalid number of arguments.\n");
		printf("Program executing with %d arguments, the program must tun with %d arguments.\n", argc - 1, EXPECTED_ARGC - 1);
        return -1;
    }
    char *filename = argv[1];
    mode_t mode = get_mode(argv[2]); // Convertir de string a octal
    if (mode != -1) return -1;
    
    // Guardar la máscara actual y establecerla a 0
    mode_t old_umask = umask(0);
    
    // Intentar crear el archivo con el modo especificado
    int fd = open(filename, O_CREAT | O_EXCL, mode);
    if (fd == -1) {
        fprintf(stderr, "Error creating file %s: %s\n", filename, strerror(errno));
        umask(old_umask); // Restaurar la máscara previa
        return -1;
    }
    close(fd);
    
    // Restaurar la máscara previa
    umask(old_umask);
    
    return 0;
}


