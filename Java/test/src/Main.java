import java.io.*;
import java.util.*;

public class Main {
    static final int N = 200010;
    static final long MOD = 1000000007L;
    static final long INF = Long.MAX_VALUE;

    static class DSU {
        int[] fa, p, e, f;

        DSU(int n) {
            fa = new int[n + 1];
            p = new int[n + 1];
            e = new int[n + 1];
            f = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                fa[i] = i;
                p[i] = 1;
            }
        }

        int find(int x) {
            if (fa[x] != x) {
                fa[x] = find(fa[x]);
            }
            return fa[x];
        }

        boolean merge(int x, int y) {
            if (x == y) f[find(x)] = 1;
            x = find(x);
            y = find(y);
            e[x]++;
            if (x == y) return false;
            if (x < y) {
                int temp = x;
                x = y;
                y = temp;
            }
            fa[y] = x;
            f[x] |= f[y];
            p[x] += p[y];
            e[x] += e[y];
            return true;
        }

        boolean same(int x, int y) {
            return find(x) == find(y);
        }

        boolean F(int x) {
            return f[find(x)] == 1;
        }

        int size(int x) {
            return p[find(x)];
        }

        int E(int x) {
            return e[find(x)];
        }
    }

    static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        DSU dsu = new DSU(n);
        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            dsu.merge(x, y);
        }

        boolean flag = true;
        List<Integer> cnt = new ArrayList<>();
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dsu.fa[i] == i) {
                int res = (dsu.size(i) * (dsu.size(i) - 1)) / 2;
                if (res != dsu.E(i)) {
                    flag = false;
                    ans += res - dsu.E(i);
                } else {
                    cnt.add(dsu.size(i));
                }
            }
        }

        if (flag) {
            Collections.sort(cnt);
            System.out.println(cnt.get(0) * cnt.get(1));
        } else {
            System.out.println(ans);
        }
    }

    public static void main(String[] args) throws IOException {
        solve();
    }
}
