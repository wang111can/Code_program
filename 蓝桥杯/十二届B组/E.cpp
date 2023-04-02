#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using ll = long long;

const int N = 3000;

vector<pair<int, int>> e[N];
ll dis[N];
bool st[N];

int spfa() {
	queue<int> q; 
	memset(dis, 0x3f, sizeof dis); dis[1] = 0;
	q.push(1);
	
	while (q.size()) {
		int u = q.front(); q.pop();
		st[u] = false;
		for (auto p : e[u]) {
			int x = p.x, y = p.y;
			if (dis[x] > dis[u] + y) {
				dis[x] = dis[u] + y;
				if (!st[x]) {
					q.push(x);
					st[x] = true;
				}
			}
		}
	}
	return dis[2021];
}

int main() {
	for (int i = 1;i <= 2021;i ++ ) {
		for (int j = i + 1;j <= i + 21;j ++ ) {
			e[i].push_back({j, i * j / __gcd(i, j)});
			e[j].push_back({i, i * j / __gcd(i, j)});
			
		}
	}
	
	cout << 0x3f3f3f3f << endl;
	cout << spfa();
}
