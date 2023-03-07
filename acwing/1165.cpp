
// 01 分数规划
// s / t > mid
// mid 最大值求
// s 为 环内点权和 t 为环 长度
// s / t > mid
// s > t * mid
// s - t * mid > 0
// 可以设 t = 1
// s - t > 0

#include <bits/stdc++.h>
using namespace std;

#define io std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define x first
#define y second
#define fr front
#define db double


typedef pair<int, int> PII;
typedef long long LL ;

const int N = 1000 * 1000 + 10, M = N;

int h[N], e[M], w[M], ne[M], idx;
int cnt[N];
db dist[N];
bool st[N];
int n;


void add(int a, int b, int c)  // 添加一条边a->b，边权为c
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}


bool check(db mid)
{

    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    
    queue<int> q;
    for (int i = 0;i < 700;i ++ ) // 两两 字母组合的和
        q.push(i), st[i] = true;
    int l = 0;    
    while (q.size())
    {
        int t = q.fr(); q.pop();
        
        st[t] = false;
        for (int i = h[t]; ~i ;i = ne[i])
        {
            int j = e[i];
            if (dist[j] < dist[t] + w[i] - mid)
            {
                dist[j] = dist[t] + w[i] - mid ;
                l ++ ;
                cnt[j] = cnt[t] + 1;
                if (l > 10000) return true; // 玄学 
                if (cnt[j] >= 700) return true;
                if (!st[j]) 
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
    
    
}


int main()
{
	io;
    while (cin >> n, n)
    {
        memset(h, -1, sizeof h);
        for (int i = 0;i < n;i ++ )
        {
            string str; cin >> str;
            if (str.size() >= 2)
            {
                int len = str.size();   
                int l1 = (str[0] - 'a') * 26 + str[1] - 'a';
                int l2 = (str[len - 2] - 'a') * 26 + str[len - 1] - 'a';
            
                add(l1, l2, len); // 把 2 个字母的组合看为 一个 26 进制数
            }
        }

        
        
        
        if (!check(0)) cout << "No solution\n";
        else 
        {
            db l = 0, r = 1000;
            while (r - l > 0.0001)
            {
                db mid = (l + r) / 2;
                if (check(mid)) l = mid;
                else r = mid;
            }
            //cout << r << endl;
            printf("%.2lf \n", r);
        }
        
    }
	return 0;
}



