#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1 * 1e5 + 10;

array<int, 4> q[N];
int cnt[N], ans[N], a[N], K[N];
int n, m;


int main()
{
    scanf("%d", &n);
    for (int i = 1;i <= n;i ++ ) scanf("%d", &a[i]);
    scanf("%d", &m);
    
    int l, r, k;
    for (int i = 0;i < m;i ++ )
    {
        scanf("%d%d%d", &l, &r, &k);
        q[i] = {l, r, k, i};
    }
    int M = 500 ;
    sort(q, q + m, [&](array<int, 4> a, array<int, 4> b){
                        if (a[0] / M != b[0] / M) return a[0] / M < b[0] / M;
                        else return a[1] / M < b[1] / M;
                    }
    );

    auto add = [&](int x)
    {
        cnt[K[x]] -- ;
        cnt[++ K[x]] ++ ;
    };
    auto del = [&](int x)
    {
        cnt[K[x]] -- ;
        cnt[-- K[x]] ++ ;
    };
    
    l = 1, r = 0;
    for (int i = 0;i < m;i ++ )
    {
		while (r < q[i][1]) add(a[++ r]);
		while (l > q[i][0]) add(a[-- l]);
		while (r > q[i][1]) del(a[r -- ]);
		while (l < q[i][0]) del(a[l ++ ]);
		ans[q[i][3]] = cnt[q[i][2]];
    }
    for (int i = 0;i < m;i ++ ) printf("%d\n", ans[i]);
    
    return 0;
    
}
