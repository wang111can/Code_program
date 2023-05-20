#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {


    int pipeid[2] = {0}; // 创建管道
    int res_p = pipe(pipeid); // pipeid[0] 表示读出端 pipeid[1] 表示写入端
    // 1 -----> 0
    if (res_p == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t id = fork();
    if (id == -1) {
        perror("fork");
        exit(1);
    }    

    if (id == 0) {
        // 子进程 读取
        // 进程 关闭 自己不需要的 端
        close(pipeid[1]);
        while (1) {
            char buffer[1024];
            // 读取 管道内的 信息
            // 从进程 自己 对应的 端进行操作
            int size = read(pipeid[1], buffer, 1024 - 1);
            if (size > 0) {
                buffer[size] = 0;
                printf("%d %s\n", size, buffer);
                std::cout << "father's message: " << buffer << '\n';
            }

            sleep(1);
        }   
        close(pipeid[0]);
    }
    else {
        // 父进程
        // 进程 关闭 自己不需要的 端
        close(pipeid[0]);
        std::string str = "hello child process!";

        int cnt = 0;
        while (1) {
            char buffer[1024];
            snprintf(buffer, sizeof(buffer), "%s[%d] NO.%d", str.c_str(), getpid(), ++ cnt);         
            // 从进程 自己 对应的 端进行操作
            // printf("father %s\n", buffer);
            write(pipeid[1], buffer, strlen(buffer));
            sleep(1);
        }
        
        close(pipeid[1]);
        int wait = waitpid(id, nullptr, 0);
    }

    return 0;
}