import java.io.*;
import java.util.*;

public class subway
{
    public static void main(String[] args) throws IOException
    {
        boolean isLocal= System.getProperty("ONLINE_JUDGE") == null;
        long startTime = 0;
        if (isLocal)
        {
            startTime = System.currentTimeMillis();
            System.setIn(new FileInputStream(new File("subway.in")));
        }

        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;

        new subway_Solution().Solve(in, out);

        in.close();
        out.close();
        
        if (isLocal)
        {
            System.err.println("program exited after: " + (System.currentTimeMillis() - startTime) + "ms");
        }        
    }
}


class subway_Solution
{
    public int gcd(int a, int b)
    {
        return (b > 0) ? gcd(b,a % b) : a;
    }

    public void Solve(Scanner in, PrintStream out)
    {

        int n = in.nextInt();

        var l = new int[n];
        for (int i = 0; i <= n - 1; ++i) l[i] = in.nextInt();

        var c = new int[n];
        for (int i = 0; i <= n - 1; ++i) c[i] = in.nextInt();

        var f = new HashMap<Integer, Integer>();

        for (int i = 0; i <= n - 1; ++i)
        {
            if (f.containsKey(l[i]) ) f.put(l[i], Math.min(f.get(l[i]), c[i]));
            else                      f.put(l[i], c[i]);

            var f2 = new HashMap<Integer, Integer>();
            f2.putAll(f);
            int curr=i;
            f.forEach((key,val)->
            {
                int nxt = gcd(key, l[curr]);

                if (f2.containsKey(nxt))    f2.put(nxt, Math.min(f2.get(nxt), val + c[curr]));
                else                        f2.put(nxt, val + c[curr]);
            });


            f.clear();
            f.putAll(f2);
        }


        if (f.containsKey(1)) out.println(f.get(1));
        else                  out.println(-1);
    }
}


