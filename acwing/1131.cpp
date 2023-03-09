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
typedef unsigned long long ull;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

const int N = 1000;

int g[N][N], n, m, p;
int dis[N][N], refle[N][N];
int st[N][N];
int key[N];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

struct Node{
    int x, y, k;
};

int bfs() {

    memset(dis, 0x3f, sizeof dis);
    dis[1 * m + 1][key[1 * m + 1]] = 0;


    queue<Node> q;
    q.push({1, 1, key[1 * m + 1]});
    
    while (q.size()) {
        auto t = q.front(); q.pop();

        if (t.x * m + t.y == (n + 1) * m) {
            return dis[t.x * m + t.y][t.k];
        }
        if (st[t.x * m + t.y][t.k]){
            // cout << "continue" << endl;
            // cout << t.x  << ' ' << t.y << ' ' << t.k << endl; 
            continue;
        }
        st[t.x * m + t.y][t.k] = true;
        int x = t.x, y = t.y;
        for (int i = 0;i < 4;i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            int state = t.k;

            if (a  && b && a <= n && b <= m && g[t.x * m + t.y][a * m + b] != inf) {
                // cout << a << ' ' << b << endl;
                if (g[t.x * m + t.y][a * m + b]) {
                    if (((state >> g[t.x * m + t.y][a * m + b]) & 1) == 0){
                        // cout << "continue" << endl;
                        continue;
                    }
                        
                }
                state |= key[a * m + b];
                // cout << t.x << ' ' << t.y << ' ' << t.k << endl;
                // cout << a << ' ' << b << ' ' << state << endl;
                // cout << "_______" << endl;
                if (dis[a * m + b][state] > dis[t.x * m + t.y][t.k] + 1) {
                    dis[a * m + b][state] = dis[t.x * m + t.y][t.k] + 1;
                    q.push({a, b, state});
                }
            }
        }
    
    }



    return -1;
}

void solve() {
    cin >> n >> m >> p;
    int k; cin >> k;

    while (k -- ) {
        int a, b, c, d, G;
        cin >> a >> b >> c >> d >> G;
        g[a * m + b][c * m + d] = g[c * m + d][a * m + b] = G;
        if (!G) {
        
            g[a * m + b][c *m + d] = g[c *m + d][a * m +b] = inf;
        }
    }
    int s; cin >> s;
    while (s -- ) {
        int a, b, c; cin >> a >> b >> c;
    
        key[a * m + b] |= 1 << c;
    }

    cout << bfs() << endl;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
