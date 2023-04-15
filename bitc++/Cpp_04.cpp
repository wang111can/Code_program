#include "..\STL\librery.hpp"


// 类的 默认 函数

class A {
private:
    int x;
public :
    A(int x = 0) {
        this->x = x;
    }
    int get_x() {
        return this->x;
    }
};

class test{

private :
    int _x, _y;
    A a;
public :



    // 1 构造
    // 函数 名 和 类名 相同 在 对象 实例化 时自动调用
    // example

    // 2 析构 在 对象 销毁 时 自动 调用 完成 清理 工作
    // 
    ~test() {}

    // 3 拷贝构造 参数必须是类对象 的 引用 
    // 系统自动 生成的 拷贝构造 对 内置类型 进行 值拷贝 自定义类型 调用 自定义类型 的 拷贝 函数
    test(const test& t) {
        _x = t._x;
        _y = t._y; 
    }


    // 4 赋值构造
    
    // 5

    // 6


    // 运算符 重载
    

};

int main() {

    stl::date a = {2023, 4, 15};
    stl::date b = {1, 2, 1};
    a.print();
}