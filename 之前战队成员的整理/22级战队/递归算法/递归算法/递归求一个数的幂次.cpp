#include<iostream>
using namespace std;
int mi(int n,int m)
{
    if(m==1)
        return n;
    else 
        return n*mi(n,m-1); 
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<mi(n,m)<<endl;
}