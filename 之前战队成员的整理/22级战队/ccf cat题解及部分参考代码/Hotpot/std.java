import java.util.Scanner;

public class std {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = 1, b = 1;
        for (int i = 1; i <= n; i++) {
            int t = a;
            a = b;
            b = (t + b) % 1000000007;
        }
        System.out.println((long)b * b % 1000000007);
    }
}