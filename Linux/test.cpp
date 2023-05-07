#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
    
    printf("%d\n", argc);

    for (int i = 0;i < argc;i ++ ) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    return 0;
}