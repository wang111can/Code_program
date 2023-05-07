# 体系

冯诺依曼体系结构: <br>
1. 输入设备    
2. 输出设备
3. 运算器
4. 存储器 --> 内存
5. 控制器 central processing unit

<br>

# 进程Process

### 概念
> 由一个PCB结构体来 描述 <br>
```c_cpp
struct PCB{
    struct PCB *next;
}
```

> 进程 = 对应的代码和数据 + 程序对应的PCB结构体 <br>
> 进程信息通过 /proc/ 文件夹查看 <br>
> ps 查看进程 <br>
> ps axj 查看所有进程 <br>
> kill -9 + pid 杀掉进程 <br>

**4 大性质**
1. 竞争性 ： 优先级(高效合理的利用有限的资源)
2. 独立性 ： 进程独享资源
3. 并行 ：多个进程在多个 cpu 下同时运行
4. 并发 ：多个进程在一个 cpu 下采取进程切换的 方式运行


*** 

cpu 与操作系统 运行某一个进程，本质是从task_struct 结构体队列中 选择 一个 task_struct 来执行它的 代码 <br>

### 系统调用函数
1. pid_t fork() 创建子进程
> 返回值：对父进程返回pid，对子进程返回 0，创建失败返回 -1 <br> 
> 父子进程代码共享 变量再独自开辟空间存储 <br>


### 进程状态
> 新建 <br>
> 运行 (进程在运行队列中等待 并非一定在被cpu处理) <br>
> 阻塞: 进程运行需要的资源(磁盘，网卡...) 没有获得, 正在等待非cup资源就绪 <br>
> 挂起: 将长时间不执行的 进程代码和数据换出到磁盘 <br>

### Linux 内的进程状态

> 使用 kill 命名来 改变进程的 状态

```c_cpp

R, (running)
S, (sleeping) 可中断sleep
D, (disk sleep) 不可中断sleep (cup 也 不能 清理)
T, (stopped) 暂停/调试 状态
t, (tracing stop)
X, (dead) 终止(瞬时状态)
Z, (zombie) 僵尸状态 {
    
    是什么： 进程 终止 但未回收

    为什么: 为了让Os 或 父进程来 回收

}

```
> 进程状态 后加上 "+" 号 说明这个进程属于前台进程(占用控制台命令行) <br>
> 父进程退出子进程还在运行(孤儿进程) 则会被 1 号进程领养


### 优先级

为什么：cpu 资源有限, 进程太多 <br>
什么是: 确定获得资源的 先后顺序 <br>
优先级 = 老优先级值(const) + nice值 <br>




### 环境变量

**在linux里**
1. 导入环境变量
export environment variable name = '' <br>

2. 显示环境变量
env <br>

3. 显示变量
set <br>


**在编程语言里** 
```c_cpp

// 由 父进程 导入
//           命令行参数              环境变量参数
int main(int argc, char *argv[], char *env[]) {

// 获取环境变量
    // extern char *environ;
    // getenv("environment variable name")
// 设置环境变量
    // setenv(" ", " ")
}

```

**命令行参数** <br>
argc: 传入参数个数 <br>
argv: 传入参数 <br>

作用:
    可以使同一个函数通过不同的参数执行不同的功能 <br>

***

# 进程地址空间

```c_cpp

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int g_val = 100;

int main(int argc, char *argv[], char *evn[]) {

    pid_t id = fork();
    if (id == 0) {
        while (1) {
            printf("I am child, pid: %d, ppid: %d, g_val: %d, &g_val: %p\n", getpid(), getppid(), g_val, &g_val);
            sleep(1);
            g_val = 1;
        }
    }
    else if (id != -1) {
        
        while (1) {
            printf("I am father, pid: %d, ppid: %d, g_val: %d, &g_val: %p\n", getpid(), getppid(), g_val, &g_val);
            sleep(1);
        }
    }
    


    return 0;
}

```

运行上述代码会发现 g_val的地址 是 一样的
子进程改变了 g_val的 值 但是 父进程 的 g_val 没有变化
可以得出 这时的 地址 不是计算机内 的 物理地址 而是虚拟地址 <br>



```
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int un_g_val;
int g_val = 100;

int main(int argc, char *argv[], char *evn[]) {


    printf("%p\n", argv); // 命令行参数区
    printf("code: %p\n", main); // 代码段区

    printf("uninit: %p\n", &un_g_val); // 未初始化变量区
    
    printf("init: %p\n", &g_val); // 初始化变量区

    char *p = (char*) malloc(10);

    printf("heap: %p\n", p); // 堆区

    int a;
    printf("stack: %p\n", &a); // 栈区


    return 0;
}

```

虚拟内存 从上到下依次为: <br>

***

内核区 <br>

命令行参数 环境变量区 <br>

栈区 (从上往下增长 / 其他的都是从下往上增长) <br>

共享区<br>

堆区 <br>

未初始化变量区 <br>

初始化变量区 <br>

代码区 <br>

