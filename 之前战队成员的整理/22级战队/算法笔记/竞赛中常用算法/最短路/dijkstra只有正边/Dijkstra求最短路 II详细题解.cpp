/*碎碎念：
我这个算法弯弯绕绕学了挺长时间的，主要是战队要求这个算法，我就提前来学这个算法
但学着就发现这个算法没有那么好学，那时数据结构也没接触过几个，但这个算法很需要数据结构，还有一些是图的知识
一度想放弃这个，以我这水平是真心不好理解
但还是坚持下来，给它硬搞下来，可恶，逢山开路，遇水搭桥,疯狂去学习没接触过的东西
*/

//这个是对朴素dijkstra的优化，整体的思路大体一致，但是有很多的细节不同

#include<iostream>
#include<queue>
#include<vector>//上面这两个使用  调过优先级的  优先队列
#include<utility>//想使用pair类型，类似结构体
#include<cstring>
using namespace std;

typedef pair<int,int> pii;//一对：first,second

int n,m;
const int maxn=1.5e5+10;

/*为什么用链接表呢？
可以看看当前最短边的点，看它连了多少边
*/
//接下来是链表所需的参数
int e[maxn],l[maxn],fx[maxn],cnt;
//这里是邻接表
/*
这里分别对应每条边，从n开始
e表示当前边所表示y也就是终点end；l表示边长length；fx表示上一个起点为x的编号；cnt表示当前所对应的边
*/
int nx[maxn];//nx[i]表示当前起点为x（即为i）  的边所对应的编号，用来赋给fx，需要更新，一开始赋值为-1
//最后nx为起点x最后出现的边(也就是编号)
void add(int x,int y,int z){//链接表的形式
    e[cnt]=y,l[cnt]=z,fx[cnt]=nx[x],nx[x]=cnt,cnt++;
}//用更新每条边

int dist[maxn];//该点所对应的最短边，需要大化
int had[maxn]={0};//该点是否用过

int dijkstra(){
    priority_queue<pii,vector<pii>,greater<pii> > q;//改变优先级的优先队列，主要表现优先级最高一定在队首
//pair是先比first在比second
    q.push({0,1});//前者表示当前点到起点的长度，后者表示当前点
    //为什么这样呢，因为我们要找到最短边,而最短边就在最上方，尽管会有部分冗余的点，但是我们可以标记它是否走过
    while(!q.empty()){//直到全部边都走完
        auto tmp=q.top();//auto自动类型，用不用都没差
        int now=tmp.second;//当前点,x，说具体点x就是起点到y的中转点
        q.pop();//出队
        if(had[now]){//走过了就不走了
            continue;
        }
        had[now]=1;//走过了
        //接下来要更新其相连的点了
        for(int i=nx[now];i!=-1;i=fx[i]){//这里是邻接表，不断的去链接上一条边，直到-1，这样就能找到所有起点为now的边了
            int y=e[i],len=dist[now]+l[i];//起点->y的边长
            if(dist[y]>len){//最短边更新
                dist[y]=len;
                q.push({len,y});//并压入比较最短边的队列
            }
        }

    }
    if(dist[n]>1e9){
        return -1;
    }
    return dist[n];

}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    //初始化
    memset(nx,-1,sizeof(nx));//当前边都在-1，代表不存在这个边
    memset(dist,100,sizeof(dist));//较大化，便于取最小，且不容易溢出
    dist[1]=0;
    cin>>n>>m;
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    cout<<dijkstra();




    return 0;
}




