#include<bits/stdc++.h>
using namespace std;
int dp[100010][3][2],n,a[100010][3],ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);//读入每个位置各种高度的观赏价值
    for(int j=0;j<3;j++){//穷举树的高度（有三种）
        for(int i=0;i<3;i++)
            for(int k=0;k<2;k++)dp[1][i][k]=0;//初始化，全部赋值为0
        dp[1][j][0]=dp[1][j][1]=a[1][j];//初始值为a[1][j]
        for(int i=2;i<=n;i++){//循环每个位置作决策
            dp[i][0][0]=max(dp[i-1][1][1],dp[i-1][2][1])+a[i][0];
            dp[i][1][0]=dp[i-1][2][1]+a[i][1];
            dp[i][1][1]=dp[i-1][0][0]+a[i][1];
            dp[i][2][1]=max(dp[i-1][1][0],dp[i-1][0][0])+a[i][2];
        }
        for(int i=0;i<j;i++)ans=max(ans,dp[n][i][0]);//分类迭代ans，<=j的高度肯定是比它矮的，所以为dp[n][i][0]
        for(int i=2;i>j;i--)ans=max(ans,dp[n][i][1]);//与上述类似，>j的肯定是比它高的，所以为dp[n][i][1]
    }
    printf("%d",ans);//输出结果
    return 0;
}