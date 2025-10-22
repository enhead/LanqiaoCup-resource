#include<iostream>
using namespace std;
const int MAXN=1e5+7;
int N,M,a[MAXN],cnt=0;
bool st[MAXN];
void combi(int n,int m)
{
    if(cnt==m)
    {
        for(int i=1;i<=cnt;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        return ;
    }
    for(int i=n;i<=N;i++)
    {
        if(st[i]==false)
        {
            st[i]=true;
            a[++cnt]=i;
            combi(i,m);
            a[cnt--]=0;
            st[i]=false;
        }
    }
}
int main()
{
    cin>>N>>M;
    for(int i=1;i<=N-M+1;i++)
    {
        st[i]=true;
        a[++cnt]=i;
        combi(i,M);
        a[cnt--]=0;
        st[i]=false;
    }
}