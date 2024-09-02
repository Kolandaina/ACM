#include <bits/stdc++.h> // for AtCoder
using namespace std;
int main()
{
    string S, T;
    cin >> S >> T;
    map<char, int> Smap, Tmap;
    for (auto &s : S)
    {
        Smap[s]++;
    }
    for (auto &t : T)
    {
        Tmap[t]++;
    }
    for (char i : S)
    {
        if (i == '@')
            continue;
        if (Tmap[i] == 0)
        {
            if ((i == 'a' || i == 't' || i == 'c' || i == 'o' || i == 'd' || i == 'e' || i == 'r') && Tmap['@'] > 0)
            {
                Tmap['@']--;
            }
            else
            {
                cout << "No" << endl;
                return 0;
            }
        }
        else
        {
            Tmap[i]--;
        }
    }

    for (char i : T)
    {
        if (i == '@')
            continue;
        if (Smap[i] == 0)
        {
            if ((i == 'a' || i == 't' || i == 'c' || i == 'o' || i == 'd' || i == 'e' || i == 'r') && Smap['@'] > 0)
            {
                Smap['@']--;
            }
            else
            {
                cout << "No" << endl;
                return 0;
            }
        }
        else
        {
            Smap[i]--;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
