#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m, s, t, k;
vector<pair<int, int>> e[N], ue[N];


int main() {
    cin >> n >> m;
    while (m -- ) {
        int a, b, c; cin >> a >> b >> c;
        e[a].push_back({b, c});
        ue[b].push_back({a, c});
    }
    cin >> s >> t >> k;
    if (s == t) k ++ ;
    const int inf = 0x3f3f3f3f;
    vector<int> eval(n + 1, inf);  // 估价 值 == 原始值 + eval[u] 终点 到 当前点 的 最短距离   
    using PII = pair<int, int>;
    using PIII = pair<int, pair<int, int>>;

    auto dijkstra = [&](){
        priority_queue<PII, vector<PII>, greater<PII>> q;
        eval[t] = 0;
        q.push({0, t});

        while (q.size()) {
            auto dot = q.top(); q.pop();
            for (auto p : ue[dot.second]) {
                if (eval[p.first] > dot.first + p.second) {
                    eval[p.first] = dot.first + p.second;
                    q.push({eval[p.first], p.first});
                }
            }
        } 
    };
    
    auto Astar = [&](){
        vector<int> cnt(n + 1, 0);
        priority_queue<PIII, vector<PIII>, greater<PIII>> q;
        
        q.push({eval[s], {0, s}});
        while (q.size()) {
            PIII dot = q.top(); q.pop();
            int evaluate = dot.first, dis = dot.second.first, u = dot.second.second;
            cnt[u] ++ ;
            if (cnt[t] == k) {
                return dis;
            }
            for (auto p : e[u]) {
                int x = p.first, y = p.second;
                if (cnt[x] < k) {
                    q.push({dis + y + eval[x], {dis + y, x}});
                }
            }

        }
        return -1;
    };

    dijkstra();

    cout << Astar() << endl;

    return 0;

}