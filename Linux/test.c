#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[], char *evn[]) {

    execl("./process", "gcc process.c", "-o", "process", NULL);

    printf("fail\n");
    return 0;
}