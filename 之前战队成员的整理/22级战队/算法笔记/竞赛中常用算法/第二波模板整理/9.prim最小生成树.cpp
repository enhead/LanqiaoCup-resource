//生成树：有n个点用n-1条边相连

/*
Prim算法（又称加点法）
使用场景：（这个算法的复杂度相对高），看到点在百左右才能用

理解：（有点像dijkstra算法）（这个没必要优化了，有kruskal算法）
    从第一个点开始，（集合的一个元素）
    {
    找到与集合相连的最短边，
    (当没有最短边时，就可以结束了)
    将这个点加入集合，（用一个数组来记录是否在集合中）
    并更新这个点相连的边（也就是与集合相连）
    }

注意：1.这里是无向边，（特殊的有向边）
      2.重边
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int n,m;
int link[maxn][maxn];//用来存无向边

int dist[maxn];//与集合相连的边，初始较大化
int had[maxn];//是否在这个集合里面

//边最大也不会超过1e4
int maxd=1e4,ans=0;
bool prim(){
    for(int j=0;j<n;j++){
        //循环n次，因为有n个点

        //找最短边
        int t=-1;
        for(int i=1;i<=n;i++){
            if(!had[i]&&(t==-1||dist[t]>dist[i])){
                t=i;
            }
        }
        // cout<<t<<" "<<dist[t]<<endl;
        if(dist[t]>maxd){
            return 0;
        }
        ans+=dist[t];
        had[t]=1;
        for(int i=1;i<=n;i++){
            dist[i]=min(dist[i],link[t][i]);
            // cout<<i<<" "<<dist[i]<<endl;
        }
    }
    return 1;
}
int main(){
    //初始化：
    memset(dist,100,sizeof(dist));
    dist[1]=0;
    memset(link,100,sizeof(link));


    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        link[u][v]=link[v][u]=min(link[u][v],w);
        //注意:重边和无向边
    }
    if(prim()){
        cout<<ans;
    }else{
        cout<<"impossible";
    }

    return 0;
}