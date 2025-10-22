//高精乘和高精加
/*
（本质都是对我们运算过程的模拟）
为了使代码更简洁：采用结构体封装（配合重载运算符）
注意这里基本都是+=，不是赋值
为了方便计算我们数组编号从0开始
*/
#include<bits/stdc++.h>
using namespace std;
struct bigint{
	int a[100]={0};
	int len=0;
	//结构体初始化
	bigint(int x){
		//存各个位数
		while(x){
			a[len++]=x%10;
			x/=10;
		}
		len--;
	}
	bigint(){}

	//bigint a;用a[i]表示a.a[i]
	//注意要&，表示引用，理解取这个值
	int &operator[](int i){
		return a[i];
	}

	//展平，除前面的0
	void flat(int l){
		len=l;
		for(int i=0;i<=len;i++){
			a[i+1]+=a[i]/10;
			a[i]%=10;

		}
		while(a[len]==0){
			len--;
		}
	}
	void print(){
		for(int i=len;i>=0;i--){
			cout<<a[i];
		}
	}

};

//高精加
bigint operator+(bigint a,bigint b){
	bigint c;
	int l=max(a.len,b.len)+2;
	for(int i=0;i<=l;i++){
		c[i]=a[i]+b[i];
	}
	c.flat(l);
	return c;
}

//高精乘
//（1）大整形*普通数（更符合平常的运算）
bigint operator*(bigint a,int b){
	bigint c;
	int l=a.len+9;//整型最多也就8位
	for(int i=0;i<=l;i++){
		c[i]=a[i]*b;
	}
	c.flat(l);
	return c;
}
//(2)大整形*大整形（将我们省略的细节重现）
bigint operator*(bigint a,bigint b){
	//关键规律：c[i+j]=a[i]+b[j]
	bigint c;
	int l=a.len+b.len+2;
	for(int i=0;i<=a.len;i++){
		for(int j=0;j<=b.len;j++){
			c[i+j]+=a[i]*b[j];
		}
	}
	c.	flat(l);
	return c;
}
int main(){
	bigint a(3),b(56);
	bigint c;
	c=a+b;
	c.print();
	cout<<endl;

	int i=2;
	bigint d;
	d=b*i;
	d.print();
	cout<<endl;

	bigint e;
	e=a*b;
	e.print();

	return 0;
}