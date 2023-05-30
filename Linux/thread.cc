

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
#include <thread>


using namespace std;

void* thread_func(void * x) {

    // for (int i = 0;i < 3;i ++ ) {
    // }
    pthread_cancel((pthread_t)x);

    return (void*)10;
}

int main() {   

    pthread_t thread_id;
    pthread_t id = pthread_self();
    pthread_create(&thread_id, nullptr, thread_func, (void*)id);
    for (int i = 0;i < 5;i ++ ) {
        sleep(1);
    }
    pthread_cancel(thread_id);
    void *ret = nullptr;
    pthread_join(thread_id, &ret);
    // res = (void*)10 
    // (long long) res = 10 
    printf("wait finish %d\n", (long long)ret);


    // pthread_t thread[5];
    // char arg[1024];
    // for (int i = 0;i < 5;i ++ ) {
    //     snprintf(arg, 1024, "%s%d", "thread  was create: id ", i);
    //     pthread_create(&thread[i], nullptr, thread_func, (void*)arg); 
    //     sleep(1);
    // }
    // while (1) {
    //     cout << "main pid: " <<  getpid() << endl;
    //     sleep(5);
    // }


    return 0;
}
