#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool check(vector<int> &a, int k, int target, int start, int end)
{
    if (k == 1)
        return true;
    int curXor = 0;
    for (int i = start; i <= end; ++i)
    {
        curXor ^= a[i];
        if (curXor == target && check(a, k - 1, target, i + 1, end))
        {
            return true;
        }
    }
    return false;
}

bool canDivide(vector<int> &a, int k)
{
    int sum = 0;
    for (int num : a)
    {
        sum ^= num;
    }

    if (sum % k != 0)
    {
        return false;
    }

    int target = sum / k;
    return check(a, k, target, 0, a.size() - 1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    if (canDivide(a, k))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
