//bf算法：字符串a中查找字符串b的暴力做法(能优化（kmp算法缺）)
//我是推荐直接用字符串中的find函数：a.find(b,[pos]);//pos表示从哪开始，默认为0，会返回位置
//这个函数最好熟悉一下
#include<string>
#include<iostream>
using namespace std;
string a,b;
int BF(){
	//i为a的指针，j为b的指针
    //哎呀，要注意范围
    int la=a.size(),lb=b.size();
	for(int i=0;i<=la-lb;i++){
		int j=0;
		while(b[j]==a[i+j]&&j<lb){//条件也注意一下
		//要注意避免超过数组
			j++;
		}
		if(j==lb){
			return i;
		}
	}
	return -1;


}
int main(){
	cin>>a>>b;
	cout<<BF();
//	cout<<a.find(b);


	return 0;
}