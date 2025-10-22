import java.util.Arrays;
import java.util.Scanner;
public class tree {
    private static int[] p = new int[4000 + 10] ;
    private static int[] ls = new int[4000 + 10] ;
    private static int[] rs = new int[4000 + 10] ;
    private static void dfs(int u , int x)
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
    private static void dfs2(int u , int x , int dep)
    {
        if(x < u)
        {
            if(ls[u] != 0)  dfs2(ls[u] , x , dep + 1) ;
            else  System.out.println(dep + 1) ;
        }
        else
        {
            if(rs[u] != 0)  dfs2(rs[u] , x , dep + 1) ;
            else  System.out.println(dep + 1) ;
        }
    }
    public static void main(String[] args) {
        Arrays.fill(p, 0);
        Arrays.fill(ls, 0);
        Arrays.fill(rs, 0);
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n*2; i++) {
            p[i] = scanner.nextInt();
        }
        int rt = p[0] ;
        for(int i = 1 ; i < n ; i ++)  dfs(rt , p[i]) ;
        for(int i = n ; i < n * 2 ; i ++)  dfs2(rt , p[i] , 1) ;
    }
}