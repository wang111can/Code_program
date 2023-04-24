#include "..\STL\librery.hpp"
// C/C++ 的内存 管理

using namespace std;

class A{
private:
    int _a;
public :
    A(int a = 0): _a(a){
        cout << _a << endl;
    }
};

int main() {
    int *p1 = new int[5]; // 申请 5个int 类型 的 数数组
    int *p2 = new int(5); // 申请 一个 int 空间 初始化 为 5
    int *p3 = new int[5] {1, 2, 3, 4, 5}; //  申请 5个int 类型 的 数数组 并且 初始化
    A *a1 = new A(1);
    A *a2 = new A;

    //  new 与 delete 是 操作符 可以 重写 

    // new 是 malloc 的 再 包装
    // 在 创建 内置类型 时 与 malloc 没有 区别
    // new 创建 自定义 对象时 会调用 对于 的 默认构造函数
    

    delete []p1; // 数组使用 [] 匹配 delete
    delete p2; 
    delete []p3;

    // delete 是 free 的 再封装 
    // 释放空间时 会调用 对应 的 析构 函数


    // int n = 0;        
    // try{
    //     while (1) {
    //         char *p = new char[1024 * 1024 * 1024];
    //         n ++ ;
    //     }
    // }
    // catch(const exception &e) {
    //     cout << n << endl;
    //     cout << e.what() << endl;       
    // }

    

    return 0;
}