#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


using namespace std;
typedef long long LL;
const int N = 1e6 + 8;
char s[N];
int l[N],r[N];
vector<int> pos;//存储删除的节点
bool st[N];//判重 true表示 删除了

//删除x节点
void remove(int x)
{
    r[l[x]] = r[x];
    l[r[x]] = l[x];
}

//check一下x位置是否是边缘字符
void check(int x)
{
    if(s[l[x]]  == '@' || s[r[x]] == '@') return ;

    if(s[l[x]] == s[x] && s[x] != s[r[x]]) pos.push_back(x),pos.push_back(r[x]);
    if(s[l[x]] != s[x] && s[x] == s[r[x]]) pos.push_back(l[x]),pos.push_back(x);
}

int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);

    //搞一个边界
    s[0] = '@';
    s[n + 1] = '@';
    //创建双向链表
    for(int i = 1;i <= n;i ++) 
        l[i] = i - 1,r[i] = i + 1;

    //把所有的边缘字符搞出来   
    for(int i = 1;i <= n;i ++) check(i);
    int i = 0;

    while(i < pos.size())
    {
        vector<int> p;//存储下一轮的可能的边缘字符
        for(;i < pos.size();i ++)
            {
                int j = pos[i];
                if(st[j]) continue;

                remove(j);
                st[j] = true; // 可能 产生 新 的 边缘 字符 的 位置 只 有 在 他的 左边 或者 右边
                p.push_back(l[j]);
                p.push_back(r[j]);
            }   

        for(int j = 0;j < p.size();j ++) 
             if(!st[p[j]])//如果是true表示被删除了
               check(p[j]);
    }        

    //输出
    bool ok = true;
    for(int i = 1;i <= n;i ++)
        if(!st[i]){
            cout << s[i];
            ok = false;
        }
    if(ok) puts("EMPTY");    
    return 0;
}
