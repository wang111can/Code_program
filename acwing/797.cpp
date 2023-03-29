#include<iostream>

using namespace std;

const int sz=100010;

int a[sz],b[sz];

int n,m,l,r,c;

void insert(int l,int r,int c)
{
    b[l]+=c;
    b[r+1]-=c;
    
}


int main()
{
    scanf("%d %d",&n,&m);
    
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)insert(i,i,a[i]);
    
    while(m--)
    {
        scanf("%d %d %d",&l,&r,&c);
        insert(l,r,c);
    }
    for(int i=1;i<=n;i++)
    printf("%d ",b[i]+=b[i-1]);
  
}