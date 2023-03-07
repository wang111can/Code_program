#include<iostream>

using namespace std;

const int N=10;
int a[N],b[N];
int n;

void dfs(int x)
{
    if(x==n){
        for(int i=0;i<n;i++)cout<<a[i]<<' ';
        cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]==0)
        {
            b[i]=1;
            a[x]=i;
            dfs(x+1);
            b[i]=0;
        }
        
    }
}

int main()
{
    cin>>n;
    dfs(0);
    
    return 0;
}