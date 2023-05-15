#include "..\STL\librery.hpp"


void test(char *x) {
    std::cout << "char*" << std::endl;
}
// void test(char ch) {
//     std::cout << "char" << std::endl;
// }


int main() {
    stl::string a("11111", 100);
    stl::string b(a, 1, 1000);
    a.show();
    b.show();
}

