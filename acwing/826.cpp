#include <iostream>

using namespace std;

const int sz = 100000 + 10;

int val[sz], Next[sz];
int head, idx; // head存放头节点的下标
int m, x, y;

void Init()
{
    head = -1;
    idx = 0;
}

void add_head(int x)
{
    val[idx] = x;
    Next[idx] = head;
    head = idx++;
}

void add_idx(int y, int x)
{

    val[idx] = x;
    Next[idx] = Next[y];
    Next[y] = idx++;
}

void dele(int y)
{
    Next[y] = Next[Next[y]];
}

int main()
{
    cin >> m;
    int n = 0;
    Init();
    while (m--)
    {
        char ch;
        cin >> ch;
        if (ch == 'H')
        {
            cin >> x;
            add_head(x);
        }
        else if (ch == 'D')
        {
            cin >> y;
            if (y == 0)
                head = Next[head];
            dele(y - 1);
        }
        else if (ch == 'I')
        {
            cin >> y >> x;
            add_idx(y - 1, x);
        }
    }
    for (int i = head; i != -1; i = Next[i])
    {
        cout << val[i] << ' ';
    }
}
