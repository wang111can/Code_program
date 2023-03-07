#include <bits/stdc++.h>
using namespace std;

#define io std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define x first
#define y second
#define fr front
#define db double
#define pb push_back
#define pi acos(-1) 
#define all(x) x.begin(), x.end()
mt19937_64 mrand(random_device{}());

typedef pair<int, int> PII;
typedef pair<double, double > PDD;
typedef long long ll ;
typedef unsigned long long ULL;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

const int N = 2e5 + 10;

vector<int> e[N];
int n, m, p[N];
int ans[N];

int find(int x) {
    if (p[x] != x) return p[x] = find(p[x]);
    return p[x];
}

void solve() {
    cin >> n >> m;
    for (int i = 1;i <= N - 10;i ++ ) {
        p[i] = i;
    }

    int now = n;
    while (m -- ) {
        int op, a, b; cin >> op >> a >> b;
        if (op == 1) {
            int x = find(a), y = find(b);
            if (x != y) {
                e[++ n].push_back(x);
                e[n].push_back(y); 
                p[x] = p[y] = n;
                
            }
        }
        else {
            int x = find(a);
            ans[x] += b;
        }
    }

    function<void(int, int)> dfs = [&](int u, int fa) {
        ans[u] += ans[fa];
        for (auto x : e[u]) {
            dfs(x, u);
        }
    };

    for (int i = 1;i <= n;i ++ ) {
        if (p[i] == i) {
            dfs(i, 0);
        }
    }

    for (int i = 1;i <= now;i ++ ) {
        cout << ans[i] << ' ' ;
    }
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}



// 版本 1 不知道哪写错了
// #include <bits/stdc++.h>
// using namespace std;

// #define io std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
// #define x first
// #define y second
// #define fr front
// #define db double
// #define pb push_back
// #define pi acos(-1) 
// #define all(x) x.begin(), x.end()
// mt19937_64 mrand(random_device{}());

// typedef pair<int, int> PII;
// typedef pair<double, double > PDD;
// typedef long long ll ;
// typedef unsigned long long ULL;
// const double eps = 1e-8;
// const int inf = 0x3f3f3f3f;
// const ll INF = 1e18;

// const int N = 10010;

// vector<pair<int, int>> e[N];
// vector<int> ops[N];
// int ans[N];
// int n, m, p[N];

// int find(int x) {
//     if (p[x] != x) {
//         return p[x] = find(p[x]);
//     }
//     return p[x];
// }

// void solve() {
//     cin >> n >> m;
//     for (int i = 1;i <= n;i ++ ) {
//         p[i] = i;
//         e[i].push_back({i, 1});
//     }
//     for (int i = 1;i <= n;i ++ ) {
//         ops[i].push_back(0);
//     }
    
//     for (int i = 2;i <= m + 1;i ++ ){
//         int op, a, b;
//         cin >> op >> a >> b;
//         if (op == 1) {
            
//             int x = find(a), y = find(b);
//             if (x != y) {
//                 // 分配 
//                 if (ops[x].size() < ops[y].size()) {
//                     swap(x, y);
//                 }
//                 int sz = ops[x].size();
//                 if (sz > 0) {        
//                     for (auto pa: e[x]) {
//                         int v = pa.x, times = pa.y;
//                         ans[v] += ops[x][sz - 1] - ops[x][times - 1];     
//                         e[y].push_back({v, i});
//                     }
//                 }
                
//                 p[x] = y;
//             } 
 
//         }
//         else {
//             int x = find(a);
//             ops[x].push_back(b);
//             int sz = ops[x].size() - 1;
//             ops[x][sz] += ops[x][sz - 1];
//         }

//     }
//     for (int i = 1;i <= n;i ++ ) {
//         if (p[i] == i) {
//             for (auto pa: e[i]) {
//                 int v = pa.x, times = pa.y;
//                 ans[v] += ops[i][ops[i].size() - 1] - ops[i][times - 1];
//             }
//         }
//     } 

//     for (int i = 1;i <= n;i ++ ) {
//         cout << ans[i] << ' ' ;
//     }





// }

// int main() {
// 	io; int T; T = 1;
//     while (T -- ){
//         solve();
//     }
// 	return 0;
// }
