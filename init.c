#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void crear_proceso(){
    int p = fork();

    if (p==0){
        execlp("xterm","xterm","-e", "./getty.out", NULL);
    }
}

int main(){
    int i;
    for (i = 0 ; i < 6 ; i++){
        crear_proceso();
    }
    //if(si uno de los procesos se cierra, correr otro){
        crear_proceso();
}