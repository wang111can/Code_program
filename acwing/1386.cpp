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
const int N = 50;

int n, m;
int dis[N][N][2], dis_min[N][N], dis_sum[N][N];
bool st[N][N][2];
// dis[][][0] 表示 不接 国王 dis[][][1] 表示接国王
// dis_min 表示接国王的最小步数 初始值为国王自己走到该点
// dus_sum 表示 以该点作为终点的 所有步数和
pair<int, int> king;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void spfa(int x, int y) {

    queue<array<int, 3>> q;
    memset(dis, 0x3f, sizeof dis);
    q.push({x, y, 0});
    dis[x][y][0] = 0;

    while (q.size()) {
        auto t = q.front(); q.pop();
        st[t[0]][t[1]][t[2]] = false;

        for (int i = 0;i < 8;i ++ ) {
            int a = t[0] + dx[i], b = t[1] + dy[i];
            if (a > 0 && b > 0 && a <= n && b <= m) {
                if (dis[a][b][t[2]] > dis[t[0]][t[1]][t[2]] + 1) {
                    dis[a][b][t[2]] = dis[t[0]][t[1]][t[2]] + 1;
                    if (!st[a][b][t[2]]) {
                        st[a][b][t[2]] = true;
                        q.push({a, b, t[2]});
                    }
                }
            }
        }
        // 去接 国王
        if (!t[2]) {
            int d = dis[t[0]][t[1]][t[2]] + max(abs(t[0] - king.x), abs(t[1] - king.y));
            if (dis[t[0]][t[1]][!t[2]] > d) {
                dis[t[0]][t[1]][!t[2]] = d;
                if (!st[t[0]][t[1]][!t[2]]) {
                    st[t[0]][t[1]][!t[2]] = true;
                    q.push({t[0], t[1], 1});
                }
            }
        }
    }

    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
            if (dis[i][j][0] == inf) {
                dis_sum[i][j] = inf;
            }
            else dis_sum[i][j] += dis[i][j][0];
        }
    }
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
            dis_min[i][j] = min(dis_min[i][j], dis[i][j][1] - dis[i][j][0]); //
        }
    }
    
}

void solve() {
    cin >> n >> m;
    char y; int x; cin >> y >> x;
    king = {x, y - 'A' + 1};
    
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
            dis_min[i][j] = max(abs(y - 'A' + 1 - j), abs(x - i));
        }
    }
    while (cin >> y >> x) {
        spfa(x, y - 'A' + 1);
    }

    int ans = inf;
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
            ans = min(ans, dis_sum[i][j] + dis_min[i][j]);
        }
    }
    cout << ans << endl;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
