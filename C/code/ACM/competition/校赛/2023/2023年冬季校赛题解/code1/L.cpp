#include <bits/stdc++.h>

std::string p[4] = {"Fire!", "Ice!", "Water!", "Thunder!"};

int main() {
    std::string s, t;

    int res = 0;

    for (int i = 0; i < 3; i++) {
        std::cin >> s;
        if (t.empty()) {
            t = s;
            res += 100;
        }
        else {
            if (t == p[0] && s == p[2]) { // 火对水
                res += 200;
                t.clear();
            }
            else if (t == p[2] && s == p[0]) { // 水对火
                res += 150;
                t.clear();
            }
            else if (t == p[0] && s == p[1]) { // 火对冰
                res += 150;
                t.clear();
            }
            else if (t == p[1] && s == p[0]) { // 冰对火
                res += 200;
                t.clear();
            }
            else if ((t == p[0] && s == p[3]) || (t == p[3] && s == p[0])) { // 火对雷或雷对火
                res += 150;
                t.clear();
            }
            else if ((t == p[1] && s == p[3]) || (t == p[3] && s == p[1])) { // 雷对冰或冰对雷
                res += 100;
                t.clear();
            }
            else if ((t == p[2] && s == p[3]) || (t == p[3] && s == p[2])) { // 雷对水或水对雷
                res += 100;
                if (i == 1) res += 100;
                t.clear();
            }
            else if ((t == p[1] && s == p[2]) || (t == p[2] && s == p[1])) { // 冰对水或水对冰
                res += 100;
                t.clear();
            }
            else {
                res += 100;
                t = s;
            }
        }
    }

    std::cout << res;

    return 0;
}