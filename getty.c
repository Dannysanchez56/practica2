#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

int validarUsuario(char *user_pswd){
    FILE *pswfile;
    char file_line[40];
    
    pswfile = fopen("passwd.txt","r");  //abrir el documento
    
    while(fgets(file_line,sizeof(file_line),pswfile) != NULL){
        if(strcmp(user_pswd,file_line) == 0){
            return 1;  
        }
    }

    return 0;
}

int main(){
    
    char user[20];
    char password[20];
    int p;
    
    while(1){
        printf("user: \n");
        fgets(user,  80, stdin);
        printf("password: \n");
        fgets(password,  80, stdin);
    
        strcat(user, ":");      //unir el user y el password en una sola variable
        strcat(user, "password);
    
        if(validarUsuario(user)){
            printf("authorized access  \n");
            //crear proceso hijo que sera reemplazado por una sesion shell
            p = fork();
            if(p == 0){
                execlp("./sh.out", "./sh.out", NULL);
            }else{
                wait(NULL);
            }
        }else{
            printf("Validacion incorrecta");
        }
    }
}
