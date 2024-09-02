#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
char s1[N], s2[N];
struct suffixautomaton {
    int sz = 1;
    int last = 1;
    int trans[2 * N][27], link[2 * N], siz[2 * N][2], lst[2 * N];
    int head[2 * N], nxt[2 * N], ver[2 * N], tot = 1;
    int ans = 0;
    inline void add(int x, int y) {
        ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
    }
    void insert(int val, int o) {
        int now = ++sz;
        lst[now] = lst[last] + 1;
        int p = last;
        siz[now][o]++;
        while (!trans[p][val]) {
            trans[p][val] = now;
            p = link[p];
        }
        if (p == 0) {
            link[last = now] = 1;
            return;
        }
        int q = trans[p][val];
        if (lst[q] == lst[p] + 1) {
            link[now] = q;
        } else {
            int clone = ++sz;
            lst[clone] = lst[p] + 1;
            link[clone] = link[q];
            memcpy(trans[clone], trans[q], sizeof(trans[q]));
            while (trans[p][val] == q) {
                trans[p][val] = clone;
                p = link[p];
            }
            link[now] = link[q] = clone;
        }
        last = now;
    }
    inline void build() {
        for (int i = 2; i <= sz; i++)
            add(link[i], i);
    }
    void dfs(int x) {
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            dfs(y);
            siz[x][0] += siz[y][0], siz[x][1] += siz[y][1];
        }
        if (siz[x][0] && siz[x][1]) ans = max(ans, lst[x]);
    }
} sam;
int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    for (int i = 0; i < len1; i++)
        sam.insert(s1[i] - 'a', 0);
    sam.insert(26, 0);
    for (int i = 0; i < len2; i++)
        sam.insert(s2[i] - 'a', 1);
    sam.build();
    sam.dfs(1);
    printf("%d\n", sam.ans);
}