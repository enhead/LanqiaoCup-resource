//回到本质：生成树：有n个点用n-1条边相连
/*
kruskal算法（又称为加边法）
（这个算法会更优点）
理解：若一条小边不在同一个集合内（这里使用并查集），
      则将这个点加入集合，并将边权记录
      加n-1就是最小生成树了


这里还采用了并查集：
简单来讲：就是用最新的点来表示整个集合
    (编号表示当前点，值表示指向的点)
    (最初指向自己)
    因此要首先要find最新的点
    若最新的点不在同一个集合中，
    就将两个集合合并（其中的一个点指向另一个点（最新点））
优化：1.路径压缩（2.初始为-1表示（没差多少））
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int maxn1=2e5+10;
int n,m;
struct Node{
    int u,v,w;
    bool operator<(const Node &other)const{
        return w<other.w;
    }
}a[maxn1];

//并查集
int p[maxn];
int find(int x){
    if(p[x]!=x){
        p[x]=find(p[x]);
        return p[x];
    }else{
        return x;
    }
}

int ans=0;
bool kruskal(){
    int cnt=0;
    sort(a,a+m);//从小到大排
    for(int i=0;i<m;i++){
        // cout<<a[i].u<<" "<<a[i].v<<endl;
        int x=find(a[i].u),y=find(a[i].v);
        //若两个点不在同一个集合
        if(x!=y){
            p[x]=y;
            ans+=a[i].w;
            cnt++;
            if(cnt==n-1){
                break;
            }
        }

    }

    if(cnt==n-1){
        return 1;
    }else{
        return 0;
    }


}
int main(){
    cin>>n>>m;
    //并查集初始化
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[i]={u,v,w};
    }

    if(kruskal()){
        cout<<ans;
    }else{
        cout<<"impossible";
    }

    return 0;
}