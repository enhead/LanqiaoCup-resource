#include<iostream>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
int get_max(int nowmax,int nowid,int len)//递归模拟for循环
{
    if(nowid==len+1)
        return nowmax;
    if(nowmax<a[nowid])
    {
        return get_max(a[nowid],nowid+1,len);
    }
    else
        return get_max(nowmax,nowid+1,len);
}
int GET_MAX(int nowlen)//递归模拟递推
{
    //GET_MAX(n)表示前n个中的最大值
    //要求前nowlen，已知前nowlen-1
    if(nowlen==1)
        return a[1];
    return a[nowlen]>GET_MAX(nowlen-1)?a[nowlen]:GET_MAX(nowlen-1);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<get_max(-1,1,n)<<endl;
    cout<<GET_MAX(n)<<endl;
}