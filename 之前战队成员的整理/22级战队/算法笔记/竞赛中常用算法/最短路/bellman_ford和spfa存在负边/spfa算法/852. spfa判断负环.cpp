//个人建议别学这个
//这个算法并不是很好，会重负走负环，但是只要改spfa模板就好
//这题已经和最短边没什么关系了，感觉用dfs会更好
//只是恰好负环基本是最短边，只要判断到哪条边时走了超过n次
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
const int maxn=1e5+10;
int dist[2010];//也不用较大化了，只要找负环
int cnt[maxn];

//邻接表:记录边
int nx[2010];//每个点当前所对应的最新编号,赋为-1,nx[x]
int fx[maxn],e[maxn],l[maxn],idx=0;
//fx表示同为起点x的边上一次出现的位置，e表示y终点，l表示边长
void add(int x,int y,int z){
    e[idx]=y,l[idx]=z,fx[idx]=nx[x],nx[x]=idx++;
}

bool had[2010];//表示有没有在队列中
bool spfa(){
    queue<int> q;//当前所被更新过的x
    //无需重复更新，因为dist为全局变量会跟着更新
    for(int i=1;i<=n;i++){
        q.push(i);
        had[i]=1;
    }
    while(!q.empty()){
        int x=q.front();
        // cout<<x<<"  ";
        q.pop();
        had[x]=0;
        for(int i=nx[x];i!=-1;i=fx[i]){
            int y=e[i],ly=dist[x]+l[i];
            if(ly<dist[y]){//负环被记录，小于0，其他的就没必要了
                dist[y]=ly;
                cnt[y]=cnt[x]+1;//后面的会更大，如果相连前面会被后面更新掉
                //max(cnt[y],cnt[x]+1);
                if(cnt[y]>=n){
                    return 1;
                }
                if(!had[y]){
                    q.push(y);
                    had[y]=1;
                }
            }
        }

    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // memset(dist,100,sizeof(dist));
    // dist[1]=0;
    memset(nx,-1,sizeof(nx));


    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    spfa();
    if(spfa()){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;

}