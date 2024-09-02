/*
https://codeforces.com/problemset/problem/515/C


在数学王国的边缘，有一座神秘的数学塔，塔内住着两位数学大师，分别是zks和zzh。他们被数学王国的国王委托解决一道神秘而复杂的数学难题。
zks是数学塔的主人，他是一个精通数字阶乘的数学家。zzh则是一位年轻而聪明的学徒，他时刻渴望学到更多的数学奥秘。
一天，zzh满怀兴奋地走进了数学塔，zks正在专注地研究数字阶乘的奇妙之处。
zzh好奇地问道：“zks先生，数字阶乘真的有那么神奇吗？”
zks微笑着回答：“zzh，数字阶乘是数学中的一项重要工具，它蕴含着无限的数学奥秘。每个数字都有着独特的质数组合，而阶乘则是这些数字的乘积。”
zzh被深深吸引，随口问：“那么，有没有什么特殊的数字 x，它的阶乘乘积等于某个数 a
的阶乘呢？” zks眼中闪过一丝兴奋：“有，确实有这样的数字 x，但它不能包含数字 0 和
1，而且我们还要找到满足条件的最大整数 x。”
zzh思考了一下，突然灵光一现：“如果我能找到一个由 n 个数字组成的十进制数
a，其中至少有一个数字大于 1，然后找到一个 x，使得 F(x) 等于
F(a)，（其中F(x)为正整数 x 的数字阶乘的乘积），那不就是我们要找的吗？”
zks点头称赞：“不错，zzh！这就是我们的任务。现在，你要做的是找到这个神秘的数字
x，并确保它是满足条件的最大整数，同时十进制表示中不能包含零和一。”
zzh接受了这个挑战，心中燃起对数学的热情。在数学塔中，两位数学家开始了一场充满智慧和奇迹的数学冒险。



样例输入：4
        1234
样例输出：33222
提示：F(1234) = 1 * 1*2 * 1*2*3 * 1*2*3*4 = F(33222) = 1*2*3 * 1*2*3 * 1*2 * 1*2
* 1*2 Input
4
1234
Output
33222

Input
3
555
Output
555

Input
15
012345781234578
Output
7777553333222222222222

Input
1
8
Output
7222

Input
10
1413472614
Output
75333332222222

Input
8
68931246
Output
77553333332222222

Input
7
4424368
Output
75333332222222222

Input
6
576825
Output
7755532222

Input
5
97715
Output
7775332

Input
3
915
Output
75332

Input
2
26
Output
532

Input
1
4
Output
322

Input
15
028745260720699
Output
7777755533333332222222222

Input
13
5761790121605
Output
7775555333322

Input
10
3312667105
Output
755533332

Input
1
7
Output
7

Input
15
989898989898989
Output
777777777777777333333333333333322222222222222222222222222222

Input
15
000000000000007
Output
7

Input
15
999999999999990
Output
77777777777777333333333333333333333333333322222222222222

Input
2
09
Output
7332

Input
12
836544897832
Output
77777553333333222222222222222

*/
#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
std::string ch[10] = {"", "", "2", "3", "223", "5", "53", "7", "7222", "7332"};
inline void slove()
{
    int n;
    std::cin >> n;
    std::string s, ans;
    std::cin >> s;
    for (int i = 0; i < n; i++) ans += ch[s[i] - '0'];
    std::sort(ans.begin(), ans.end());
    std::reverse(ans.begin(), ans.end());
    std::cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}