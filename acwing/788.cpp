#include <iostream>

using namespace std;

const int n = 100001;
int a[n], tmp[n];
int sz;

long long mer_sort(int l, int r)
{
    if (l >= r)
        return 0;
    int mid = l + r >> 1;

    long long res = mer_sort(l, mid) + mer_sort(mid + 1, r);
    int k = 0, x = l, y = mid + 1;

    while (x <= mid && y <= r)
        if (a[x] <= a[y])
            tmp[k++] = a[x++];
        else
        {

            tmp[k++] = a[y++];
            res += mid - x + 1;
        }
    while (x <= mid)
        tmp[k++] = a[x++];
    while (y <= r)
        tmp[k++] = a[y++];
    for (int i = l, j = 0; i <= r; i++, j++)
        a[i] = tmp[j];

    return res;
}

int main()
{
    cin >> sz;
    for (int i = 0; i < sz; i++)
        scanf("%d", &a[i]);
    cout << mer_sort(0, sz - 1);
}