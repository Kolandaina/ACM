#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        string s;
        cin >> s;

        int n = s.length();
        if (n % 2 == 1 || s[0] == ')' || s[n - 1] == '(')
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;

            string regular_seq = "";
            int open_brackets = 0;

            for (char c : s)
            {
                if (c == '(')
                {
                    open_brackets++;
                }
                else
                {
                    open_brackets--;
                }

                regular_seq += c;
                if (open_brackets == 0)
                {
                    regular_seq += "()";
                }
            }

            cout << regular_seq << endl;
        }
    }

    return 0;
}
