#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
const int N = 128;
int trie_cnt = 1;
int trie[N * M];
bool end_word[N * M];
void insert(string m)
{
    int p = 0;
    for (int i = 0; i < m.length(); i++)
    {
        if (!trie[p * N + m[i]])
        {
            trie[p * N + m[i]] = trie_cnt++;
        }
        p = trie[p * N + m[i]];
    }
    end_word[p] = true;
}
int count_str()
{
    int cnt = 0;
    for (int i = 0; i < trie_cnt; i++)
    {
        if (end_word[i])
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        insert(s);
    }
    cout << count_str() << endl;
    return 0;
}