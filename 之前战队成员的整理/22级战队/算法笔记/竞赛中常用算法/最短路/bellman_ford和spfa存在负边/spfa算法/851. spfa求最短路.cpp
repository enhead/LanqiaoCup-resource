#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
const int maxn=1e5+10;
//邻接表：
int nx[maxn],fx[maxn],e[maxn],l[maxn],idx=0;
//nx（now——x）记录起点为x的最后一次出现的编号；fx是链接上一次出现的编号(初始化为-1，代表还未出现)；
//e（end）就是y啦；l表示边长；idx就是编号
void add(int x,int y,int z){//录入
    fx[idx]=nx[x];e[idx]=y;l[idx]=z;nx[x]=idx++;
}//注意fx和nx是关键


int dist[maxn];//最短路，初始较大化,dist[1]=0
int had[maxn]={0};//优化一下，队伍内没必要重复加入

void spfa(){
     //初始化
    memset(dist,100,sizeof(dist));
    dist[1]=0;

    queue<int> q;
    q.push(1);
    had[1]=1;//已经在队伍内了
    while(!q.empty()){//没路了就自动停了
        int t=q.front();
        q.pop();
        had[t]=0;//取出后就没有了
        for(int i=nx[t];i!=-1;i=fx[i]){
            int y=e[i],tl=dist[t]+l[i];
            // cout<<y<<" "<<"tl="<<tl;
            if(dist[y]>tl){//更小就更新
                dist[y]=tl;
                // cout<<dist[y]<<endl;
                if(!had[y]){
                    q.push(y);
                    had[y]=1;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    memset(nx,-1,sizeof(nx));
    for(int i=0;i<m;i++){//邻接表
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    // for(int i=nx[1];i!=-1;i=fx[i]){
    //     cout<<i<<" ";
    // }
    spfa();
    // cout<<dist[n];
    if(dist[n]>1e9){
        cout<<"impossible";
    }else{
        cout<<dist[n];
    }
    return 0;
}