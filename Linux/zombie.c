#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[], char *evn[]) {

        

    pid_t id = fork();
    if (id == 0) {
        return 0;
    }
    else {
        while (1) {
        }
    }


    return 0;
}
