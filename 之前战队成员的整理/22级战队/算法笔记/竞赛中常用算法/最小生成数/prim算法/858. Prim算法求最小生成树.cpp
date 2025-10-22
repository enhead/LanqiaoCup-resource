//唉，这个算法说实话，我看视频没看懂，最后是模拟这个代码搞懂的
//这个算法与dijkstra算法，很相似，但没必要学堆优化版的，后面有个算法可以替代
/*最小生成树就是用n-1个边连接n个点
思路：（贪心，关键是找与集合相连的最短边）
1.创建一个集合用来存点（最小生成树内的点）
2.dist用来存与这个集合相连的边（注意一下在集合内的点之间就不算相连了，had数组标记，同时也是在存点），
(dist[x]表示x点到这个集合的最短距离)
3.重复下述的过程(直到所有的点都在集合内  或是  有个点与集合断开时)：
    a.找到这些边的最短边（需循环所有边），其中相连的点t，记得标记一下——加入集合
    b.用这个点t去更新dist
*/


#pragma GCC optimize(2)
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
int link[510][510];//存每条边，较大化
int dist[510];//把维护与集合相连的边，较大化
bool had[510];//标记点，顺带进集合
int ans=0;
bool prim(){
    //初始化：
    memset(dist,100,sizeof(dist));
    dist[1]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!had[j]&&(t==-1||dist[t]>dist[j])){//找最短的边
                t=j;
            }
        }
        if(dist[t]>1e4){
            return 1;
        }
        ans+=dist[t];
        had[t]=1;//标记点
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],link[t][j]);
        }

    }
    return 0;

}
int main() {
// 	freopen("shuru.txt","r",stdin);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>m;
	memset(link,100,sizeof(link));
	for(int i=0;i<m;i++){
	    int u,v,w;
	    cin>>u>>v>>w;
	    link[u][v]=link[v][u]=min(link[u][v],w);//有重边，同时无向边是特殊的有向边
	}
    if(prim()){
        cout<<"impossible";
    }else{
        cout<<ans;
    }


	return 0;
}