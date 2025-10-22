#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dist[510];//distance 最短路，距离起点的最短距离，需要更新,初始较大化
bool had[510]={0};//看是否已经遍历过,0表示没遍历过
int link[510][510];//记录每个连接的最小边，记录x->y的边长，link[x][y]，初始较大化

int n,m;

int dijkstra(){
    //每一个大循环其实就出一个贪心的结果
    for(int i=0;i<n;i++){
        int m=-1;//找出其中的那个点距离起点最小
        for(int j=1;j<=n;j++){
            if(!had[j]&&(m==-1||dist[m]>dist[j])){
                m=j;//更新最小且没用过的点
            }
        }
        had[m]=1;//这个已经用过了
        for(int j=1;j<=n;j++){//唉，小小注意一下，编号大点是可能到小点
            dist[j]=min(dist[j],dist[m]+link[m][j]);//更新，没有连接的自动过滤(加了个大值)
        }
    }
    if(dist[n]==168430090){//非法的答案
        return -1;
    }
    return dist[n];

}
int main() {
// 	freopen("shuru.txt","r",stdin);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    //初始化
    memset(dist,10,sizeof(dist));//并不是赋值为10//赋值为168430090
    dist[1]=0;//起点1
    memset(link,10,sizeof(link));

    cin>>n>>m;
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        link[x][y]=min(link[x][y],z);//由于存在重边
    }

    cout<<dijkstra();


	return 0;
}