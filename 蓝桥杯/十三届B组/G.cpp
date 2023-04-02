#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 10000010, mod = 1000000007;

/*
�� i �� �� ״̬ �� �� i + 1 �� �� ״̬ �� �ɴ���
ÿ�� ʹ�� 01 00 10 11 ����ʾ ���� �� ������ 0 ��ʾ û�� �� 1 ��ʾ ʹ�� 
f[i][j] ��ʾ �ں� �� �� i - 1 �� ��ǰ �� �� i �� ��ʱ �� i �� �� ״̬ Ϊ j �� ������ 

*/

int n;
int f[N][5];
int state[][5] = {
	{1, 1, 1, 1}, // ��һ�� ״̬�� �ɴ��� ...  �� i �� ��  00 ״̬ ���� ʹ �� i + 1 �� ���� ���� ״̬
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
