/*
f[i][j] ��ʾ �� i �� ���� ʹ�� �� j �������
��Ϊ 2 ������

��Сֵ == 0 
f[i][j] += f[i - 1][j] �� i �� Ӱ���� �� ����� Ϊ 0 
��Сֵ > 0
f[i][j] ���� �� ÿ���� �� ����� -1 ���� �� �� ������ͬ 
f[i][j] += f[i][j - i]

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	while (t -- ) {
		int n, m; cin >> m >> n;
		vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
		f[0][0] = 1;
		for (int i = 1;i <= n;i ++ ) {
			for (int j = 0;j <= m;j ++ ) {
				f[i][j] += f[i - 1][j];
				if (j - i >= 0) {
					f[i][j] += f[i][j - i];
				}
			}
		}
		cout << f[n][m] << endl;
	}
	
}
