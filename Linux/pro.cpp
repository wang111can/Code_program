#include <iostream>
#include <unistd.h>

using namespace std;


int main() {
    
    int cnt = 0;
    for (int i = 0;i <= 100;i ++ ) {
        cout << '[';
        
        for (int j = 1;j <= cnt;j ++ ) {
            cout << '-';
        }
        for (int j = 100;j >= cnt + 1;j -- ) {
            cout << ' ';
        }
        cnt ++ ;
        cout << ']';
        cout << '\r';
        fflush(stdout);
        usleep(10000);
        
    }
    printf("\n");
  
      return 0;
}
