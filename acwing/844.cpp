#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int,int> PTT;
const int N=110;

int a[N][N],b[N][N];//b用来标记走过的路
queue<PTT> t;//宽搜节点1 2 3 4 从小到大依次搜索起点附件的点
int n,m;

int bfs()
{
    int dx[]={0,-1,0,1},dy[]={1,0,-1,0};
    
    b[0][0]=0;
    t.push({0,0});
    
    while(!t.empty())
    {   
        auto tmp=t.front();
        t.pop();
        for(int i=0;i<4;i++)
        {
            int x=tmp.first+dx[i],y=tmp.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]==0&&b[x][y]==-1)
            {
                b[x][y]=b[tmp.first][tmp.second]+1;//当前节点比上个节点的位置多一
                t.push({x,y});
            }
        }
        
    }
    
    return b[n-1][m-1];//返回当前终点与起点的距离
    
    
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++) b[i][j]=-1;//-1为可以走
   cout<<bfs()<<endl;
   
   return 0;
}
