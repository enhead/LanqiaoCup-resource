#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k;
struct edge{
    int x,y,z;
}edge[10010];
int dist[510];//最短边
int backup[510];//备份免得重复走
void bellman_ford(){
    memset(dist,100,sizeof(dist));
    dist[1]=0;
    for(int i=0;i<k;i++){
        memcpy(backup,dist,sizeof(backup));//只用上一步做得来更新，免得串联，就是更新后又按更新的走，这样可能走了不止k步
        for(int j=0;j<m;j++){
            int x=edge[j].x,y=edge[j].y,z=edge[j].z;
            dist[y]=min(dist[y],backup[x]+z);//这里需要注意一下，是跟dist[y]比
            // cout<<"x="<<x<<"   y="<<y<<"  dist[y]"<<dist[y]<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edge[i]={x,y,z};
    }
    bellman_ford();
    // cout<<dist[n]<<endl;
    if(dist[n]>1e8){
        cout<<"impossible";
    }else{
        cout<<dist[n];
    }
    return 0;
}