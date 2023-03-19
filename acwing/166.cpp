#include <bits/stdc++.h>
using namespace std;

const int N = 9, M = 1 << 9;

int cnt[M], mp[M];
int col[N], row[N], g[3][3];
string str;

void init() {
    for (int i = 0; i < 3;i ++ ) {
        for (int j = 0;  j < 3; j ++ ) {
            g[i][j] = M - 1;
        }
    }
    for (int i = 0;i < 9;i ++ ) col[i] = row[i] = M - 1;
}

inline int get_(int x, int y) {
    return col[y] & row[x] & g[x / 3][y / 3];
}

inline int lowbit(int x) {
    return x & -x;
}

inline void mark(int x, int y, int number, bool draw) {
    if (draw) {
        str[x * N + y] = number + '1';
    }
    else str[x * N + y] = '.';

    int state = 1 << number;
    if (!draw) state = - state;
    col[y] -= state;
    row[x] -= state;
    g[x / 3][y / 3] -= state;
}

bool dfs(int dot) {
    if (!dot) return true;


    int state = 10, x, y;
    for (int i = 0;i < N;i ++ ) {
        for (int j = 0;j < N;j ++ ) {
            if (str[i * N + j] == '.')
                if (cnt[get_(i, j)] < state) { // 从 剩余 点 数 小 的 点 来 枚举
                    state = cnt[get_(i, j)];
                    x = i, y = j;
                }
         }
    }
    state = get_(x, y);
    for (int i = state; i;i -= lowbit(i)) {
        int number = mp[lowbit(i)]; // 最低 位 数字
        mark(x, y, number, true);
        if (dfs(dot - 1)) return true;
        mark(x, y, number, false);
    }

    return false;
}



void solve() {

    string t;

    for (int i = 0;i < M;i ++ ) {
        for (int j = 0;j < N;j ++ ) {
            cnt[i] += i >> j & 1; // 每一种 2 进制 状态 1 的 个数
        }
    }
    for (int i = 0;i < 9;i ++ ) mp[1 << i] = i;

    while (cin >> str, str != "end") {
        init();
        int dot = 0;
        for (int i = 0, k = 0;i < N;i ++ ) {
            for (int j = 0;j < N;j ++ , k ++ ) {
                if (str[k] == '.') dot ++ ;
                else {
                    int t = str[k] - '1';
                    mark(i, j, t, true);
                }
            }
        }
        dfs(dot);
        cout << str << endl;
    }

}

int main() {
	int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories