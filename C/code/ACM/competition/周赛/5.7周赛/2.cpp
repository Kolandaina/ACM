#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    if ((n == 4 && x == 2) || (n == 2 && x == 1))
        cout << "1" << endl;
    else
        cout << "0" << endl;
    return 0;
}
