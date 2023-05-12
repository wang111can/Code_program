#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


int main() {
    FILE* fp = fopen("text.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        
    }
}
