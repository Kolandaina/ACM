/**   int128 输出流自定义
 *    2023-03-20: https://codeforces.com/contest/1806/submission/198413531
**/
using i128 = __int128;

std::ostream &operator<<(std::ostream &os, i128 n) {
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}