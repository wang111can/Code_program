#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int p[N], n;

int find(int x) {
	if (p[x] != x) return p[x] = find(p[x]);
	return p[x];
}

int main() {
	cin >> n;
	for (int i = 1;i < N;i ++ )  p[i] = i;
	
	for (int i = 1;i <= n;i ++ ) {
		int x; cin >> x;
		x = find(x); // �ҵ� �ұ� ��һ�� û���� �� �� 
		cout << x << endl;
		p[x] = x + 1;
	}
	
}
