#ifndef _FIFO_H_
#define _FIFO_H_

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

#define PAGE_SIZE 4096
#define PROJ_ID 486452
#define PIPE "/home/wc/Code_program/Linux/pipe"

using namespace std;



string _path = "/home/wc/Code_program/Linux/";

class Pipe {

public :
    Pipe() {
        mkfifo(PIPE, 0666);
    }
    ~Pipe() {
        unlink(PIPE);
    }

};






#endif

