#include <bits/stdc++.h>
std::string merge(int32_t a, int32_t b, int32_t c)
{
    std::string s = std::to_string(a) + ":";
    if (b < 10)
        s += "0";
    s += std::to_string(b) + ":";
    if (c < 10)
        s += "0";
    s += std::to_string(c);
    return s;
}
void solve()
{
    std::set<std::string> v;
    std::map<int, bool> m;
    m[1] = m[3] = m[5] = m[7] = m[8] = m[10] = m[12] = true;
    for (int32_t i = 0; i < 10; i++)
    {
        std::string e = "928" + std::to_string(i);
        for (int32_t j = 1; j < 13; j++)
        {
            int32_t o = std::stoi(e);
            if (j == 2)
            {
                if ((o % 4 == 0 && o % 100 != 0) || o % 400 == 0)
                {
                    for (int32_t k = 1; k < 30; k++)
                    {
                        v.insert(merge(o, j, k));
                    }
                }
                else
                {
                    for (int32_t k = 1; k < 29; k++)
                    {
                        v.insert(merge(o, j, k));
                    }
                }
            }
            else if (m[j])
            {
                for (int32_t k = 1; k < 32; k++)
                {
                    v.insert(merge(o, j, k));
                }
            }
            else
            {
                for (int32_t k = 1; k < 31; k++)
                {
                    v.insert(merge(o, j, k));
                }
            }
        }
    }
    for (int32_t i = 2; i < 10; i++)
    {
        std::string e = std::to_string(i) + "928";
        for (int32_t j = 1; j < 13; j++)
        {
            int32_t o = std::stoi(e);
            if (j == 2)
            {
                if ((o % 4 == 0 && o % 100 != 0) || o % 400 == 0)
                {
                    for (int32_t k = 1; k < 30; k++)
                    {
                        v.insert(merge(o, j, k));
                    }
                }
                else
                {
                    for (int32_t k = 1; k < 29; k++)
                    {
                        v.insert(merge(o, j, k));
                    }
                }
            }
            else if (m[j])
            {
                for (int32_t k = 1; k < 32; k++)
                {
                    v.insert(merge(o, j, k));
                }
            }
            else
            {
                for (int32_t k = 1; k < 31; k++)
                {
                    v.insert(merge(o, j, k));
                }
            }
        }
    }
    for (int32_t i = 2000; i < 10000; i++)
    {
        v.insert(merge(i, 9, 28));
    }
    std::vector<std::string> arr(v.size() + 1);
    int32_t n = 0;
    for (auto e : v)
    {
        arr[n] = e;
        n++;
    }
    arr[n] = "9999:99:99";
    int32_t t;
    std::cin >> t;
    while (t--)
    {
        std::string a, b;
        std::cin >> a >> b;
        std::cout << std::upper_bound(arr.begin(), arr.end(), b) - std::lower_bound(arr.begin(), arr.end(), a) << "\n";
    }
}
int32_t main()
{
    solve();
    return 0;
}
