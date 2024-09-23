#include <iostream>
#include <string>

using namespace std;

int longestPalindrome(string s)
{
    int n = s.length();
    int maxLength = 1;

    // 检查奇数长度的回文串
    for (int i = 0; i < n; i++)
    {
        int left = i, right = i;

        while (left >= 0 && right < n && s[left] == s[right])
        {
            int length = right - left + 1;
            maxLength = max(maxLength, length);
            left--;
            right++;
        }
    }
    // 检查偶数长度的回文串
    for (int i = 0; i < n - 1; i++)
    {
        int left = i, right = i + 1;

        while (left >= 0 && right < n && s[left] == s[right])
        {
            int length = right - left + 1;
            maxLength = max(maxLength, length);
            left--;
            right++;
        }
    }

    return maxLength;
}

int main()
{
    string s;
    cin >> s;

    int result = longestPalindrome(s);

    cout << result << endl;

    return 0;
}
