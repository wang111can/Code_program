#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string dfs(string &seq, int &u)
{
    u ++ ;
    vector<string> seqs;
    while (seq[u] == '0') seqs.push_back(dfs(seq, u));
    u ++ ;
    sort(seqs.begin(), seqs.end());
    string res = "0";
    for (auto &s : seqs) res += s;
    res += '1';
    return res;
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        string a, b;
        cin >> a >> b;
        a = '0' + a + '1';
        b = '0' + b + '1';
        int ua = 0, ub = 0;
        auto ra = dfs(a, ua), rb = dfs(b, ub);
        if (ra == rb) puts("same");
        else puts("different");
    }
    return 0;
}