#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "Task.hpp"

#define PROCESS_NUM 5

using namespace std;

int waitCommand(int waitFd, bool &quit) //如果对方不发，我们就阻塞
{
    uint32_t command = 0;
    ssize_t s = read(waitFd, &command, sizeof(command));
    if (s == 0)
    {
        quit = true;
        return -1;
    }
    assert(s == sizeof(uint32_t));
    return command;
}

void sendAndWakeup(pid_t who, int fd, uint32_t command)
{
    write(fd, &command, sizeof(command));
    cout << "main process: call process " << who << " execute " << desc[command] << " through " << fd << endl;
}

int main()
{
    // 代码中关于fd的处理，有一个小问题，不影响我们使用，但是你能找到吗？？
    load();
    // pid: pipefd
    vector<pair<pid_t, int>> slots;
    // 先创建多个进程
    for (int i = 0; i < PROCESS_NUM; i++)
    {
        // 创建管道
        int pipefd[2] = {0};
        int n = pipe(pipefd);
        assert(n == 0);
        (void)n;

        pid_t id = fork();
        assert(id != -1);
        // 子进程我们让他进行读取
        if (id == 0)
        {
            // 关闭写端
            close(pipefd[1]);
            // child
            while (true)
            {
                // pipefd[0]
                // 等命令
                bool quit = false;
                int command = waitCommand(pipefd[0], quit); //如果对方不发，我们就阻塞
                if (quit)
                    break;
                // 执行对应的命令
                if (command >= 0 && command < handlerSize())
                {
                    callbacks[command]();
                }
                else
                {
                    cout << "非法command: " << command << endl;
                }
            }
            exit(1);
        }
        // father,进行写入，关闭读端
        close(pipefd[0]); // pipefd[1]
        slots.push_back(pair<pid_t, int>(id, pipefd[1]));
    }
    // 父进程派发任务
    srand((unsigned long)time(nullptr) ^ getpid() ^ 23323123123L); // 让数据源更随机
    while (true)
    {
        // 选择一个任务, 如果任务是从网络里面来的？
        int command = rand() %  handlerSize();
        // 选择一个进程 ，采用随机数的方式，选择进程来完成任务，随机数方式的负载均衡
        int choice = rand() % slots.size();
        // 把任务给指定的进程
        sendAndWakeup(slots[choice].first, slots[choice].second, command);
        sleep(1);

        // int select;
        // int command;
        // cout << "############################################" << endl;
        // cout << "#   1. show funcitons      2.send command  #" << endl;
        // cout << "############################################" << endl;
        // cout << "Please Select> ";
        // cin >> select;
        // if (select == 1)
        //     showHandler();
        // else if (select == 2)
        // {
        //     cout << "Enter Your Command> ";
        //     // 选择任务
        //     cin >> command;
        //     // 选择进程
        //     int choice = rand() % slots.size();
        //     // 把任务给指定的进程
        //     sendAndWakeup(slots[choice].first, slots[choice].second, command);
        // }
        // else
        // {
        // }
    }

    // 关闭fd, 所有的子进程都会退出
    for (const auto &slot : slots)
    {
        close(slot.second);
    }

    // 回收所有的子进程信息
    for (const auto &slot : slots)
    {
        waitpid(slot.first, nullptr, 0);
    }
}