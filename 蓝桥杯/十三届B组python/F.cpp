#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


using namespace std;
typedef long long LL;
const int N = 1e6 + 8;
char s[N];
int l[N],r[N];
vector<int> pos;//�洢ɾ���Ľڵ�
bool st[N];//���� true��ʾ ɾ����

//ɾ��x�ڵ�
void remove(int x)
{
    r[l[x]] = r[x];
    l[r[x]] = l[x];
}

//checkһ��xλ���Ƿ��Ǳ�Ե�ַ�
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

    //��һ���߽�
    s[0] = '@';
    s[n + 1] = '@';
    //����˫������
    for(int i = 1;i <= n;i ++) 
        l[i] = i - 1,r[i] = i + 1;

    //�����еı�Ե�ַ������   
    for(int i = 1;i <= n;i ++) check(i);
    int i = 0;

    while(i < pos.size())
    {
        vector<int> p;//�洢��һ�ֵĿ��ܵı�Ե�ַ�
        for(;i < pos.size();i ++)
            {
                int j = pos[i];
                if(st[j]) continue;

                remove(j);
                st[j] = true; // ���� ���� �� �� ��Ե �ַ� �� λ�� ֻ �� �� ���� ��� ���� �ұ�
                p.push_back(l[j]);
                p.push_back(r[j]);
            }   

        for(int j = 0;j < p.size();j ++) 
             if(!st[p[j]])//�����true��ʾ��ɾ����
               check(p[j]);
    }        

    //���
    bool ok = true;
    for(int i = 1;i <= n;i ++)
        if(!st[i]){
            cout << s[i];
            ok = false;
        }
    if(ok) puts("EMPTY");    
    return 0;
}
