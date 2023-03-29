/*
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;


const int N = 110;

typedef pair<int, int> PII;

char f[N][N][N];
  int dx[6] = {1, 0, -1, 0, 0, 0};
  int dy[6] = {0, 1, 0, -1, 0, 0};
  int dz[6] = {0, 0, 0, 0, -1, 1};
bool st[N][N][N];
int ans[N][N][N];
struct dot{
    int x,y,z;
};

int bfs(int n,int c,int r)
{
       int x1,x2,y1,y2,z1,z2;
          for(int i=1;i<=n;i++){
            for(int j=1;j<=c;j++){
                for(int k=1;k<=r;k++){
                    cin>>f[i][j][k];
                    if(f[i][j][k]=='S') x1=i,y1=j,z1=k;  //
                    if(f[i][j][k]=='E') x2=i,y2=j,z2=k;  //
                }
            }
        }

       //cout << x1 << ' ' << y1 << ' ' <<  z1 << endl;
        //cout << x2 << ' ' << y2 << ' ' <<  z2 << endl;
        queue<dot> q;
        q.push({x1,y1,z1});
        st[z1][x1][y1] = true;
        int l1,l2,l3;
        while (q.size())
        {
            auto t = q.front();
            q.pop();
            
            cout << t.x << ' ' << t.y << ' ' << t.z << endl;
      
            for (int i = 0;i < 6;i ++ )
            {
                int a = t.x + dx[i], b = t.y + dy[i], z = t.z + dz[i];
                //
                if(a <= c && b <= r && z <= n&& a >= 1&& b>=1 && z>= 1 &&!st[a][b][z] && f[a][b][z]!='#')
                {
                   // cout<< xx << ' ' << yy << ' ' << u << "------" << a << ' ' << b << ' ' << z << endl;
                    //cout << z << ' ';
                   
                    ans[z][a][b] = ans[t.z][t.x][t.y] + 1;
                    if (f[z][a][b] == 'E') {
                        return ans[z][a][b];
                    }
                 
                    st[z][a][b] = true;
                    q.push({a,b,z});
                }
                //cout << endl;
            }
         
        }
}

int main()
{
    int n,c,r;
    
    while (cin >> n >> c >> r,n && c && r)
    {
     
        memset(ans,0,sizeof ans);
        memset(st,0,sizeof st);
        
        

        
      
        int aws = bfs(n,c,r);
        if(aws)
        printf("Escaped in %d minute(s)\n",aws);
        else 
        {
            cout << "Trapped!" << endl;
        }
    }
}
*/
#include <bits/stdc++.h>
using namespace std;

const int N=110;

int l,r,c;  //迷宫参数
int px,py,pz,ex,ey,ez;  //pi为S的位置，ei为E的位置

char mp[N][N][N];  //记录迷宫
int ans[N][N][N];  //存储答案
bool vis[N][N][N];  //记录该点是否走过的状态

struct point{  //点的坐标
    int x,y,z;
};

queue<point> st;  //搜索队列

int dx[]={1,-1,0,0,0,0},dy[]={0,0,1,-1,0,0},dz[]={0,0,0,0,1,-1};  //偏移量数组

int bfs(){
    while(!st.empty()){  //当队头不为空时，扩展搜索队头
        auto p=st.front();
        for(int i=0;i<6;i++){
            int m_x=p.x+dx[i],m_y=p.y+dy[i],m_z=p.z+dz[i];  //偏移之后的点的坐标
            if(m_x<=l&&m_y<=r&&m_z<=c&&m_x>=1&&m_y>=1&&m_z>=1&&!vis[m_x][m_y][m_z]&&mp[m_x][m_y][m_z]!='#'){  //判断条件
                vis[m_x][m_y][m_z]=1;  //更新该点走过的状态
                ans[m_x][m_y][m_z]=ans[p.x][p.y][p.z]+1;  //更新偏移后的点距离S的步骤
                if(mp[m_x][m_y][m_z]=='E') return  ans[m_x][m_y][m_z];  //搜到E直接返回答案
                st.push({m_x,m_y,m_z});  //将该点入队，继续扩展搜索
            }
        }
        st.pop();  //队头扩展搜索完毕后出队
    }
    return 0;  //所有的点扩展搜索完后若还未返回搜到E，说明无解
}

int main(){
    while(cin>>l>>r>>c&&l&&r&&c){  //多实例读入
        //还原数据
        memset(ans,0,sizeof(ans)); 
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        while(st.size()){
            st.pop();
        }
        //读入迷宫
        for(int i=1;i<=l;i++){
            for(int j=1;j<=r;j++){
                for(int k=1;k<=c;k++){
                    cin>>mp[i][j][k];
                    if(mp[i][j][k]=='S') px=i,py=j,pz=k;  //
                    if(mp[i][j][k]=='E') ex=i,ey=j,ez=k;  //
                }
            }
        }

        vis[px][py][pz]=1;  //标记S已经走过

        st.push({px,py,pz}); //S点入队

        int cnt=bfs();  //调用搜索，将从S点开始搜索

        if(cnt!=0) printf("Escaped in %d minute(s).\n",cnt);
        else cout<<"Trapped!"<<endl;
    }

    return 0;
}
