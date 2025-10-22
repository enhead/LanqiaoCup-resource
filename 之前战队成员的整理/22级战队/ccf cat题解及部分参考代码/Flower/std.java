import java.util.Arrays;
import java.util.Scanner;
public class flower {
    static int n , k ;
    static int tmp ;
    private static int[] t = new int[100000 + 10] ;
    private static int[] v = new int[100000 + 10] ;
    private static int[] p = new int[100000 + 10] ;
    private static int[] heap = new int[100000 + 10] ;
    static int siz = 0 ;
    private static void down(int x)
    {
        int t = x;      //t：存三个中最小的结点
        if(2 * x <= siz && heap[t] > heap[2 * x])      t = 2 * x;		//比较左结点
        if(2 * x + 1<= siz && heap[t] > heap[2 * x + 1])      t = 2 * x + 1;	//比较右结点
        
        //如果t == x那么这个子堆往下的所有子堆都调整好，退出
        
        if(t != x){
            tmp = heap[x] ;
            heap[x] = heap[t] ;
            heap[t] = tmp ;
            down(t);
        }
    }
    private static void up(int u)
    {
        while(u/2 > 0 && heap[u/2]>heap[u])
        {
            tmp = heap[u / 2] ;
            heap[u / 2] = heap[u] ;
            heap[u] = tmp ;
            u/=2;
        }
    }
    private static int pop()
    {
        int x = heap[1] ;
        heap[1] = heap[siz --];    //删除根
        down(1) ;
        return x ;
    }
    public static void main(String[] args) {
        Arrays.fill(t, 0);
        Arrays.fill(v, 0);
        Arrays.fill(p, 0);
        Arrays.fill(heap, 0);
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();
        for(int i = 1 ; i <= n ; i ++)  t[i] = scanner.nextInt();
        for(int i = 1 ; i <= n ; i ++)  v[i] = scanner.nextInt();
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
        System.out.println(s) ;       
    }
}