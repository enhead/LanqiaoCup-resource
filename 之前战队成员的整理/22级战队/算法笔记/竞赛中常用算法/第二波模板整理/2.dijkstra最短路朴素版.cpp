/*
dijkstra最短路朴素版：
（通过模拟整出来的）
使用场景：点数^2<边数
步骤：
    枚举每条边
     {
      1.找到距离起点最近且没走过的点（dist数组中找）
      2.更新与该点所有相联的边
      }
*/
//1.普通（完全够用了）

#include<bits/stdc++.h>
using namespace std;
int dist[510];
int n,m;
int link[510][510];//存储每条边
bool used[510];//是否被用过
void dijkstra(){
    for(int i=0;i<n;i++){
        //循环点的个数
        int t=-1;//找到距离起点最近且没走过的点
        for(int j=1;j<=n;j++){
            if(!used[j]&&(t==-1||dist[t]>dist[j])){
                t=j;
            }
        }
        used[t]=1;
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],dist[t]+link[t][j]);
            // cout<<t<<" "<<j<<" "<<dist[j]<<endl;
        }
    }
}
int main(){
    //初始化(最短路最大最大都不会超过500*10000)
    int maxd=5e6;
    memset(dist,10,sizeof(dist));
    dist[1]=0;
    memset(link,10,sizeof(link));

    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        link[x][y]=min(link[x][y],z);//重边
    }
    dijkstra();
    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
    if(dist[n]>maxd){
        cout<<"-1";
    }else{
        cout<<dist[n];
    }

    return 0;
}


/*(没必要看这个)
//2.采用邻接表（优化不到哪去，了解就行）
#include<bits/stdc++.h>
using namespace std;
int dist[510];
int n,m;
bool used[510];//是否被用过

//邻接表
int cnt=0;
int nx[510],fx[100010];//x最新的一次出现(初始为-1)，上一次出现
int e[100010],w[100010];//边的起点终点，长度
void add(int x,int y,int z){
    //当前x连接的上一个
    //cnt是用来记录边的编号，处理nx[x]
    fx[cnt]=nx[x],e[cnt]=y,w[cnt]=z,nx[x]=cnt++;
}

void dijkstra(){
    for(int j=0;j<n;j++){
        int t=-1;
        for(int i=1;i<=n;i++){
            if(!used[i]&&(t==-1||dist[t]>dist[i])){
                t=i;
            }
        }
        used[t]=1;
        for(int i=nx[t];i!=-1;i=fx[i]){
            int y=e[i],z=w[i];
            dist[y]=min(dist[y],dist[t]+z);
        }



    }
}
int main(){
    //初始化(最短路最大最大都不会超过500*10000)
    int maxd=5e6;
    memset(dist,10,sizeof(dist));
    dist[1]=0;
    memset(nx,-1,sizeof(nx));

    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    dijkstra();
    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
    if(dist[n]>maxd){
        cout<<"-1";
    }else{
        cout<<dist[n];
    }

    return 0;
}
*/