#include <bits/stdc++.h>
using namespace std;

#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define x first
#define y second
#define fr front
#define db double
#define pb push_back
#define pi acos(-1)
#define all(x) x.begin(), x.end()
mt19937_64 mrand(random_device{}());

typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

const int N = 1000000;

char str[1000010];
ll p[1000010], x = 27;
ll sl[1000010], sr[1000010];

ll get_1(ll s[], int l, int r)
{
    return s[r] - s[l - 1] * p[r - l + 1];
}

ll get_2(ll s[], int l, int r) {
    return s[l] - s[r + 1] * p[r - l + 1];
}

void solve()
{

    string t;
    p[0] = 1;
    for (int i = 1; i <= N; i++)
        p[i] = p[i - 1] * x;
    int Case = 1;
    while (cin >> t, t != "END")
    {

        cout << "Case " << Case++ << ": ";
        string str;
        str = " " + t;
        int n = t.size();
        int ans = 0;
        sr[n + 1] = 0;
        for (int i = 1; i <= n; i ++)
        {
            sl[i] = sl[i - 1] * x + str[i] - 'a' + 1;
        }
        for (int i = n;i >= 1;i -- ) {
            sr[i] = sr[i + 1] * x + str[i] - 'a' + 1;
        }
        int l, r, mid;
        for (int i = 1; i <= n; i++)
        {

            l = 0, r = min(i - 1, n - i);
            while (l < r)
            {
                mid = l + r + 1 >> 1;
                if (get_1(sl, i - mid, i - 1) == get_2(sr, i + 1, i + mid)) 
                    l = mid;
                else
                    r = mid - 1;
            }
            ans = max(l << 1 | 1, ans);         
            l = 0, r = min(i - 1, n - i + 1); 
            while (l < r)
            {
                mid = l + r + 1 >> 1;
                if (get_1(sl, i - mid, i - 1) == get_2(sr, i, i + mid - 1)) 
                    l = mid;
                else
                    r = mid - 1;
            }
            ans = max(l << 1, ans);
        }
        cout << ans << endl;
    }
}

int main()
{
    io;
    int T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
//  --allow-unrelated-histories