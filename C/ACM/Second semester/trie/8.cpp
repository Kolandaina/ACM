#include <iostream>
#include <vector>
const int prime = 31;
const int MOD = 1e8 + 7;

inline long long calculateHash(const std::string &str)
{
    long long hashValue = 0;
    long long p = 1;

    for (char ch : str)
    {
        hashValue = (hashValue + (ch - 'a' + 1) * p) % MOD;
        p = (p * prime) % MOD;
    }
    return hashValue;
}

inline bool areEqual(const std::string &str1, const std::string &str2, int l1, int r1, int l2, int r2)
{
    int len1 = r1 - l1 + 1;
    int len2 = r2 - l2 + 1;

    if (len1 != len2)
    {
        return false;
    }

    long long hash1 = calculateHash(str1.substr(l1, len1));
    long long hash2 = calculateHash(str2.substr(l2, len2));

    return hash1 == hash2;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    std::string str;
    std::cin >> str;

    for (int i = 0; i < m; i++)
    {
        int l1, r1, l2, r2;
        std::cin >> l1 >> r1 >> l2 >> r2;

        if (areEqual(str, str, l1 - 1, r1 - 1, l2 - 1, r2 - 1))
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }

    return 0;
}
