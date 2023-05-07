#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int un_g_val;
int g_val = 100;

int main(int argc, char *argv[], char *evn[]) {

    char *str = "hello";
    printf("string: %p\n", &(*str));

    printf("command line: %p\n", argv); // 命令行参数区
    printf("code: %p\n", main); // 代码段区

    printf("uninit: %p\n", &un_g_val); // 未初始化变量区
    
    printf("init: %p\n", &g_val); // 初始化变量区

    char *p = (char*) malloc(10);

    printf("heap: %p\n", p); // 堆区

    int a;
    printf("stack: %p\n", &a); // 栈区


    return 0;
}