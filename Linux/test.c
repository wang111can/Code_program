#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int un_g_val;
int g_val = 100;

int main(int argc, char *argv[], char *evn[]) {


    pid_t id = fork();

    if (id == 0) {
        
        while (1) {}
        exit(11);
    }
    else {
        int status = 0;
        pid_t wait_id = waitpid(id, &status, 0); // 
        // waitpid 返回的 status 是 按照 二进制的 方式返回的 0 ~ 32 其中 15 ~ 8 为退出码状态
        if (wait_id == id) {
            printf("the child process has been done! exit status: %d\n", (status >> 8) & 0xff); // 0xff == 00....00000011111111
            printf("notify: %d\n", status & 0x7f);
        }
    }

    return 0;
}