#include<bits/stdc++.h>
using namespace std ;

int main() 
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;
    
    int n , k ;
    cin >> n >> k ;
    vector<int> t(n + 1 , 0) ;
    vector<int> v(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> t[i] ;
    for(int i = 1 ; i <= n ; i ++)  cin >> v[i] ;
    priority_queue<int , vector<int> , greater<int>> q ;
    vector<int> p(100000 + 10 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  p[t[i]] = v[i] ;
    for(int i = 100000 ; i >= 1 ; i --)
    {
        if(p[i] == 0)  continue ;
        q.push(p[i]) ;
        if(q.size() > k)
        {
            assert(q.size() == k + 1) ;
            q.pop() ;
        }
    }
    int s = 0 ;
    while(!q.empty())
    {
        int u = q.top() ;
        s += u ;
        q.pop() ;
    }
    cout << s << '\n' ;

    return 0 ;
}