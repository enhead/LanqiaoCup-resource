/*
dfs（深度搜索）：
如果看到对于每一项都有选与不选（或其他多种可能）
然后看到数据量要小于40，才能用；如果超过100或1000那么大部分时候都是dp了

有两种模板，但其实都是等价的：
    1.基本（每个步有多种可能）
    void dfs(int x){//x递归是递归层数，一般是必备的，有时候会有其他参数
        if(得到答案){
            记录/判断答案；
            return;
        }
        if(所有步走完){
            return；
        }
        for(枚举这空的可能的值){
            if(合法){
                记录影响；//一般使用全局变量来记录（函数外的）
                dfs(x+1);
                消除影响；
            }
        }
    }
    2.选与不选：
    //这里思维也别太局限，int i也可以不要
	//然后用以had数组表示选和不选，到n输出答案，同时停止
    void dfs(int x,int i){
        //i表示一维数组编号，x表示选了几个
        if(得到答案){
            记录/判断答案；
            return;
        }
        if(所有步走完){
            return；
        }
        if(合法){
            记录影响；//一般使用全局变量来记录（函数外的）
            dfs(x+1,i+1);//选
            消除影响；
        }
        dfs(x,i+1);//不选
    }
*/


//dfs全排序（n选m）
#include<bits/stdc++.h>
using namespace std;
int a[100];
int n,m;
//选与不选模板：
int f[100];//全局变量，记录函数的影响
void dfs(int x,int i){
    //现在i表示到哪
    if(x==m){
        for(int i=0;i<m;i++){
            cout<<f[i]<<"  ";
        }
        cout<<endl;
        return;
    }
    if(i>=n){
        return;
    }
    f[x]=a[i];
    dfs(x+1,i+1);//选了a[i]
    f[x]=0;//有没有这步也没差啦
    dfs(x,i+1);//不选a[i]
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,0);

    return 0;
}