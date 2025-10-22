//原题：https://www.luogu.com.cn/problem/P2392
//备注：这里我主要用的是dfs，由于是我第一篇题解是我自己写的，我写的会比较复杂
//      我看很多别人的题解是用动态规划，但我还不会也看不懂，后面在详细学

//第一篇

//这里为什么能相到暴力枚举呢？
//因为你看数据量只有20，一般能行

//备注：如果想就简化下面的代码也不难，但有的会牺牲一些优化
		//为什么会写那么麻烦主要就是变量太多，我这个猪脑可能会不够用
//      1.可以将那个二维数组直接写为一维，但要记得清空，这样可以不用写入i
//		  这样也不用设那嘛多一维数组了（ans[6],cha[6]）,写一个就够用
		
//      2.数据量并不大，就算全部遍历也是小问题


//第一次尝试使用贪心，就是想从大到小，左右脑看大小依次排，但会出现两大排一起，其余小的放一块的，情况
//（2 2 2 3 3）这组数据，可片面证明贪心不可行

//这里其实是dfs优化
//我想找的是最接近一半的可能
//主要采用遍历a[i][1]参与的所有可能
//因为我们只需看一半的可能，另一半也会很接近结果的一半
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int s[6];
int a[6][30];
int sum[6];//和
bool res=0;
int temp=0;
int ans[6]={0};//为了方便计算去牺牲一点空间问题不大
//找的是哪个更接近结果的一半，最优
int cha[6]={0};//可能答案的差，这个往后看就懂了
void dfs(int i,int x,int b){//b是开始,x用来记录递归的层数，我们只要找a[i][1]参与的所有可能
	//也就是说x只要回到1，即可停止
	//因为我们只需看一半的可能，另一半也会很接近结果的一半
	if(res){
		return;//这步很重要，完成后直接返回主函数
	}
	for(int j=b;j<=s[i];j++){
		
		temp+=a[i][j];//记得回溯
		int cha_=fabs(sum[i]-(temp<<1));
		if(cha_<cha[i]){//等价于比的是哪个更接近结果的一半
		//这样才能避免使用浮点，注意要绝对值
			ans[i]=temp;
			cha[i]=cha_;//牺牲空间，去方便计算
		}
		dfs(i,x+1,j+1);
		temp-=a[i][j];//回溯，清掉影响
		if(x==1){
            temp=0;//别忘
			res=1;//x回到1，a[i][1]参与的所有可能已经结束
		}
	}
}
int main() {
// 	freopen("shuru.txt","r",stdin);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	for(int i=1;i<=4;i++){
		for(int j=1;j<=s[i];j++){
			cin>>a[i][j];
			sum[i]+=a[i][j];
		}
        ans[i]=sum[i];//初始化
		cha[i]=sum[i];//设为最大，方便后面的应算
		dfs(i,1,1);
        res=0;//别忘了重置,呜呜呜
// 		cout<<cha[i]<<"  "<<ans[i]<<endl;
	}
    int ji=0;//答案，我名字没设后
	for(int i=1;i<=4;i++){
        ji+=max(ans[i],(sum[i]-ans[i]));
    }
    cout<<ji;
	return 0;

}




//一样的方法第二版

////#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//using namespace std;
//int sum;
//int ans;
//int s;
//int a[30];
//int ans_;//可能的答案
//int cha;//ans对应的差
//void dfs(int x,int i){//i是从哪开始，x递归层数
//    if(x==0&&i==1){
//		return;//枚举一半,往下看
//	}
//    int cha_=fabs(sum-(ans_<<1));
//    if(cha_<cha){
//		  ans=ans_;
//		  cha=cha_;
//    }
//	for(int j=i;j<s;j++){
//		//搜索一半即可
//		/*也就是说我们只要找到所有a[1]参与的
//		在往下其实是等价，往组合上想，若列出所有的情况，会有一半是重复的（两队是可以交换的）
//		一个组合只有a[1]或没有的情况，找到a[1]就是找到另一半*/
//		ans_+=a[i];
//		dfs(x+1,j+1);
//		ans_-=a[i];//恢复
//	}
//}
//
//int main() {
////  	freopen("shuru.txt","r",stdin);
//
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int sans=0,s_[4];
//    for(int j=0;j<4;j++){
//        cin>>s_[j];
//    }
//	for(int j=0;j<4;j++){
//		//全部初始化
//		s=s_[j];
//		memset(a,0,sizeof(a));
//		sum=0;
//		for(int i=0;i<s;i++){
//			cin>>a[i];
//			sum+=a[i];
//		}
//        ans_=0;//这里需要特别注意一下
//        cha=sum;
//		dfs(0,0);
//        cout<<ans<<endl;
//		sans+=max(ans,sum-ans);
//
//	}
//	cout<<sans;
//	return 0;
//}