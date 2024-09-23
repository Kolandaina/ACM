#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1000005;
int n, k;
struct node
{
    int v, id;
} a[N];
deque<node> qmin, qmax;
inline void slove()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].v, a[i].id = i;
    for (int i = 1; i <= n; i++)
    {
        while (!qmin.empty() && qmin.back().v >= a[i].v)
            qmin.pop_back();
        qmin.push_back(a[i]);
        if (qmin.front().id == i - k)
            qmin.pop_front();
        if (i >= k)
            cout << qmin.front().v << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        while (!qmax.empty() && qmax.back().v <= a[i].v)
            qmax.pop_back();
        qmax.push_back(a[i]);
        if (qmax.front().id == i - k)
            qmax.pop_front();
        if (i >= k)
            cout << qmax.front().v << " ";
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}
/*
#include <iostream>
#include <deque>
#include <vector>
std::vector<int> slidingWindowMax(const std::vector<int> &nums, int k)
{
    std::vector<int> result;
    std::deque<int> dq;
    int len = nums.size();
    for (int i = 0; i < len; ++i)
    {
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
            if (i - dq.front() >= k - 1)
            {
                dq.pop_front();
            }
        }
    }
    return result;
}
std::vector<int> slidingWindowMin(const std::vector<int> &nums, int k)
{
    std::vector<int> result;
    std::deque<int> dq;
    int len = nums.size();
    for (int i = 0; i < len; ++i)
    {
        while (!dq.empty() && nums[i] <= nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
            if (i - dq.front() >= k - 1)
            {
                dq.pop_front();
            }
        }
    }
    return result;
}
int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> nums[i];
    }
    std::vector<int> maxResult = slidingWindowMax(nums, k);
    std::vector<int> minResult = slidingWindowMin(nums, k);
    int d = 0;
    for (int num : minResult)
    {
        d++;
        if (d == 1)
            continue;
        std::cout << num << " ";
    }
    std::cout << std::endl;
    d = 0;
    for (int num : maxResult)
    {
        d++;
        if (d == 1)
            continue;
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/