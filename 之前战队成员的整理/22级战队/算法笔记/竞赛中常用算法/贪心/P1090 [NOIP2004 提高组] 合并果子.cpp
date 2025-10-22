//原题：https://www.luogu.com.cn/problem/P1090
	
	//唉，如果要用贪心一定一定一定要将例子举全，我的经验（我也没做多少题）是最好数据要在四个以上，最好是想邻且有几个相等
	//否则很容易错，模拟完后，你会发现这题是贪心
	//每次都取前两个最小的，又合成新的一堆，前两个要去掉
	//由于还没学数据结构（很快就能学到了，我就不专研啦），然后为方便排序和插入，选择存下标记法
	//当然使用书上那种两个数组的方法（一个从小到大的记录原来，另一个记录合并后的新堆<这里本来就是从小到大排>，使用完前两个就抛弃，每次只需比较标记的元素即可）会更省时间和空间


#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
typedef long long ll;
using namespace std;
const int maxn=2e8+10;//呜呜呜，哭了RE了，一般情况下是1.数组越界2.除0  3.算法太差
//这里最后看了下样例，是数组越界。所以才设那么大
int a[maxn]={0};
long long ans;
int main() {
// 	freopen("shuru.txt","r",stdin);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	int n;
	cin>>n;
	int maxa=1,mina=maxn;//记录一下
	for(int i=0; i<n; i++) {
		int b;cin>>b;
		maxa=max(maxa,b);//不一定能优化上
		mina=min(mina,b);
		a[b]++;
	}
	int c=0;
	int ji=0;//记录到两个没有
	for(int i=mina;i<=maxa;i++){
		while(a[i]){
			c+=i;a[i]--;
			ji++;
			if(ji==2){
				ans+=c;
                maxa=max(maxa,c);//这里需要特别注意一下
				a[c]++;
				c=ji=0;//清空
			}
		}
	}
	cout<<ans;
	return 0;
}