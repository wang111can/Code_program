

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

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 

int ticket = 10000;

void* thread_func(void * args) {

    // for (int i = 0;i < 3;i ++ ) {
    // }
    while (1) {
        pthread_mutex_lock(&mutex);
        if (ticket > 0) {
            // usleep(1000);
            cout << "pthread_id: " << pthread_self() << " ticket: "<< ticket << endl;
            // fflush(stdout);
            ticket -- ;
            
            pthread_mutex_unlock(&mutex);
        }
        else {
            pthread_mutex_unlock(&mutex);
            break;        
        }

    }

    return nullptr;
}

int main() {   

    pthread_t thread_id[10];
    pthread_t id = pthread_self();

    for (int i = 0;i < 10;i ++ )
        pthread_create(&thread_id[i], nullptr, thread_func, nullptr);

    while (1) {}
    void *ret = nullptr;
    // pthread_join(thread_id, &ret);
    // res = (void*)10 
    // (long long) res = 10 


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
