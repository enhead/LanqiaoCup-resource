/*
求最大公约数：
（数论），现在这些直接记就行
函数：__gcd(a,b);//注意有两个下划线
辗转相除法（gcd）
    做法:两数相除，然后取之前的被除数做除数，取余做被除数，
            重复上述过程，直到余数为0
    (有一些优化版本，但这个版本就够用了)
    //也不用管谁大谁小，运算过程中自动换算
    while(b>0){
        int tmp=a%b;
        a=b;
        b=tmp;
    }
*/
/*
求最大公约数
（数论），就不推了，直接记
lcm算法：
    最大公约数=a*b/__gcd(a,b);
    //    两数相乘/最小公倍数
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    cout<<a*b/__gcd(a,b)<<endl;
    while(b>0){
        int tmp=a%b;
        a=b;
        b=tmp;
    }
    cout<<a<<endl;


    return 0;
}