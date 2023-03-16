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
typedef unsigned long long ull;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;


void solve() {

    stack<int> st; string str; cin >> str; int ans = 0;
    for (int i = 0;i < str.size();i ++ ){
        char x = str[i];
        if (st.size() && x == ']' && str[st.top()] == '[') st.pop();
        else if (st.size() && x == ')' && str[st.top()] == '(') st.pop();
        else if (st.size() && x == '}' && str[st.top()] == '{') st.pop();
        else st.push(i);
        if (st.empty()) ans = max(ans, i + 1);
        else ans = max(ans, i - st.top());
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
//  --allow-unrelated-histories