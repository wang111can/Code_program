#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10;

int g[N];
vector<int> ans, path;
string ops[9] = {
    "ABDE", "ABC", "BCEF", "ADG", "BDEFH",
    "CFI,", "DEGH", "GHI", "EFHI"
};

bool check()
{
    for (int i = 0; i < 9; i ++ )
        if (g[i] != 12)
            return false;
    return true;
}

void rotate(int u)
{
    for (auto c: ops[u])
    {
        int k = c - 'A';
        g[k] += 3;
        if (g[k] == 15) g[k] = 3;
    }
}

void dfs(int u)
{
    if (u == 9)
    {
        if (check())
        {
            if (ans.empty() || ans.size() > path.size() ||
                ans.size() == path.size() && ans > path)
                ans = path;
        }
        return;
    }

    for (int i = 0; i < 4; i ++ )
    {
        dfs(u + 1);
        path.push_back(u + 1);
        rotate(u);
    }

    for (int i = 0; i < 4; i ++ ) path.pop_back();
}

int main()
{
    for (int i = 0; i < 9; i ++ ) cin >> g[i];
    dfs(0);

    for (auto x: ans) cout << x << ' ';
    cout << endl;

    return 0;
}
