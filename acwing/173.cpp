#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int> (m + 1)), dis(n + 1, vector<int> (m + 1, 0x3f3f3f3f));
    queue<pair<int, int>> q; 
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
            char c; cin >> c;
            int t = c - '0';
            if (t == 1) {
                dis[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    while (q.size()) {
        auto t  = q.front(); q.pop();
        int x = t.first, y = t.second;
        
        for (int i = 0;i < 4;i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a && b && a <= n && b <= m) {
                if (dis[a][b] > dis[x][y] + 1) {
                    dis[a][b] = dis[x][y] + 1;
                    q.push({a, b});
                }
            }
        }
    }
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
            cout << dis[i][j] << ' ';
        }
        cout << endl;
    }



    return 0;
}

