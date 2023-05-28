

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
#include <pthread.h>

using namespace std;

void* thread_func(void * x) {
    while (1) {
        cout << (char*) x << ' ' << "thread pid: " << getpid() << endl;
        sleep(1);
    }
}

int main() {   

    pthread_t thread[5];
    char arg[1024];
    for (int i = 0;i < 5;i ++ ) {
        snprintf(arg, 1024, "%s%d", "thread was create: id ", i);
        pthread_create(&thread[i], nullptr, thread_func, (void*)arg); 
        sleep(1);
    }
    while (1) {
        cout << "main pid: " <<  getpid() << endl;
        sleep(5);
    }
}
