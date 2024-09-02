#include <bits/stdc++.h>
using namespace std;
const int M = 1e6;
const int N = 128;
int trie_cnt = 1;
int trie[N * M];
bool end_word[N * M];
void insert(string m)
{
    int p = 0;
    for (int i = 0; i < m.length(); i++)
    {
        if (!trie[p * N])
        {
            trie[p * N] = ++trie_cnt;
        }
        p = trie[p * N];
    }
    end_word[p] = true;
}
bool find(string m)
{
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
    int m;
    cin >> m;
    while (m--)
    {
        string s;
        cin >> s;
        if (find(s))
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << "WRONG" << endl;
        }
    }
}
// #include <bits/stdc++.h>
// using namespace std;
// map<string, int> mp;
// int main()
// {
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         string s;
//         cin >> s;
//         mp[s] = 1;
//     }
//     int m;
//     cin >> m;
//     while (m--)
//     {
//         string s;
//         cin >> s;
//         if (mp[s] == 1)
//         {
//             cout << "OK" << endl;
//             mp[s] = 2;
//         }
//         else if (mp[s] == 2)
//         {
//             cout << "REPEAT" << endl;
//         }
//         else
//         {
//             cout << "WRONG" << endl;
//         }
//     }
//     return 0;
// }