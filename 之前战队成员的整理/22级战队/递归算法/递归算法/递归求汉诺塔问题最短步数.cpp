#include<iostream>
using namespace std;
int hanno(int n)
{
    if(n==1)
        return 1;
    else 
        return 2*hanno(n-1)+1;
}
int main()
{
    int n;
    cin>>n;
    cout<<hanno(n)<<endl;
}