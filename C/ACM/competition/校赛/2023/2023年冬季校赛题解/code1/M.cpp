#include <bits/stdc++.h>

void solved () {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> p(10 + 1);
    p[0] = "0";
    for(int i = 1; i <= 10; i++){
        for(auto j : p[i - 1]){
            if(j == '0') p[i] += "01";
            else p[i] += "10";
        }
    }

    for(int i = 0; i < n; i++) std::cout << p[10][i];
    std::cout << '\n';
}

int main() {
    int t = 1;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
        solved ();

    return 0;
}