#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main() {

    pid_t id = fork();

    if (id == 0) {
        printf("child: %d %d\n", getpid(), id);
        while (1) {
            sleep(3);
            break;
        }
        return 0;
    }
    else {
        while (1) {
            printf("father: %d %d\n", getpid(), id);
        }
    }
     
    return 0;
}