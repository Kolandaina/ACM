#include <bits/stdc++.h>
using namespace std;
int k;
int temp;
void node(int n)
{
    int a = n / 10000;
    int b = n / 1000 % 10;
    int c = n / 100 % 100 % 10;
    int d = n / 10 % 1000 % 100 % 10;
    int e = n % 10000 % 1000 % 100 % 10;
    int sub1 = a * 100 + b * 10 + c;
    int sub2 = b * 100 + c * 10 + d;
    int sub3 = c * 100 + d * 10 + e;
    if (sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0)
    {
        cout << n << endl;
        temp = 1;
    }
}
int main()
{
    cin >> k;
    for (int i = 10000; i <= 30000; i++)
    {
        node(i);
    }
    if (temp == 0)
        cout << "No";
}