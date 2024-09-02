#include <iostream>
#include <map>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
map<int, int> r, b;
int main()
{
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        char add;
        cin >> add;
        if (add == 'B')
            b[a[i]]++, cnt += r[a[i]];
        else
            r[a[i]]++, cnt += b[a[i]];
    }
    cout << cnt << endl;
}
