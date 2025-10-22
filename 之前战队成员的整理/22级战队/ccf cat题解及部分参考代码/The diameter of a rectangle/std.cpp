#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 1000006

int n,root;
int a[N],b[N],L[N],R[N];
ll sum[N];
stack<int >S;
ll ans=0;

void dfs(int x){
    if(!x)return ;
    dfs(L[x]);
    dfs(R[x]);
    sum[x]=sum[L[x]]+sum[R[x]]+1ll*b[x];
}
int main(){
    freopen("20.in","r",stdin);
    freopen("20.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
    for(int i=1;i<=n;i++){
        while(!S.empty() && a[S.top()]>a[i]){
            L[i]=S.top();
            S.pop();
        }
        if(!S.empty())R[S.top()]=i;
        S.push(i);
    }
    while(!S.empty()){
        root=S.top();
        S.pop();
    }
    dfs(root);
    for(int i=1;i<=n;i++)ans=max(ans,min(1ll*a[i],sum[i])*min(1ll*a[i],sum[i]));
    cout<<ans<<endl;
}
