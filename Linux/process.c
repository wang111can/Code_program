#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[], char *evn[]) {

    printf("call outer process to cover the process\n");
    

    return 0;
}