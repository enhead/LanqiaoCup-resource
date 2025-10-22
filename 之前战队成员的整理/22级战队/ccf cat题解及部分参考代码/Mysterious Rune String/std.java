import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;

class SAM {
    static final int N = 200055;
    long[] cnt = new long[N << 1];
    int[][] ch = new int[N << 1][26];
    int[] fa = new int[N << 1];
    int[] l = new int[N << 1];
    int[] size = new int[N << 1];
    int[] k = new int[N << 1];
    int[] c = new int[N << 1];
    int[] pos = new int[N << 1];
    int[] belong = new int[N << 1];
    int[][] fat = new int[21][N << 1];
    int last, tot;
    void init() {
        last=tot=1;
        Arrays.fill(ch[1], 0);
    }
    void ins(int c,int id) {
        int p=last,np=++tot;last=np;l[np]=l[p]+1;
        Arrays.fill(ch[tot], 0);
        for(;p!=0&&ch[p][c]==0;p=fa[p]) ch[p][c]=np;
        if(p==0)fa[np]=1;
        else {
            int q=ch[p][c];
            if(l[p]+1==l[q])fa[np]=q;
            else {
                int nq=++tot;l[nq]=l[p]+1;
                System.arraycopy(ch[q], 0, ch[nq], 0, ch[q].length);
                fa[nq]=fa[q];fa[q]=fa[np]=nq;
                for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
            }
        }
        size[np]=1;
        pos[np]=id;
        belong[id]=np;
    }
    void build(){
        init();
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        int n=s.length();
        for(int i=1;i<=n;i++) ins(s.charAt(i-1)-'a',i);
        for(int i=1;i<=tot;i++) c[l[i]]++;
        for(int i=1;i<=tot;i++) c[i]+=c[i-1];
        for(int i=1;i<=tot;i++) k[c[l[i]]--]=i;
        for(int i=1;i<=tot;i++) c[i]=size[i]=0;

        for(int id=tot;id>1;id--) {
            int i=k[id];
            fat[0][i] = fa[i];
            pos[fa[i]]^=pos[i];
            cnt[pos[i]]=cnt[pos[i]]+l[i]-l[fa[i]];
        }
        fat[0][1]=0;
        for (int i=1;i<=20;i++)
            for (int j=1;j<=tot;j++)
                fat[i][j]=fat[i-1][fat[i-1][j]];
        int m = sc.nextInt();
        while(m-->0) {
            int L,R,id;
            L=sc.nextInt();
            R=sc.nextInt();
            id = belong[R];
            for(int i=20;i>=0;i--) {
                if(l[fat[i][id]]+1>R-L+1) {
                    id = fat[i][id];
                }
            }
            System.out.println(cnt[pos[id]]);
        }
    }
}
public class Main {
    public static void main(String[] args) {
        new SAM().build();
    }
}
