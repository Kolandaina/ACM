import java.util.Scanner;

public class test {
    public static void solve() {
        Scanner sc = new Scanner(System.in);
        int maximun_value, maximum_index, search_cost, n;
        int[] arr = new int[10];
        maximun_value = -1;
        maximum_index = -1;
        search_cost = 0;
        n = arr.length();
        for (int i = 0; i < n; i++) {
            if (maximun_value < arr[i]) {
                maximun_value = arr[i];
                maximum_index = i;
                search_cost = search_cost + 1;
            }
        }
        System.out.println(maximum_index);

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
