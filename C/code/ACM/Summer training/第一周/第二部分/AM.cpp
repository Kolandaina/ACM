#include <iostream>
const int N = 1e6;
int vis[N], n, i = 1;
int main()
{
    std::cin >> n;
    vis[n] = 1;
    for (;; i++)
    {
        n = (n % 100000 / 10) * (n % 100000 / 10) % N;
        if (vis[n])
            break;
        vis[n] = i;
    }
    std::cout << n << " " << i - vis[n] << " " << i << "\n";
    return 0;
}