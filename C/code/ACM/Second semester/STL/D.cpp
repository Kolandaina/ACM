#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int i, n;
    while (cin >> n && n != 0)
    {
        while (1)
        {
            stack<int> v;
            int a[1010], k = 1;
            cin >> a[1];
            if (a[1] == 0)
                break;
            for (int i = 2; i <= n; i++)
            {
                cin >> a[i];
            }
            for (int i = 1; i <= n; i++)
            {
                while (k <= a[i])
                {
                    v.push(k);
                    k++;
                }
                if (v.top() == a[i])
                    v.pop();
            }
            if (v.empty())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}