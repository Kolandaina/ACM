#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string, string> s;
    char str[20], a[10], b[10];
    while (gets(str) && str[0] != '\0')
    {
        sscanf(str, "%s%s", a, b);
        s[b] = a;
    }
    while (cin >> str)
    {
        if (s[str].size())
            cout << s[str] << endl;
        else
            cout << "eh" << endl;
    }
    return 0;
}