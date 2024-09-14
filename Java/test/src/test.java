import java.util.Scanner;

public class test {
    public static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n + 1];
        int[] b = new int[m + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 1; i <= m; i++) {
            b[i] = sc.nextInt();
        }
        if (n == 1) {
            System.out.println(a[1] + b[1]);
            return;
        }

    }

    public static void main(String[] args) {
        int t = 1;
//        Scanner sc = new Scanner(System.in);
//        t=sc.nextInt();
        while (t > 0) {
            solve();
            t--;
        }
    }
}
