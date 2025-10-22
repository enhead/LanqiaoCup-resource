#include<iostream>
using namespace std;
const int MAXN=1e5+7;
int N,M,a[MAXN],cnt=0;
bool st[MAXN];
void pailie(int n,int m)
{
    if(n==m)
    {
        for(int i=1;i<=m;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=1;i<=N;i++)
    {
        if(st[i]==false)
        {
            st[i]=true;
            a[++cnt]=i;
            pailie(n+1,m);
            st[i]=false;
            a[cnt--]=0;
        }
    }
}
int main()
{
    cin>>N>>M;//1~n中选m个数
    for(int i=1;i<=N;i++)
    {
        st[i]=true;
        a[++cnt]=i;
        pailie(1,M);
        st[i]=false;
        a[cnt--]=0;
    }
}