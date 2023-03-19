#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
vector<ull> prime;
vector<ull> get_hash(string &s)
{

    vector<ull> res(s.length() + 1);
    res[0] = 0;
    for (int i = 1; i <= s.length(); i++)
        res[i] = res[i - 1] * 131 + (s[i - 1] - 'a');
    return res;
}
ull substr_hash(vector<ull> &hsh, int l, int r)
{

    if (l > r)
        return 0;
    return hsh[r] - hsh[l - 1] * prime[r - l + 1];
}
int main()
{
    int len1, len2, q;
    cin >> len1 >> len2 >> q;
    string a, b;
    cin >> a >> b;
    vector<int> res(len2 + 1);
    res.resize(len2 + 1);
    prime.resize(max(len1, len2));
    prime[0] = 1;
    for (int i = 1; i < prime.size(); i++)
        prime[i] = prime[i - 1] * 131;

    vector<ull> hash1, hash2;
    hash1 = get_hash(a);
    hash2 = get_hash(b);
    for (int i = 1; i <= len1; i++)
    {
        int l = 0, m, r = len2;
        while (l < r)
        {
            m = (l + r + 1) / 2;
            if (substr_hash(hash1, i, i + m - 1) == substr_hash(hash2, 1, m))
                l = m;
            else
                r = m - 1;
        }
        res[l]++;
    }
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        cout << (x <= len2 ? res[x] : 0) << endl;
    }
    return 0;
}
