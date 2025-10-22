/*
整数分解：
1.最简单的一种肯定是用字符串记录：
    但是它不好处理负数，同时要注意s[0]是从最高位记录
2.一般做法：
    int c[100];
    int len=0;//记录长度
    while(a){
        c[len++]=a%10;
        a/=10;
    }
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    //从个位开始记录
    int c[100];
    int len=0;//记录长度
    int b=0;
    while(a){
        b=b*10+a%10;
        a/=10;
    }
    cout<<b;

    return 0;
}