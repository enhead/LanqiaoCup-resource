/*多重背包思路：
总是去往01背包上靠
1.基本思路：就是将第i个物品（体积v，价值w）个数s，又分别转为了s个物品（体积k*v，价值k*w）（k=1，2，3，k，~s）
2.二进制优化：一个一个物品去加，复杂度过高了，肯定会超时
(缺)
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=1.1e4;
int v[maxn],w[maxn];//log2(maxs)*1000约为11000
int f[2010];
int main(){
    int N,V;
    cin>>N>>V;
    int cnt=-1;
    //第i个物品又去合成新的二进制版物品
    //新的物品表示为（空间为k*v，价值为k*w）
    for(int i=0;i<N;i++){
        int a,b,s;
        cin>>a>>b>>s;
        int k=1;
        while(k<s){
            cnt++;
            v[cnt]=k*a;
            w[cnt]=k*b;
            s-=k;
            k*=2;
        }
        if(s>0){
            cnt++;
            v[cnt]=s*a;
            w[cnt]=s*b;
        }
    }
    for(int i=0;i<=cnt;i++){
        //一维滚动数组优化，要不然数组太多了
        // cout<<v[i]<<"   "<<w[i]<<endl;
        for(int j=V;j>=v[i];j--){
            f[j]=max(f[j],f[j-v[i]]+w[i]);
            // cout<<"f"<<j<<"= "<<f[j]<<";";
        }
        // cout<<endl;
    }
    // for(int j=0;j<=V;j++){
    //     cout<<f[j]<<" ";
    // }
    cout<<f[V];
    return 0;
}