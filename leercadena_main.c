#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "leercadena.h"


int main(int argc, char *argv[]) {
    char **vector; 

    if (argc == 1){
        printf("Indique el programa que desea se ejecute \n"); 
        exit(1);
        
    } else {       
        convierte_string(argv); 
        pid_t pid;  
        if (strcmp ('exit', argv[1]) ==  0) {
            exit(1); 
        }
        pid = fork(); 
        if (pid < 0) {
            perror("No se pudo crear un proceso \n"); 
            exit(1); 
        } else if (pid == 0) {
            convierte_char(argv); 
            vector = de_cadena_a_vector(comando); 
            execvp(vector[0], vector); 
            perror("Return from execlp() not expected"); 
            exit(EXIT_FAILURE); 
        } else {
            wait(NULL); 
        }
         
    }
    return 0; 
}


char* convierte_char(char *argv[]) {
    int i; 
    char var[25]; 
    for (i = 1; i < sizeof(argv); i++) {
        var[i] = argv[i]; 
    }
}


