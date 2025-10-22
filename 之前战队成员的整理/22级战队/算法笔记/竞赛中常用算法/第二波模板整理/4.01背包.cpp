//滚动数组优化版
#include<bits/stdc++.h>
using namespace std;
int f[1010];
int main(){
    int N,V;
    cin>>N>>V;
    for(int i=0;i<N;i++){
        int v,w;
        cin>>v>>w;
        for(int j=V;j>=v;j--){
            f[j]=max(f[j],f[j-v]+w);
        }
    }
    cout<<f[V];

    return 0;
}