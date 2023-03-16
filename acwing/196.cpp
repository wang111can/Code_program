
/*
这道题目很明显是和素数也就是质数有关.题目让我们求出[l,r][l,r]之中的素数,那么我们很显然是需要素数筛,问
题是这道题目中[l,r][l,r]特别大,我们无法求出[1,r][1,r]中的素数,但是我们发现任何一个合数n,肯定会包括一个不超过n√n的素数.
通过上面这个非常有用的性质,我们就可以只需要枚举出2~r√r 之间的所有质数.
既然如此的话,我们对于每一个质数p而言,我们就标记i*p为合数.(Lp≤i≤rp)(Lp≤i≤rp) 
*/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

//sqrt(2^31 - 1)
const int N = 1e6 + 10;

bool st[N];
int primes[N], cnt;

void get_primes(int n) {
    memset(st, 0, sizeof st);
    cnt = 0;
    for (int i = 2; i <= n; ++ i) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] * i <= n; ++ j) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    int l, r;
    while (~scanf("%d%d", &l, &r)) {
        get_primes(50000);

        //把[l,r]区间内所有的合数用他们的最小质因子筛掉
        memset(st, 0, sizeof st);
        for (int i = 0; i < cnt; ++ i) {
            LL p = primes[i];
            for (LL j = max(2 * p, (l + p - 1) / p * p); j <= r; j += p)
                st[j - l] = true;
        }

        //剩下的所有的都是素数了
        cnt = 0;
        for (int i = 0; i <= r - l; ++ i)
            if (!st[i] && i + l > 1)
                primes[cnt ++ ] = i + l;

        if (cnt < 2) printf("There are no adjacent primes.\n");
        else {
            //计算间隔
            int minp = 0, maxp = 0;
            for (int i = 0; i + 1 < cnt; ++ i) {
                int d = primes[i + 1] - primes[i];
                if (d < primes[minp + 1] - primes[minp]) minp = i;
                if (d > primes[maxp + 1] - primes[maxp]) maxp = i;
            }
            printf("%d,%d are closest, %d,%d are most distant.\n", 
            primes[minp], primes[minp + 1], 
            primes[maxp], primes[maxp + 1]);
        }
    }
    return 0;
}

