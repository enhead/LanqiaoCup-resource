/*
kruskal算法又称加边法，从最小边开始加，边里会有两个点，将这些点加入集合中
一个点可以连多个边，但是边不能是集合内的点
*/


/*
一开始原本想使用存下标记法，想用had数组标记在集合内（就是最小生成树）的点，
但发现根本就行不通，有的集合间并没有联通，这问题需要注意
*/
//这里标记联通的集合需要用到并查集，我这时候还没去学
//尽管并查集代码很短，但设计得无比巧妙
//我是通过模拟代码大概理解其中的步骤和方法，应该不是很严谨，但还是硬解释一下
/*并查集
核心思想：用集合中得一个元素去描述整个集合
储存：一维数组  p[]
        需注意：数组的标号表示点，取值也表示点
初始化：p[i]=i;  //代表没有点联通，点i->i，就是一个孤零零的点（其实也是个集合，也是一个根节点）
相联操作(集合合并)：p[x]=y;  //先简单理解为x->y，
                   //下面你需要非常注意这个x和y到底表示的是什么？相联的是什么？
寻找集合最前头的点（find）：递归dfs函数，找到p[x]==x,的那个点，就是根节点(根节点就是当前点所在集合中最前面（新）的那个点)
							（这里可以路径压缩优化）
*/
/*先举个例子：（朴素版）（没有路径压缩）
这里的集合是按顺序加入的：
一开始：{5，7，3}
    int x=find(5)=5,int y=find(7)=7（别忘了已经初始化了）
    p[x]=y  p[5]=7，（p[7]=7;）  7变为了这个集合的最新点，find接下来找的就是这个
    p[7]=3;p[3]=3;              此时3变为了最新点，find找这个
然后：在创个集合{1，6，2}；
      p[1]=6;p[6]=2;p[2]=2;     2是最新点
最后：合并集合{7，6}
        find(7)=3,find(6)=2;
        p[3]=2;                 连接集合，2是最新点
*/
/*解释：
    x其实是表示以x为暂时最前头节点的集合；y同理；
    代表x->y，x与y相联，y更新为【合并后两个集合】的根节点（最新点）
    a[旧节点]=新节点；   a[新节点]=新节点；
    //这里着重理解一下
*/

/*
    初始化也可为：-1
    find根节点就是找-1
*/

#pragma optimize(2)
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=2e5+10;
const int maxn1=1e5+10;
int n,m;
int p[maxn1];
struct Node{
    int x,y,z;
    bool operator<(const Node &other)const{//结构体的重载，便于排序
        return z<other.z;

    }
}node[maxn];
int cnt=0;//根据前面做的题你会知道，想相联n个点，那他必须为n-1条边
//并查集也是一种相联操作，没操作一次表示连一条边
long long ans=0;


//find函数你需要仔细看看，这个是有讲究的
////第一种
// int find(int x){
//     if(p[x]!=x){
//         // return find(p[x]);//一开始我写是这个，但是他找到答案会一层一层返回，效率低
//								//上面这个就是路径优化
//         p[x]=find(p[x]);
//     }else{
//         return p[x];
//     }
// }
//第二种
int find(int x){
    if(p[x]!=-1){
        p[x]=find(p[x]);//这里就是路径压缩
        //返回的同时更新p[x]，将走过的更新为同个根节点

    }else{
        return x;//注意一下返回的是点
    }
}
void kruskal(){
    sort(node,node+m);//从小到大排
    for(int i=0;i<m;i++){
        int x=node[i].x,y=node[i].y,z=node[i].z;
        int a=find(x),b=find(y);//找各自集合的最新的（根节点）
        //其中a表示旧的，b表示新根节点
        if(a!=b){
            p[a]=b;//集合合并，b成为这个集合的新根节点
            cnt++;//连了一条边
            ans+=z;
        }
    }
    if(cnt==n-1){
        cout<<ans;
    }else{
        cout<<"impossible";
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);


    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        node[i]={x,y,z};
    }

    //并查集初始化
    // 第一种
    // for(int i=1;i<=n;i++){
    //     p[i]=i;
    // }
    //第二种
    memset(p,-1,sizeof(p));

    kruskal();

    return 0;
}