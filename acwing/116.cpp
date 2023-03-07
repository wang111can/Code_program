#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
const int N = 4, INF = 100;

int change[N][N];

int get(int x, int y)
{
    return x * N + y;
}

int main()
{
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j < N; j ++ )
        {
            for (int k = 0; k < N; k ++ ) change[i][j] += (1 << get(i, k)) + (1 << get(k, j));
            change[i][j] -= 1 << get(i, j);
        }

    int state = 0;
    for (int i = 0; i < N; i ++ )
    {
        string line;
        cin >> line;
        for (int j = 0; j < N; j ++ )
            if (line[j] == '+')
                state += 1 << get(i, j);
    }

    vector<PII> path;
    for (int i = 0; i < 1 << 16; i ++ )
    {
        int now = state;
        vector<PII> temp;
        for (int j = 0; j < 16; j ++ )
            if (i >> j & 1)
            {
                int x = j / 4, y = j % 4;
                now ^= change[x][y];
                temp.push_back({x, y});
            }
        if (!now && (path.empty() || path.size() > temp.size())) path = temp;
    }

    cout << path.size() << endl;
    for (auto &p : path)
        cout << p.first + 1 << ' ' << p.second + 1 << endl;

    return 0;
}