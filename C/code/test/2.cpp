#include <iostream>
#include<vector>
#include<deque>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m = 12;
        int a, b;
        int now[4] = {0, 2, 3, 4};
        deque<int> v[20];
        for (int i = 1; i <= 3; i++)
            v[now[i]].push_back(i);
        while (m--) {
            cin >> a >> b;
            int flag = 0;
            deque<int> &t = v[now[a]];
            deque<int> u;
            while (t.back() != a)
                u.push_front(t.back()), now[t.back()] += b, t.pop_back();
            u.push_front(t.back()), now[t.back()] += b, t.pop_back();
            while (!v[now[a]].empty()) {
                u.push_front(v[now[a]].back());
                v[now[a]].pop_back();
            }
            v[now[a]] = u;
        }
        if (v[9].size() == 3) cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}
