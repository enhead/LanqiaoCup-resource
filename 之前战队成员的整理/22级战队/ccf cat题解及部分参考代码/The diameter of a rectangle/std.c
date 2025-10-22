#include <stdio.h>

typedef long long ll;

#define N 1000006

int n,root,top=0;
int a[N],b[N],L[N],R[N],s[N];
ll sum[N];
ll ans=0;

ll Max(ll x,ll y){
	if(x>y)return x;
	else return y;
}
ll Min(ll x,ll y){
	if(x>y)return y;
	else return x;
}
void dfs(int x){
    if(!x)return ;
    dfs(L[x]);
    dfs(R[x]);
    sum[x]=sum[L[x]]+sum[R[x]]+1ll*b[x];
}
int main(){
    //freopen("10.in","r",stdin);
    //freopen("10.out","w",stdout);
    scanf("%d",&n);
    int i; 
    for(i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
    for(i=1;i<=n;i++){
        while(top && a[s[top]]>a[i]){
            L[i]=s[top--];
        }
        if(top)R[s[top]]=i;
        s[++top]=i;
    }
    root=s[1];
    dfs(root);
    for(i=1;i<=n;i++)ans=Max(ans,Min(1ll*a[i],sum[i])*Min(1ll*a[i],sum[i]));
    printf("%lld\n",ans);
}
