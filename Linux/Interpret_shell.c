#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[], char *evn[]) {

    char cmd[1000];    
    char *_argv[1000];
    int index = 0;
    
    while (1) {

        printf("shell$ ");
        fflush(stdout);
        
        memset(cmd, '\0', sizeof cmd);
        index = 0;
        
        // 读入指令
        if (fgets(cmd, sizeof cmd, stdin) == NULL) continue;
        
        cmd[strlen(cmd) - 1] = '\0';


        //strtok(string, seg) 对一个字符串进行操作 返回 seg的位置
        // 第二次调用 string 传入 NULL
        
        // 把读入的 指令 分段
        _argv[index ++ ] = strtok(cmd, " ");

        while (_argv[index ++ ] = strtok(NULL, " "));
        // The  strtok()  function breaks a string into a sequence of zero or more nonempty tokens
      
        // 内置命令
        // 不想让 子进程执行，要让父进程 或shell 执行的 命令
        // 例如 cd 命令， 子进程执行只改变子进程的 工作目录 不改变父进程的 工作目录 
        if (strcmp(_argv[0], "cd") == 0)
        {
            if (_argv[1] != NULL) {
                chdir(_argv[1]); // 使用shell 内置 命令 控制 而非 系统命令
            }
            continue;
        }

        // 系统命令
        pid_t id = fork();
        if (id == 0) {
            // 子进程 执行 对于的 指令函数
            execvp(_argv[0], &_argv[1]);
            exit(1);
        }
        int status = 0;
        pid_t waitid = waitpid(id, &status, 0);
        int exit_code = (status >> 8) & 0xff, Os_code = (status & 0x7f);
        // printf("%d %d\n", exit_code, Os_code);
        if (Os_code != 0) {
            printf("%s\n", strerror(Os_code));
        }

    }


    return 0;
}