#include <bits/stdc++.h>

#define x first
#define y second 

using namespace std;

int main() {
	map<char, int> mp;
	string str; cin >> str;
	for (auto x : str) {
		mp[x] ++ ;
	}
	vector<pair<char, int>> ans;
	for (auto p : mp) {
		ans.push_back({p.x, p.y});
	}
	sort(ans.begin(), ans.end(), [&](pair<char, int> a, pair<char, int> b){
		if (a.y == b.y) return a.x < b.x;
		return a.y > b.y;
	});
	for (int i = 0;i < ans.size();i ++ ) {
		if (ans[0].y == ans[i].y) {
			cout << ans[i].x;
		}
		else break;
	}
}
