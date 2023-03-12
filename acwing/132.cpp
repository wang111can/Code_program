#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1010, M = 1000010;

int teamid[M];

int main()
{
    int n, C = 1;
    while (cin >> n, n)
    {
        queue<int> team;
        queue<int> person[N];
        printf("Scenario #%d\n", C ++ );
        for (int i = 0; i < n; i ++ )
        {
            int cnt;
            cin >> cnt;
            while (cnt -- )
            {
                int x;
                cin >> x;
                teamid[x] = i;
            }
        }

        string command;
        while (cin >> command, command != "STOP")
        {
            if (command == "ENQUEUE")
            {
                int x;
                cin >> x;
                int tid = teamid[x];
                if (person[tid].empty()) team.push(tid);
                person[tid].push(x);
            }
            else
            {
                int tid = team.front();
                auto &q = person[tid];
                cout << q.front() << endl;
                q.pop();
                if (q.empty()) team.pop();
            }
        }
        cout << endl;
    }

    return 0;
}   