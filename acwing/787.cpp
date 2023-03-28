#include <iostream>

using namespace std;

const int n = 100001;
int a[n], tmp[n];
int sz;

void mer_sort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    mer_sort(a, l, mid);
    mer_sort(a, mid + 1, r);

    int k = 0, x = l, y = mid + 1;
    while (x <= mid && y <= r)
        if (a[x] <= a[y])
            tmp[k++] = a[x++];
        else
            tmp[k++] = a[y++];

    while (x <= mid)
        tmp[k++] = a[x++];

    while (y <= r)
        tmp[k++] = a[y++];

    for (int i = l, j = 0; i <= r; i++, j++)
        a[i] = tmp[j];
}

int main()
{

    cin >> sz;
    for (int i = 0; i < sz; i++)
        cin >> a[i];

    mer_sort(a, 0, sz - 1);
    for (int i = 0; i < sz; i++)
    {
        cout << a[i] << " ";
    }
}