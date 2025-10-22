//唉，这个算法理解起来是有难度的
/*状态表示：f[i][j]
            集合：表示a[1~i]和b[1~i]的公共子序列
            属性：max
  状态计算：（当前状态与前面状态的关系）
            对于a[i],b[j]
            1.a[i]和b[j]不存在：这个毫无疑问是f[i-1][j-1]
            2.a[i]不存在，b[j]存在：
                f[i-1][(j?)]，a[i]不存在毫无疑问，但是b[j]存在就比较难确定
                    解释：我们看看当前的状态计算的所有情况，我们会对这些情况取个max
                          也就说会这个max包含b[j]存在与不存在的情况，
                          意思是说我们这个算的其实是max({a[i]不存在b[j]不存在},{a[i]不存在b[j]存在})
                          我们max的项是可以重复
                所有可以确定是f[i-1][j]
            3.a[i]存在,b[j]不存在
                f[i][j-1]
                同2:上式求的是：max({a[i]不存在b[i]存在},{a[i]不存在b[i]存在})
            4.a[i]和b[j]同时存在：
                只有当a[i]==b[j]时
                f[i-1][j-1]+1
            根据推理过程会发现第1类其实是可以忽略掉的，然后取其他的max

*/
#include<bits/stdc++.h>
using namespace std;
int f[1010][1010];
int main(){
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    a='0'+a;//注意a[0]
    b='0'+b;
    // cout<<a<<"  "<<b<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            // cout<<f[i][j]<<"  ";
            if(a[i]==b[j]){
                f[i][j]=max(f[i][j],f[i-1][j-1]+1);
            }
            // cout<<f[i][j]<<"  ;";
        }
        // cout<<endl;
    }
    cout<<f[n][m];



    return 0;
}