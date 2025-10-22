#include <stdio.h>
#include <stdlib.h>
int n , k ;
int t[100000 + 10] ;
int v[100000 + 10] ;
int p[100000 + 10] ;
int heap[100000 + 10] , siz ;
void swap(int &x , int &y)
{
    int t = x ;
    x = y ;
    y = t ;
}
void down(int x){       //递归向下调整子结点
    int t = x;      //t：存三个中最小的结点
    if(2 * x <= siz && heap[t] > heap[2 * x])      t = 2 * x;		//比较左结点
    if(2 * x + 1<= siz && heap[t] > heap[2 * x + 1])      t = 2 * x + 1;	//比较右结点
    
    //如果t == x那么这个子堆往下的所有子堆都调整好，退出
    
    if(t != x){
        swap(heap[x], heap[t]);
        down(t);
    }
}
void up(int u)
{
	while(u/2&&heap[u/2]>heap[u])
	{
		swap(heap[u/2],heap[u]);
		u/=2;
	}
}
int pop()
{
    int x = heap[1] ;
    heap[1] = heap[siz --];    //删除根
    down(1) ;
    return x ;
}
int main() 
{
    scanf("%d%d" , &n , &k) ;
    for(int i = 1 ; i <= n ; i ++)  scanf("%d" , &t[i]) ;
    for(int i = 1 ; i <= n ; i ++)  scanf("%d" , &v[i]) ;
    for(int i = 1 ; i <= n ; i ++)  p[t[i]] = v[i] ;
    for(int i = 100000 ; i >= 1 ; i --)
    {
        if(p[i] == 0)  continue ;
        heap[++ siz] = p[i] ;
        up(siz) ;
        if(siz > k)
        {
            pop() ;
        }
    }
    int s = 0 ;
    while(siz > 0)  s += pop() ;
    printf("%d\n" , s) ;

    return 0 ;
}

