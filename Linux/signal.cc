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

void handler(int signum) {
    cout << "catching signum: " << signum << endl; 
    sleep(10);
}


class t {

private:
    int _x;
public:
    t(int x = 0):_x(x) {

    }
    int get_x() {
        return _x;
    }

};

int main()
{   

    void *test;
    test = (t*)malloc(sizeof(t));
    cout << (*((t*)test)).get_x() << endl;

    // struct sigaction act, oldact;
    // act.sa_flags = 0;
    // sigemptyset(&act.sa_mask);
    // sigaddset(&act.sa_mask, 3);
    // act.sa_handler = handler;
    
    // sigaction(2, &act, nullptr);
    
    // while (1) {}
    // 创建 信号集
    // sigset_t set, oldset;

    // // 初始化信号集
    // sigemptyset(&set);
    // sigemptyset(&oldset);
    // sigaddset(&set, 2); 

    // sigprocmask(SIG_BLOCK, &set, &oldset); // 阻塞 2 号信号

    // sigset_t pending;
    // while(1) {
    //     sigpending(&pending);
        
    //     cout << sigismember(&pending, 2) << endl;
    //     sleep(1);
    // }

    // for (int i = 1;i <= 31;i ++ ) {
    //     signal(i, catching);
    // }

    // while (1)  {

    // }


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
