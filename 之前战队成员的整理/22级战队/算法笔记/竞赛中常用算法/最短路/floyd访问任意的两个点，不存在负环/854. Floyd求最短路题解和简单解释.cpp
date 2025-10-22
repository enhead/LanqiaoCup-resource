//这个算法涉及简单的动态规划，我现在暂时没学，只能简单且不严谨的解释，只帮助理解
//这个代码看起来虽然很像暴力枚举，但感觉并不是
//唉，虽然代码非常简单，但说实话我感觉并不好理解(可能是我比较笨吧)
//像这种查询的一般会把所有情况求出或间接求出。
/*1.首先嘚搞明白一点，根据对前面的算法学习:
        你会发现若这条最短路（1->5->9->3->30）经过了多个点，那其中任意两点都是最短路
        (这里应该算是贪心，局部最优解，推整体)
*/
/*2.然后将floyd算法简单模拟会发现：
        若任意一条经过多个点的最短路(a->b->c->d->e->f)；
        首先，通过观察这个算法一定能够确定走了“相邻的”3个点的最短路（划重点是相邻的）；
        因为这个中间的点一定是从小到大确定的，所以先确定的一定是中间点小的；（注意是中间）
        （前（大一点）->中(小的)->后（大一点） ）
        这个最短边操作完后，其实就能忽略掉中间点；
        不断去循环上述的过程，最终一定能当做只剩两个点。
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define f(i,n) for(int i=1;i<=n;i++)//宏定义，略写，因为涉及到较多的循环
int n,m;
int dist[210][210];//因为要去min，初始较大化，同时有个隐含条件就是x==y时，距离为0
void floyd(){
    f(i,n){//i就是中间点
        f(x,n){
            f(y,n){
                dist[x][y]=min(dist[x][y],dist[x][i]+dist[i][y]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int k;
    cin>>n>>m>>k;
    //初始
    memset(dist,10,sizeof(dist));
    f(i,n){
        dist[i][i]=0;
    }
    f(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        dist[x][y]=min(dist[x][y],z);//有重边
    }
    floyd();
    while(k--){
        int x,y;
        cin>>x>>y;
        if(dist[x][y]>4e6){
            cout<<"impossible\n";
        }else{
            cout<<dist[x][y]<<"\n";
        }
    }

    return 0;
}