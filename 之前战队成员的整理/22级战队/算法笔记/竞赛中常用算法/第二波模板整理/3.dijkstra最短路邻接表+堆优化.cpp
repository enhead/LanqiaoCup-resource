//对朴素的优化(堆优化+邻接表)
//使用场景：点^2<边
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
//存边，和终点
const int maxn=1.5e5+10;
int n,m;
int dist[maxn];
bool used[maxn];

//邻接表
/*
(邻接表不用担心重边)
一个点会连接 cnt 条边，
每条边又有指向上一条边，
这样就能遍历以x为起点的所有边
*/
int cnt=0;
int nx[maxn];//初始为-1
int fx[maxn],e[maxn],w[maxn];
void add(int x,int y,int z){
    fx[cnt]=nx[x],e[cnt]=y,w[cnt]=z,nx[x]=cnt++;
}

void dijkstra(){
    priority_queue<pii,vector<pii>,greater<pii> > q;
    //调优先级，小的优先
    q.push({0,1});
    while(!q.empty()){
        //1.找最短边
        int t=q.top().second;
        q.pop();
        if(used[t]){
            continue;
        }
        used[t]=1;


        //2.更新相邻点
        for(int i=nx[t];i!=-1;i=fx[i]){
            int y=e[i],z=w[i];
            dist[y]=min(dist[y],dist[t]+z);
            q.push({dist[y],y});
            // cout<<"y="<<y<<"  "<<dist[y]<<endl;
        }
    }
}

int main(){
    //初始化
    memset(dist,100,sizeof(dist));
    dist[1]=0;
    memset(nx,-1,sizeof(nx));
    //最短路最大值1.5e5*1e4
    int maxd=1.5e9;

    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }

    dijkstra();
    if(dist[n]>maxd){
        cout<<"-1";
    }else{
        cout<<dist[n];
    }


    return 0;
}