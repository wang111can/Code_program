#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

unordered_map<string,int> t;
queue<string> q;
string str;

int bfs()
{
    string end="12345678x";
    
    q.push(str);
    t[str]=0;
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
    
    while(q.size())
    {
        
        auto tmp=q.front();
        q.pop();
        int z=t[tmp];
        if(tmp==end)return t[tmp];
        int k=tmp.find('x');    
        int x=k/3,y=k%3;
        for(int i=0;i<4;i++)
        {
            int a=x+dx[i],b=y+dy[i];
            if(a>=0&&a<3&&b>=0&&b<3)
            {
                swap(tmp[a*3+b],tmp[k]);
                if(!t.count(tmp)){
                t[tmp]=z+1;
                q.push(tmp);
                }
                swap(tmp[a*3+b],tmp[k]);
            }
            
        }
        
        
    }
    return -1;
    
    
}

int main()
{
    for(int i=0;i<9;i++){
        char ch;
        cin>>ch;
        str+=ch;
    }
    
    cout<<bfs()<<endl;
    
    return 0;
    
    
}