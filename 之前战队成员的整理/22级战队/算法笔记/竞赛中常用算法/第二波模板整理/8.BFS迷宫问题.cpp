//bfs
/*
一步一步的往外搜，没搜完当前步是不会到下一步的
模板：
queue<类型> q;
q.push(初始位置);
while(!q.empty()){
    <类型> t=q.front();
    q.pop();//该元素弹出
    for(所有可拓展的情况){
        if(不合法){
            continue;
        }
        q.push(合法)；//入队
    }
}

一般还需配合ans[x][y]来记录首次到达的状态
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int > pii;//用这个来存坐标
int ans[105][105];//初始化为-1，表示没走过
bool a[105][105];//原数组
int n,m;

//可移动的方向：
int mx[4]={0,1,0,-1};
int my[4]={1,0,-1,0};

int main(){

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    //初始化:

    memset(ans,-1,sizeof(ans));
    ans[1][1]=0;
    queue<pii> q;
    q.push({1,1});
    while(!q.empty()){
        auto t=q.front();
        int tx=t.first,ty=t.second;
        // cout<<"tx="<<tx<<" "<<"ty="<<ty<<endl;
        q.pop();
        for(int i=0;i<4;i++){
            int x=mx[i]+tx,y=my[i]+ty;
            if(x<=0||x>n||y<=0||y>m||ans[x][y]!=-1||a[x][y]){
                continue;
            }
            ans[x][y]=ans[tx][ty]+1;
            q.push({x,y});
            // cout<<x<<"  "<<y<<" "<<ans[x][y]<<";";
        }
        // cout<<endl;
    }

    cout<<ans[n][m];
    return  0;
}