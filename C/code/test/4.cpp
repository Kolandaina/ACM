#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxx 101000
char s[maxx], s1[maxx * 2];
int mp[maxx * 2];
void Manacher(int l) {
    int k = 0;
    s1[k++] = '$'; s1[k++] = '#';
    for (int i = 0; i < l; i++) {
        s1[k++] = s[i];
        s1[k++] = '#';
    }
    s1[k] = 0;
    int mx = 0, id = 0;
    for (int i = 0; i < k; i++) {
        mp[i] = mx > i ? min(mp[2 * id - i], mx - i) : 1;
        while (s1[i + mp[i]] == s1[i - mp[i]])
            mp[i]++;
        if (i + mp[i] > mx) {
            mx = i + mp[i];
            id = i;
        }
    }
}
int main() {
    while (~scanf("%s", s)) {
        int l = strlen(s);
        int ans = 0;
        Manacher(l);
        for (int i = 0; i < 2 * l + 2; i++)
            ans = max(ans, mp[i] - 1);
        cout << ans << endl;
    }
    return 0;
}
