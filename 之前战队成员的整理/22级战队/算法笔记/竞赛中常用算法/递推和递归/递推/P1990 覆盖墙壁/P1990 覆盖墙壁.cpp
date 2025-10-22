//原题：
//https://www.luogu.com.cn/problem/P1990

//这里去看题解吧，要画图才能讲明白，


#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int f[maxn],g[maxn];
//int mod=1e4;
int main() {
// 	freopen("shuru.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;cin>>n;
	f[1]=1;f[2]=2;f[3]=5;
//	g[2]=2;
	for(int i=4;i<=n;i++){
							//		g[i]=g[i-1]+f[i-2]*2;
//第一种写法：			//		g[i]%=mod;
						//		f[i]=f[i-1]+f[i-2]+g[i-1];
						//		f[i]%=mod;
	//优化一下：
		f[i]=f[i-1]*2+f[i-3];				
		f[i]%=mod;
	}
	cout<<f[n];
	
	
	
	return 0;

}