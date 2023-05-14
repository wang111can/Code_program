#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {


    
    int fp = open("text.txt", O_WRONLY | O_CREAT, 0777);

    // printf("FILE1: %d\n", fp); 
    // while (1) {

    // }
    // umask(0);
    // int fp = open("text.txt",  O_RDONLY, 0777);

    
    // const char *s = "system\n";
    // write(fp, s, strlen(s));
    // char str[100];
    // memset(str, '\0', sizeof str);
    // read(fp, str, 100); {
    //     fprintf(stdout, "%s", str);
    // }

    // close(fp);

    // while (1) {
        
    //     FILE* fp = fopen("text.txt", "a"); // 在当前进程工作 目录下 创建 文件 
    //     if (fp == NULL) {
    //         perror("fopen");
    //         return 0;    
    //     }

    //     const char *s1 = "hello fwrite\n";
    //     fwrite(s1, strlen(s1), 1, fp);
    //     const char *s2 = "hello fprintf\n";
    //     fprintf(fp, "%s", s2);
    //     const char *s3 = "hello fputs\n";
    //     fputs(s3, fp);


    //     fclose(fp);
    //     fp = fopen("text.txt", "r"); // 在当前进程工作 目录下 创建 文件 
        
    //     char str[100];
    //     printf("-------\n");
    //     while (fgets(str, 100, fp) != NULL) {
    //         fprintf(stdout, "%s", str);
    //     }
    //     sleep(3);
    //     fclose(fp);

    // }



}
