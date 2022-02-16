#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

int validarUsuario(){


    return 1;
}

int main(){

    char password[20];
    char user[20];

    printf("user: \n");
    fgets(user,  80, stdin);
    printf("password: \n");
    fgets(password,  80, stdin);
    if(validarUsuario()){
        printf("authorized access  \n");
        //crear proceso hijo que sera reemplazado por una sesion shell
        int p = fork();
        if(p == 0){
            execlp("./sh.out", "./sh.out", NULL);
        }
        else{
            wait(NULL);
            }
    }
}