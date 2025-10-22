//原题：https://www.luogu.com.cn/problem/P2437
//注：还用到了递推


#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
//封装结构体来使用高精加
struct bigint{
	int a[320]={0};//这样也是初始化
	int len=0;
	bigint(int i){//初始化
//        memset(a,0,sizeof(a));
//        len=0;
		while(i){
			a[len++]=i%10;
			i/=10;
		}
        len--;//注意会多一个
	}
	bigint(){}//没这个应该也没关系
    int &operator[](int i){//其实不会这个也没关系啦，记得什么表示就好，这样反而更不会出错
        //重载[]，bigint x;  x[i]直接表示x.a[i],简化输入
        //注意返回类型int,同时一定要有&取值，否则无法改变原值，这一点至关重要，要是记不住最好别用
        return a[i];
    }
	void flat(int l){//处理每个位置上的数
		len=l;
		for(int i=0;i<=len;i++){
			a[i+1]+=a[i]/10;//千万别忘了加等于，呜呜
			a[i]%=10;
		}
		while(a[len]==0){//除0
			len--;
		}
	}
	void print(){//输出
		for(int i=len;i>=0;i--){
			cout<<a[i];
		}
	}
}x[1010];

bigint operator+(bigint &a,bigint &b){//这里是重载函数，可去学一下
	//&是取值的意思，直接用原值，不用也行
	bigint c;//设个局内变量存答案避免混乱
	int maxl=max(a.len,b.len);
    for(int i=0;i<=maxl;i++){
        c[i]=a[i]+b[i];//重载[]主要用在这，如果能记住结构体表示的话，可不用
    }
	c.flat(maxl+1);
    return c;
}
int main() {
// 	freopen("shuru.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	//数据量较大，用递推好点f[i]=f[i-1]+f[i-2];
	int m,n;
	cin>>m>>n;
	n=n-m+1;//等价于m=1
	//有问题，涉及精度问题
//位数可用这个解决	cout<<log10(2.0)*98+1;//我们表示的是十进制，
	//大概320
	
	x[1]=bigint(1);//初始化，嘚学
	x[2]=bigint(1);
	for(int i=3;i<=n;i++){
		x[i]=x[i-1]+x[i-2];//高精加，太优雅了
	}
	x[n].print();
	return 0;

}