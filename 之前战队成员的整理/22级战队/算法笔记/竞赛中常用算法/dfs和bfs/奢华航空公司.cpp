//原题链接：
//https://ac.nowcoder.com/acm/contest/51364/L

//像这种dfs中判断只有能不能放的可以先看看洛谷p191-193的 P2392   的题解，先学一下
//当然直接看这个也行，如果你相信我的话（但是最好别信，我很菜）
/*碎碎念（都是废话）：
这题是学校战队的训练题，写了一个半小时，（上头了，就像dfs一样不撞头不回头，啊不对，是撞头也不回头）当时脑子转不过来（太笨了，呜呜呜）
虽然能想到是dfs，但我采用的方法（失败了）是，走一步的同时，将其影响的格子给封掉，然后走下一步看看有没有被封（这方法应该是可行的）
但实现起来发现，这个方法有很多需要注意，1.一口需要封五个，又要复原5个2.你不能影响在这个格子走之前影响的格子
综上，这个方法并不优，且很容易出错〒▽〒
*/
/*赛后复盘（看完题解后，自己在写）：
这次我们就先判断能不能走（上下左右有没有被占）（这里主要在判断上），没有的话可以占掉，然后复原
（这里你就不需要一口气封五个，也不需要判断前面的影响，只有当前格子放不放，唉）
在具体实现上，我打算采用二维的dfs（只有一小斯不同,就不一维转二维了）
*/

//因为是训练，我会采用训练（竞赛）的一些优化，主要区别就在前面了，可以学学
#pragma optimize(2)//开o2优化
#include<bits/stdc++.h>//万能头文件
using namespace std;
typedef long long ll;//数据结构略写
ll ans;
int m,n,k;
bool a[100][100];
void dfs(int row,int col,int x){//row表示行，col表示列，x表示选了几个
    if(x==k){
        ans++;
        return;
    }
    if(row==n&&col==m+1){
        return;//全部遍历完，结束
    }
    if(col>m){//下一行
        row++;col=1;
    }
    if(a[row-1][col]==0&&a[row][col-1]==0&&a[row+1][col]==0&&a[row][col+1]==0){
        //四个方位都没有人，就选
        a[row][col]=1;
        dfs(row,col+1,x+1);//行不需要动，自动换算，
        a[row][col]=0;//还原
    }
    dfs(row,col+1,x);//不选这个直接往下
}
int main(){

    ios::sync_with_stdio(false);//关掉与c语言输入输出的同步
    cin.tie(0);cout.tie(0);//关掉c++输入输出的关联

    int t;cin>>t;
    while(t--){
        //初始化
        ans=0;
        memset(a,0,sizeof(a));
//         string s;
//         getline(cin,s);
        cin>>m>>n>>k;
        dfs(1,1,0);
        ans%=420047;
        cout<<ans<<"\n";
    }


    return 0;
}

