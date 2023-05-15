#include <iostream>


// C++ 如何 支持 重载
/*
        Cpp 是以 函数名 + 函数 参数 来 创建 符号表
        C 是以 函数名 来 创建符号表
*/
/*

预处理： 头文件展开 宏替换 ....
        文件 以 .i 结尾

编译: 语法检查 生成汇编代码
        文件 以 .s 结尾 的 汇编 代码


汇编: 翻译 汇编 代码 生成 机械码
        文件 以 .o 结尾 

链接：
    文件 以 .out / .exe结尾

*/



// 在 C++ 内部 想 使用 用 C 编译规则 编译 的 东西 需加上 extern C

extern "C" {
        // 使 编译器 使用 C 的 规则 去 链接 和 查找函数
        // 目标 文件 或者 代码 的 路径 / 内容

}      
/*
若 在 C 内部 想 使用 C++ 的 函数  需 在 C++ 函数 编译 处 加上 extern "C" 而不是 C 的 内部 因为 C 无法 识别 C++ 的 语法 与 规则
#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
*/


int main() {    

    return 0;
}    