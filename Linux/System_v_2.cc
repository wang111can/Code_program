#include "System_v.hpp"

int main() {
    
    // 1. 创建公共的 key 值 key_t ftok(pathname, proj_id) 
    key_t key_val = ftok(_path.c_str(), PROJ_ID); 
   // printf("S2: %d \n", key_val);
    assert(key_val != -1);

    // 2. 创建共享内存 在 已有的 共享内存 内 寻找
    int token = shmget(key_val, PAGE_SIZE, IPC_CREAT | 0666);
    if (token == -1) {
        perror("shmget");
        exit(1);
    }


    // 挂接共享内存 到 进程的 地址空间
    char * address = (char*)shmat(token, nullptr, 0);
    // address 为 共享内存在虚拟内存内 的 起始地址
    // the address may be nullptr

    int fp = open(PIPE, O_RDONLY);

    char buffer[1024];
    while (true) {
        
        ssize_t signal = read(fp, buffer, 1024);
        if (signal == sizeof (uint32_t)) 
        {
            if (strcmp(address, "quit") == 0) break;
            printf("%s \n", address);
        }
    }



    // 从地址空间 内 去 关联
    shmdt(address);

    // 释放共享内存
    // shmctl(token, IPC_RMID, nullptr);


    return 0;
}