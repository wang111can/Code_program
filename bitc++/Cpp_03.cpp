#include "stl.h"
#define ADD(x, y) ((x) + (y))

/*
宏 的 优缺点 ： 没有 类型检查，可读性差 ..... 
            维护 性强 提高效率(减少 栈帧建立)
*/

// 编译时 在 调用 位置 展开 该函数 减少 调用 寻址 空间  
// 编译器 会 判断 该函数 是否 满足 展开 条件
// inline 函数 声明与定义分离 可能 会发生 函数 链接 寻址 找不到 目标函数 因为 inline 函数 不 加入 符号表
inline void func_1() {
    std::cout << "inline" << std::endl;
}

/* 
    类 与 结构体 的 区别
    struct 
        默认 权限 为 public
    class  
        默认 权限 为 private
*/

struct s1 {
    void init() {
        std::cout << "init" << std::endl;
    }
private :
    int a;

    /*......*/
};

class c1 {

};

int main() {
    std::cout << ADD(1, 1 + 1) << std::endl;

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i : a) std::cout << i << std::endl;

    std::cout << stl::Creator_name << std::endl;

    return 0;
}   