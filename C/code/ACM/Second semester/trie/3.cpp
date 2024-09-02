#include <bits/stdc++.h>
using namespace std;
int n, k, len1, len2;
int next1[1000001];
char s1[1000001];
char s2[1000001];
inline void get_next()
{
    int t1 = 0, t2;
    next1[0] = t2 = -1;
    while (t1 < len2)
        if (t2 == -1 || s2[t1] == s2[t2])
            next1[++t1] = ++t2;
        else
            t2 = next1[t2];
}
inline void KMP()
{
    int t1 = 0, t2 = 0;
    while (t1 < len1)
    {
        if (t2 == -1 || s1[t1] == s2[t2])
            t1++, t2++;
        else
            t2 = next1[t2];
        if (t2 == len2)
            printf("%d\n", t1 - len2 + 1), t2 = next1[t2];
    }
}
int main()
{
    scanf("%s", s1);
    scanf("%s", s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    get_next();
    KMP();
    for (int i = 1; i <= len2; ++i)
        printf("%d ", next1[i]);
    return 0;
}