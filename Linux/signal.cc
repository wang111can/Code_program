#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <cstring>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <stdlib.h>


using namespace std;

int cnt = 0;


void calcu(int x) {
    cout << cnt << endl;
}

int main() {

    alarm(1);
    signal(SIGALRM, calcu);
    
    for(;;) {
        cnt ++ ;
    }
    // pid_t id = fork();
    // int pipeid[2] = {0};
    // pipe(pipeid);
    
    
    // if (id == 0) {
    //     close(pipeid[0]);
    //     string str = "Writing!!!!!!!!!!";
    //     while (1) {
    //         write(pipeid[1], str.c_str(), (int)str.size());
    //     }
    //     close(1);
    //     exit(0);
    // }
    // else {

    //     close(pipeid[1]);
    //     char buffer[1024];
    //     for (int i = 1;i <= 5;i ++ ) {
    //         sleep(1);
    //         read(pipeid[0], buffer, 1024 - 1);
    //     }
    //     close(pipeid[0]);
    //     int status = 0;
    //     int wait_id = waitpid(id, &status, 0);

    //     printf("子进程的退出码为[%d]\n", status & 0x7f);

    // }


}


