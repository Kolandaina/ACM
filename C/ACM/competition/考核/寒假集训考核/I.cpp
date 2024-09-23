// #include<bits/stdc++.h>
// using namespace std;
// int vis[100];
// int main()
// {
//     int n,m;
//     char a[1000];
//     cin>>n>>m;
//     for(int i=0;i<m;i++) cin>>a[i];
//     for(int i=0;i<m;i++)
//     {
//         if(vis[a[i]]==0) vis[a[i]]=1;
//     }
//     for(int i=m;i>0;i--)
//     {
//         if(vis[a[i]]==0) vis[a[i]]=2;
//     }
//     int s=0;
// }
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> k >> n;
    int n1 = 0;
    string s;
    cin >> s;
    map<char, int> q, p;
    for (int i = 0; i < n; i++)
    {
        q[s[i]]++;
    }
    int u = 0;
    for (int i = 0; i < n; i++)
    {
        if (!p[s[i]])
            n1++;
        q[s[i]]--;
        p[s[i]]++;
        if (n1 > k)
            u = 1;
        if (q[s[i]] == 0)
            n1--;
    }
    if (u)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}