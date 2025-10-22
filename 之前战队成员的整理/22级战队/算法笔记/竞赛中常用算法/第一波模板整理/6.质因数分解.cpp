//质因数分解
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    cout<<"a=";
    for(int i=2;i<=a;i++){//这样就能完全筛
        while(a%i==0){//
            //这里有点类似质数筛的第二种方法
            //每个非素数都能分解为比他小的素数的乘积
            //例如：4=2*2，72=2*2*2*3*3
            cout<<i;
            a/=i;
            if(a!=1){//免得多输出一个
                cout<<'*';
            }
        }
    }
    return 0;
}