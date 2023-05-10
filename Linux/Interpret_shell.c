#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[], char *evn[]) {

    char cmd[1000];    
    char *_argv[1000];
    int index = 0;
    while (1) {
        printf("shell$ ");
        fflush(stdout);
        memset(cmd, '\0', sizeof cmd);
        index = 0;
        if (fgets(cmd, sizeof cmd, stdin) == NULL) continue;
        cmd[strlen(cmd) - 1] = '\0';


        //strtok(string, seg) 对一个字符串进行操作 返回 seg的位置
        // 第二次调用 string 传入 NULL
        _argv[index] = strtok(cmd, " ");
        while (_argv[++ index] = strtok(NULL, " "));
        // The  strtok()  function breaks a string into a sequence of zero or more nonempty tokens


    }


    return 0;
}