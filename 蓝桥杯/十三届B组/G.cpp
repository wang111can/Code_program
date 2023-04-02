#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 10000010, mod = 1000000007;

/*
第 i 行 的 状态 与 第 i + 1 行 的 状态 的 可达性
每列 使用 01 00 10 11 来表示 方格 的 可用性 0 表示 没有 用 1 表示 使用 
f[i][j] 表示 摆好 了 第 i - 1 列 当前 摆 第 i 列 此时 第 i 列 的 状态 为 j 的 方案数 

*/

int n;
int f[N][5];
int state[][5] = {
	{1, 1, 1, 1}, // 第一种 状态的 可达性 ...  第 i 列 的  00 状态 可以 使 第 i + 1 列 产生 所有 状态
	{0, 0, 1, 1}, // 10
	{0, 1, 0, 1}, // 01
	{1, 0, 0, 0} // 11 
};


int main() {
	cin >> n;
	f[1][0] = 1;
	for (int i = 1;i <= n;i ++ ) {	
		for (int j = 0;j < 4;j ++ ) {
			for (int k = 0;k < 4;k ++ ) {
				f[i + 1][k] = (f[i + 1][k] + f[i][j] * state[j][k]) % mod;
			}
		}
	}
	cout << f[n + 1][0] << endl;
	return 0;
}
