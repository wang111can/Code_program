#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[], char *evn[]) {

    printf("call outer process to cover the process\n");
    for (int i = 0;evn[i];i ++ ) {
        printf("%s\n", evn[i]);
    }
    sleep(3);

    return 0;
}

