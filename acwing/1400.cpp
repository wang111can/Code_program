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

const int N = 50;

char g[N][N];
int deg[N];
int n, m;
vector<int> e[N];


void build(char ch, int a, int b, int c, int d) {
    int u = ch - 'A';
    vector<bool> st(N, 0);
    for (int i = b;i <= d;i ++ ) {
        if (!st[g[a][i] - 'A'] && g[a][i] != ch) {

            e[u].push_back(g[a][i] - 'A');
            deg[g[a][i] - 'A'] ++ ;
            st[g[a][i] - 'A'] = true;
        }
    }
    for (int i = b;i <= d;i ++ ) {
        if (!st[g[c][i] - 'A'] && g[c][i] != ch) {
            deg[g[c][i] - 'A'] ++ ;
            e[u].push_back(g[c][i] - 'A');
            st[g[c][i] - 'A'] = true;
        }
    }
    
    for (int i = a;i <= c;i ++ ) {
        // cout << i << ' ' << b << endl;
        if (!st[g[i][b] - 'A'] && g[i][b] != ch) {
             deg[g[i][b] - 'A'] ++ ;
            e[u].push_back(g[i][b] - 'A');
            st[g[i][b] - 'A'] = true;
        }
    }

    for (int i = a;i <= c;i ++ ){
        if (!st[g[i][d] - 'A'] && g[i][d] != ch) {
            e[u].push_back(g[i][d] - 'A');
            st[g[i][d] - 'A'] = true;
            deg[g[i][d] - 'A'] ++ ;
            
        } 
    }
}

int q[N];bool st[N];
string path;

void dfs(string s) {
    
    if (s.empty()) {
        cout << path << endl;
        return ;
    }
    sort(all(s)); // 字典序
    
    for (int i = 0;i < s.size();i ++ ){
        char c = s[i];
        path += c;
        string t =  s.substr(0, i) + s.substr(i + 1);
        for (auto v : e[c - 'A']) {
            deg[v] -- ;
            if (deg[v] == 0) {
                t += v + 'A';
            }
        }
        dfs(t);
        for (auto v : e[c - 'A']) {
            deg[v] ++ ;
        }
        path.pop_back();
    
        
    }
    
    
}

void topsort()
{
    string s;
    for (char i = 'A'; i <= 'Z'; i ++ )
        if (!deg[i - 'A'] && st[i - 'A'])
            s += i;
    dfs(s);
}


void solve() {
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) cin >> (g[i] + 1);
    
    for (char ch = 'A';ch <= 'Z';ch ++ ) {
        int a = n + 1, b = m + 1, c = 0, d = 0;
        for (int i = 1;i <= n;i ++ ) {
            for (int j = 1;j <= m;j ++ ) {
                if (g[i][j] == ch) {
                    a = min(a, i);
                    b = min(b, j);
                    c = max(c, i);
                    d = max(d, j);
                }
            }
        }
        // cout << a << ' ' << b << '_' << c << ' ' << d << endl;
        if (c && a != n + 1) {
            st[ch - 'A'] = true;
            build(ch, a, b, c, d);
        }
            
    }
    topsort();
    // cout << endl;
    // for (char ch = 'A';ch <= 'C';ch ++ ) {
    //     cout << ch << ':' << endl;
    //     for (auto x : e[ch - 'A']) {
    //         cout << char(x + 'A') << ' ' ;
    //     }
    //     cout << endl;
    // }

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
