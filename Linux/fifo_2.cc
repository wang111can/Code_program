#include "fifo.hpp"

using namespace std;


int main()
{



    // 读取方
    int fd = open(_path.c_str(), O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    char Read_Buffer[1024];

    int cnt = 0;
    while (1) {
        memset(Read_Buffer, '\0', sizeof Read_Buffer);
        ssize_t sz = read(fd, Read_Buffer, sizeof Read_Buffer);
        if (sz > 0) {

            printf("已读%d 条信息: %s\n", ++ cnt, Read_Buffer);
        }
        else if (sz == 0) {
            cerr << "输出方关闭\n" << endl;
            
            unlink(_path.c_str());
            exit(0);
        }
        // 读取失败
        else {
            perror("read");
            break;
        }
    }   



    unlink(_path.c_str());
    close(fd);

    return 0;
}
