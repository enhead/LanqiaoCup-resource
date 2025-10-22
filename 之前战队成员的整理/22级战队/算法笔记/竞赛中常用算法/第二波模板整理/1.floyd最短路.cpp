//动态规划（这里可以理解为dfs优化）
/*
假设：a->b->c->d.....->n
理解：
    这里任意点的两个点最后算出来都是最短路（这里不好解释）
    首先这里一定能确定相邻点的最短路（x->i->y）（i从小到大确定）
    然后算完我们就能将中间点忽略
    最后这会剩下起点和终点
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int f[210][210];
#define for(i,n) for(int i=1;i<=n;i++)
void floyd(){
    //大点也会指向小点
    for(i,n){//枚举中间点
        for(x,n){//起点
            for(y,n){//终点
                f[x][y]=min(f[x][y],f[x][i]+f[i][y]);
            }
        }
    }
}
int main(){
    //初始化：
        //最短路最值：正负10000*200
    int maxf=2e6;
    memset(f,10,sizeof(f));//初始较大化
    cin>>n>>m>>k;
    for(i,n){//隐含条件，x->x距离为0
        f[i][i]=0;
    }
    for(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        //唉，别忘了有重边
        f[x][y]=min(f[x][y],z);
    }

    floyd();
    while(k--){
        int x,y;
        cin>>x>>y;
        if(f[x][y]>maxf){
            cout<<"impossible\n";
        }else{
            cout<<f[x][y]<<'\n';
        }
    }
    return 0;
}