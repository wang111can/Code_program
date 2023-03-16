#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PLI;

const int N = 100010;

int main()
{
    int n, m;
    cin >> n >> m;

    priority_queue<PLI, vector<PLI>, greater<PLI>> heap;
    for (int i = 0; i < n; i ++ )
    {
        LL w;
        cin >> w;
        heap.push({w, 0});
    }

    while ((n - 1) % (m - 1))
    {
        heap.push({0ll, 0});
        n ++ ;
    }

    LL res = 0;
    while (heap.size() > 1)
    {
        LL sum = 0;
        int depth = 0;
        for (int i = 0; i < m; i ++ )
        {
            sum += heap.top().first;
            depth = max(depth, heap.top().second);
            heap.pop();
        }
        res += sum;
        heap.push({sum, depth + 1});
    }

    cout << res << endl << heap.top().second << endl;

    return 0;
}