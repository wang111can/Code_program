#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10000;

int n;
int ans[N], top = N;
int path[N];
string state, target;

void dfs(int p, int k)
{
    if (k >= top - 1) return;
    if (state == target)
    {
        memcpy(ans, path, k * 4);
        top = k;
        return;
    }
    if (p - 2 >= 0 && state[p - 2] == 'W' && state[p - 1] == 'B')
    {
        path[k] = p - 2;
        swap(state[p - 2], state[p]);
        dfs(p - 2, k + 1);
        swap(state[p - 2], state[p]);
    }
    if (p - 1 >= 0 && state[p - 1] == 'W')
    {
        path[k] = p - 1;
        swap(state[p - 1], state[p]);
        dfs(p - 1, k + 1);
        swap(state[p - 1], state[p]);
    }
    if (p + 1 <= n * 2 && state[p + 1] == 'B')
    {
        path[k] = p + 1;
        swap(state[p + 1], state[p]);
        dfs(p + 1, k + 1);
        swap(state[p + 1], state[p]);
    }
    if (p + 2 <= n * 2 && state[p + 2] == 'B' && state[p + 1] == 'W')
    {
        path[k] = p + 2;
        swap(state[p + 2], state[p]);
        dfs(p + 2, k + 1);
        swap(state[p + 2], state[p]);
    }
}

int main()
{
    cin >> n;
    state = string(n, 'W') + ' ' + string(n, 'B');
    target = state;
    reverse(target.begin(), target.end());
    dfs(n, 0);

    for (int i = 0; i < top; i ++ )
    {
        cout << ans[i] + 1;
        if ((i + 1) % 20 == 0) cout << endl;
        else cout << ' ';
    }
    return 0;
}