#include <stdio.h>
#include <stdlib.h>
int n , rt ;
int p[4000 + 10] ;
int ls[4000 + 10] , rs[4000 + 10] ;
void dfs(int u , int x)
{
    if(x < u)
    {
        if(ls[u] != 0)  dfs(ls[u] , x) ;
        else  ls[u] = x ;
    }
    else
    {
        if(rs[u] != 0)  dfs(rs[u] , x) ;
        else  rs[u] = x ;
    }
}
void dfs2(int u , int x , int dep)
{
    if(x < u)
    {
        if(ls[u] != 0)  dfs2(ls[u] , x , dep + 1) ;
        else  printf("%d\n" , dep + 1) ;
    }
    else
    {
        if(rs[u] != 0)  dfs2(rs[u] , x , dep + 1) ;
        else  printf("%d\n" , dep + 1) ;
    }
}
int main() 
{
    scanf("%d" , &n) ;
    for(int i = 1 ; i <= n * 2 ; i ++)  scanf("%d" , &p[i]) ;
    rt = p[1] ;
    for(int i = 2 ; i <= n ; i ++)  dfs(rt , p[i]) ;
    for(int i = n + 1 ; i <= n * 2 ; i ++)  dfs2(rt , p[i] , 1) ;

    return 0 ;
}