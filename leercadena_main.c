#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int i; 
    char* vec[argc]; 
    if (argc == 1){ // Se verifica que el usuario no haya ingresado nada, de ser el caso, le pedira el programa que desea se ejecute. 
        printf("Indique el programa que desea se ejecute \n"); 
        exit(1);
        
    } else { 
        pid_t pid;  
        pid = fork(); 
        if (pid < 0) {
            perror("No se pudo crear un proceso \n"); 
            exit(1); 
        } else if (pid == 0) {
          argv[argc] = NULL; 
          for (i = 0; i < argc; i++) {
            vec[i] = argv[i+1]; 
          }          
          execvp(vec[0], vec); 
          perror("Return from execlp() not expected"); 
          exit(EXIT_FAILURE); 
        } else {
            wait(NULL); 
        }
    }
    return 0; 
}
