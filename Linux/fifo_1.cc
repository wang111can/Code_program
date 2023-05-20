#include "fifo.hpp"

using namespace std;


int main()
{
    int ret_status = mkfifo(_path.c_str(), MODE);
    if (ret_status == -1) {
        perror("mkfifo");
        exit(1);
    }
        

    // 写入方
    int fd = open(_path.c_str(), O_WRONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }



    char Write_Buffer[1024];
    string str = "I'm input side";
    int cnt = 0;
    while (1) {
        memset(Write_Buffer, '\0', sizeof Write_Buffer);
        snprintf(Write_Buffer, sizeof Write_Buffer, "%s : [%d]", str.c_str(), ++ cnt);
        write(fd, Write_Buffer, strlen(Write_Buffer)); 
            
        sleep(1);
    }   




    close(fd);

    return 0;

}
