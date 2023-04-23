#include "..\STL\librery.hpp"


void test(char *x) {
    std::cout << "char*" << std::endl;
}
// void test(char ch) {
//     std::cout << "char" << std::endl;
// }


int main() {
    std::string a = "1111";
    std::cout << a.capacity();
}

