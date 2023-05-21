#include "System_v.hpp"



// 通过管道来 使 共享内存 实现管道控制
Pipe AccessControl;

int main() {

    // 1. 创建公共的 key 值 key_t ftok(pathname, proj_id) 
    key_t key_val = ftok(_path.c_str(), PROJ_ID); 
    //printf("S1: %d \n", key_val);
    assert(key_val != -1);
    
    // 2. 创建共享内存 发起者 创建一个 全新的 共享内存
    int token = shmget(key_val, PAGE_SIZE, IPC_CREAT | IPC_EXCL | 0666);
    
    if (token == -1) {
        perror("shmget");
        exit(1);
    }


    // 挂接共享内存 到 进程的 地址空间
    char * address = (char*)shmat(token, nullptr, 0);
    // address 为 共享内存在虚拟内存内 的 起始地址
    // the address may be nullptr


    int fp = open(PIPE, O_WRONLY);

    while (true) {
        ssize_t sz = read(0, address, PAGE_SIZE - 1);
        
        if (sz > 0) {
            uint32_t signal = 1;
            write(fp, &signal, sizeof (uint32_t)); // 写入管道文件 
            address[sz - 1] = '\0'; // 换掉换行符
            if (strcmp(address, "quit") == 0) {
                break;
            }
        }

    }
    // 从地址空间 内 去 关联
    shmdt(address);

    // 发起者释放共享内存
    shmctl(token, IPC_RMID, nullptr);


    return 0;
}
