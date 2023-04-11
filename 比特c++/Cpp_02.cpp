#include <iostream>



int main() {


    int a = 0;
    std::cout << typeid(a).name() << std::endl;

    //double &x = a; error 原因 是 x 被 赋予 强制类型 转换 产生 的 double a， x 引用 的 一个 临时 的 double a 产生 了 权限 放大， 临时 变量 具有 常性
    const double &x = a; // 不能 修改      

    /*
    (引用 是 指针 的 再 封装)
    引用 和 指针 的 不同 点
    引用定义时 必须 初始化 指针不用
    引用不可以 改变 引用的对象 指针可以变换 指向 的 对象
    没有 null 引用 但是 有 null 指针
    sizeof 求得 的 是引用 类型 的大小 求指针是 指针的大小
    引用 自加是对 引用 的 对象 加1 指针自加是 往后便宜指向对象的一个类型的大小
    .........
    */  


    return 0;
}

