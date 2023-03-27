#include <bits/stdc++.h>

using namespace std;

int n;
struct Node{
    int sum, l, r;
    bool operator <(Node & x) {
        if (sum == x.sum) {
            if (x.l == l) {
                return r < x.r;
            }
            return l < x.l;
        }
        return sum < x.sum;
    }
    
}plan[5000010];

int main() {
    
    cin >> n;
    int cnt = 0;
    for (int i = 0;i * i <= n;i ++ ) {
        for (int j = i;j * j + i * i <= n;j ++ ) 
            plan[cnt ++ ] = {i * i + j * j, i, j};

    }
    sort(plan, plan + cnt);
    
    for (int i = 0;i * i <= n;i ++ ) {
        for (int j = i;j * j + i * i <= n;j ++ ) {  
            
            int t = n - i * i - j * j;
            int l = 0, r = cnt - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (plan[mid].sum >= t) r = mid;
                else l = mid + 1;
            }
            if (plan[r].sum == t) {
                vector<int> ans{i, j, plan[r].r, plan[r].l};
                sort(ans.begin(), ans.end());
                for (auto x : ans) {
                    cout << x << ' ';
                }
                
                return 0;
            }
        }
    }

    
    return 0;
}