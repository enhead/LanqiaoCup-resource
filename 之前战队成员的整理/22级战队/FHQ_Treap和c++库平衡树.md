# ==S9.FHQ_Treap==

时间复杂度logn

平衡树：如果n个元素建成二叉排序树，为了保证时间复杂度靠近logn，我们希望左右子树尽量节点个数相同。

因此当两个树合并的时候，我们引入了一个“堆权值/树权值”的概念，要求根节点到叶子节点，权值逐渐递减，也就是尽可能让权值大的当父节点，这个权值，我们使用随机数来给每个新加进来的节点赋值权值

为了统一说法，下面所有的随机数产生的权值，都用pri值来说明，下文提到权值指的是元素的数值

FHQ_Treap有两个操作：分裂和合并，由这俩个基本操作来实现各种要求，不需要旋转，所以很好写



[P3369 【模板】普通平衡树 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P3369)

## 分裂&合并

分裂的时候不需要考虑pri值，只要记住一个思路：输入一个参数x，将原树分裂，所有小于等于x的划分成一个树，大于x的都划分成一个树，原树变成了两个树a和b

![](素材/246085_bce176080f-平衡树分裂.png)

```c++
void split(int u,int x,int &l,int &r){//l,r是每次操作中都重新定义一遍，要定义成引用。
    //目的是拆分后，得到两个树的根节点，一左一右，想调用左/右子树直接调用l，r就行了
    //u是当前遍历到的节点，他的左右子节点是t[u].ls和t[u].rs，x是需要分割的值，小于等于x分成一个树，大于x的分成一个树
    
	if(u==0){l=r=0;return;}//如果u是0，说明碰到叶子节点了，返回0就行了
	if(t[u].val<=x){//分到左子树，因为是二叉排序树，右子节点的权值大于父节点，所以我们递归确定一下右子节点划到哪一颗树
		l=u;
		split(t[u].rs,x,t[u].rs,r);//注意这里的l，r，lr是个范围，
        //我们把当前探索的根节点挪到u的右子节点，范围变成[右子节点，r]
	}
	else{//同理，分到右子树，看下这个节点的左边
		r=u;
		split(t[u].ls,x,l,t[u].ls);//根节点挪到左子节点，范围变成[l,左子节点]
	}
	update(u);//改变树的结构分成两个树了，所以更新一下父节点值，跟线段树一样
}
```



合并是个麻烦事

因为我们要是直接暴力把两个树按照二叉树排序直接连到一块，并不能保证左右子树的节点个数尽量平衡，所以这时候我们拿出了pri值，谁的pri值大，我们让他当父节点放进树中，这样一层层排下去，因为pri值是随机数，所以能类似接近于平衡树的logn层

![](素材/246085_c4159b580f-平衡树合并-17154420605282.png)

黄字是pri值，蓝字是权值

```c++
int merge(int l,int r){//这里l树的权值必须<=r树的权值，才能保证二叉排序树的结构
	if(!l||!r) return l+r;//如果其中一个为0，那么返回l+r就是返回那个不为0的树，0是代表走到叶子节点，走到头了
	if(t[l].pri>t[r].pri){//l的根节点pri值更大，考虑将r树接在l树的右子树上
		t[l].rs=merge(t[l].rs,r);//更新l的右子树，并update
		update(l);
		return l;//返回进行完当前操作的新树的根
	}
	else{
		t[r].ls=merge(l,t[r].ls);
		update(r);
		return r;
	}
    //注意要保证l树的权值始终小于r的权值，所以在这两个参数上，第一个参数始终写l或其子树，第二个参数始终写r及其子树
}
```





## 衍生操作

为了能够确定排名（定义排名为比当前数小的数的个数+1），这里引入一个size(代码中定义成了sz),sz是以u为根节点的叶子节点的数量，数量+1就是这个节点的排名

注意！你在自己画图后可能有点疑惑，这个数量+1也不是排名啊，要先分裂才能确定排名，分裂成只剩下x本身和比x小的数，然后sz+1才是你想要的答案，**所以输出排名，要拿左子树的排名+1来进行输出**

```c++
int root=0,cnt=0;//root是当前题目树的根节点，每次进行分裂操作后，都要及时merge并更新root。
//cnt是当前用了多少个元素，每一个cnt存的，其实都相当于一个只有一个节点的树，因此我们可以调用cnt来调用新加入的元素，让他加入树
struct Node{
	int ls,rs;
	int val,pri;
	int sz;
}t[N];
void newNode(int x){
	cnt++;
	t[cnt].val=x;
	t[cnt].pri=rnd();
	t[cnt].sz=1;
	t[cnt].ls=t[cnt].rs=0;
}
void update(int u){//这里+1，是因为假如u上面还有节点，u的父节点读取u的sz，就得到了u这一块树的节点个数，也正好是排名
	t[u].sz=t[t[u].ls].sz+t[t[u].rs].sz+1;
}



//插入：将树分成<=x的和大于x的，然后再让<=x的和x结合，再把这一块跟大于x的结合
void insert(int x){
	int l=0,r=0;
	split(root,x,l,r);
	newNode(x);
	int aa=merge(l,cnt);
	root=merge(aa,r);
}
//删除只会删除一个x，因为当遍历到x时候，就会去找比x大的子树了，小于等于x的都在x的左子树
//分成<=x和大于x，再把左边分成<=x-1,这里剃掉了一个x，再把左边跟最初的右边相结合，就结束了
void del(int x){
	int l,r,p;//得到分裂后的l和r
	split(root,x,l,r);
	split(l,x-1,l,p);
	p=merge(t[p].ls,t[p].rs);//p是左子树中的子右子树，这个子右子树被削了一个x，确定一下这个新生的右子树的根节点
	root=merge(merge(l,p),r);//再跟母体左子树结合，最终在跟右子树结合
}
//左子树的sz+1
//比较排名的时候，记住要拿左子树来比较！
void rk(int x){
	int l,r;
	split(root,x-1,l,r);
	cout<<t[l].sz+1<<'\n';
	root=merge(l,r);
}
int kth(int u,int k){
	if(k==t[t[u].ls].sz+1) return u;//找到了
	if(k<=t[t[u].ls].sz) return kth(t[u].ls,k);//在左子树里面
	if(k>t[t[u].ls].sz) return kth(t[u].rs,k-t[t[u].ls].sz-1);//不在左子树，也不是根节点，所以-sz-1
}
void pre(int x){//找前缀
	int l,r;
	split(root,x-1,l,r);
	cout<<t[kth(l,t[l].sz)].val<<'\n';
	root=merge(l,r);
}
void aft(int x){//找后缀
	int l,r;
	split(root,x,l,r);
	cout<<t[kth(r,1)].val<<'\n';
	root=merge(l,r);
}
```







下面就是模板，考试时候直接抄上去，想调用那个函数调用那个函数就完事了

```c++
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
mt19937 rnd(114514);
int cnt=0,root=0;
int fg=0;
struct Node{
	int ls,rs;
	int val,pri;
	int sz;
}t[N];
void newNode(int x){
	cnt++;
	t[cnt].val=x;
	t[cnt].pri=rnd();
	t[cnt].sz=1;
	t[cnt].ls=t[cnt].rs=0;
}
void update(int u){
	t[u].sz=t[t[u].ls].sz+t[t[u].rs].sz+1;
}
void split(int u,int x,int &l,int &r){
	if(u==0){l=r=0;return;}
	
	if(t[u].val<=x){
		l=u;
		split(t[u].rs,x,t[u].rs,r);
	}
	else{
		r=u;
		split(t[u].ls,x,l,t[u].ls);
	}
	update(u);
	
}
int merge(int l,int r){
	if(!l||!r) return l+r;
	if(t[l].pri>t[r].pri){//存疑，为什么是>不是大于等于
		t[l].rs=merge(t[l].rs,r);
		update(l);
		return l;
	}
	else{
		t[r].ls=merge(l,t[r].ls);
		update(r);
		return r;
	}
}
void insert(int x){
	int l=0,r=0;
	split(root,x,l,r);
	newNode(x);
	int aa=merge(l,cnt);
	root=merge(aa,r);
}
void del(int x){
	int l,r,p;
	split(root,x,l,r);
	split(l,x-1,l,p);
	p=merge(t[p].ls,t[p].rs);
	root=merge(merge(l,p),r);
}
void rk(int x){
	int l,r;
	split(root,x-1,l,r);
	cout<<t[l].sz+1<<'\n';
	root=merge(l,r);
}
int kth(int u,int k){//这里+1，-1存疑
	if(k==t[t[u].ls].sz+1) return u;
	if(k<=t[t[u].ls].sz) return kth(t[u].ls,k);
	if(k>t[t[u].ls].sz) return kth(t[u].rs,k-t[t[u].ls].sz-1);
}
void pre(int x){
	int l,r;
	split(root,x-1,l,r);
	cout<<t[kth(l,t[l].sz)].val<<'\n';
	root=merge(l,r);
}
void aft(int x){
	int l,r;
	split(root,x,l,r);
	cout<<t[kth(r,1)].val<<'\n';
	root=merge(l,r);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	while(n--){
		int opt,x;cin>>opt>>x;
		if(opt==1){
			insert(x);
		}
		else if(opt==2){
			del(x);
		}
		else if(opt==3){
			rk(x);
		}
		else if(opt==4){
			cout<<t[kth(root,x)].val<<'\n';
		}
		else if(opt==5){
			pre(x);
		}
		else if(opt==6){
			aft(x);
		}
	}
	return 0;
}
```

## 用库实现平衡树

c++库里的平衡树，不能插入重复的数字，但是有办法解决。把树的权值int改为pair<int,int>,插入时，若插入x，则写成插入pair<x,cnt++>,这样即使插入重复个x，cnt也不一样，每次输出输出pair的first即可

```c++
//两个库，写bits/stdc++.h也行
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//需要写上命名空间__gnu_pbds::
__gnu_pbds ::tree<pair<int, int>, __gnu_pbds::null_type, less<pair<int, int> >,
                  __gnu_pbds::rb_tree_tag,
                  __gnu_pbds::tree_order_statistics_node_update>
    trr;
//挨个解释一下，pair<int,int> 是平衡树中的权值
			 __gnu_pbds::null_type 必须这么填，低版本填编译器填__gnu_pbds::null_mapped_type
			 第三个填比较函数 std::greater<> or std::less<> or cmp or less<pair<int, int> >
			 les<...> 前n个元素是1,2,3,4,....
			 第四个填树的类型，有rb_tree_tag红黑树和splay_tree_tag
			 //第五个是为了支持查询第k大和排名的一个参数
```



```c++
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
__gnu_pbds ::tree<pair<int, int>, __gnu_pbds::null_type, less<pair<int, int> >,
                  __gnu_pbds::rb_tree_tag,
                  __gnu_pbds::tree_order_statistics_node_update>
    trr;

int main() {
  int cnt = 0;
  int q, opt, x;
 
    scanf("%d", &q);
    for (int i = 1; i <= q; ++ i)
    {
        scanf("%d%d", &opt, &x);
        //删除一个数
        if(opt == 1){
        	trr.insert(mp(x,cnt++));
        }
        //删除一个数
        if(opt == 2){
        	trr.erase(trr.lower_bound(mp(x,0)));
        }
        //查询一个数的排名
        if(opt == 3){
        	printf("%d\n", (int)trr.order_of_key(mp(x,0)) + 1);
        } 
        //查询第k小的数 返回的是一个迭代器 这里k是从0开始算的，意思是最小的数是第0小的
        //每个节点的权值就是pair的first
        if(opt == 4){
        	printf("%d\n", (*trr.find_by_order(x - 1)).first);
        } 
        //查询一个数的前驱
        if(opt == 5){
        	printf("%d\n", (*( -- trr.lower_bound(mp(x,0)) )).first);
        } 
        //查询一个数的后继
        if(opt == 6){
        	printf("%d\n", (*trr.lower_bound(mp(x + 1,0))).first);
        } 
        
    }

  return 0;
}
```