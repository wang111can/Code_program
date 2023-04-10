#include <iostream>
#include <cassert>


// 创建 命名 空间
namespace test {
    int x1 ; 
    int x2 ;
};
using test::x1; // 展开 命名空间 内 某个 成员


using namespace test; // 展开 命名空间



// 根据 传入数值 从左 往右 给 参数 复值
void func_1(int a, int b = 1, int c = 2) { // 缺省参数
    std::cout << a << ' ' << b << ' ' << c << ' ' << std::endl;

}


// 函数 重载
// 以参数 类型 和 顺序 来 区分 函数
int add(int x, int y) {
    return x + y;
}

long long add(long long x, long long y) {
    return x + y;
}

int& func_2() {
    static int x = 0;
    x ++ ;
    return x;
}


int main()  {

    std::cout << x1 << std::endl; // 指定 访问命名空间
    std::cout << test::x2 << std::endl;
    
    func_1(0);
    assert(1);
    int &t = x1; // 引用 和 引用 的 变量 使用同一块空间
    // 引用 在 定义 时 必须 初始化
    // 一个 变量 可以 有 多个 引用 
    // 一个 引用 只能 引用 一个 变量 且 不能 更改 引用 对象 
    int &y = func_2();
    std::cout << y << std::endl;
    return 0;
}


 