#include <bits/stdc++.h>

#include <cmath>
#include <cstdio>

#define AC 0
#define WA 1
#define ERROR -1

using namespace std;

bool check_sum_and_product(const vector<int> &arr, int n)
{
    long long sum = 0;
    long long product = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0) return false;
        product *= arr[i];
        sum += arr[i];
    }
    return sum == 0 && product == n;
}

int main(int argc, char *argv[])
{
    /*
     * argv[1]：输入文件
     * argv[2]：选手输出文件
     * exit code：返回判断结果
     */

    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "r");

    if (!fin || !fout)
    {
        return ERROR; // 文件打开失败
    }

    int t;
    if (fscanf(fin, "%d", &t) != 1)
    {
        fclose(fin);
        fclose(fout);
        return ERROR; // 输入文件读取失败
    }

    for (int i = 0; i < t; ++i)
    {
        int n;
        if (fscanf(fin, "%d", &n) != 1)
        {
            fclose(fin);
            fclose(fout);
            return ERROR; // 输入文件读取失败
        }

        if (n % 4 != 0)
        {
            char output_res[10];
            if (fscanf(fout, "%s", output_res) != 1 ||
                strcmp(output_res, "NO") != 0)
            {
                fclose(fin);
                fclose(fout);
                return WA; // 期望 NO，实际输出不同
            }
            continue;
        }

        vector<int> values(n);
        for (int j = 0; j < n; ++j)
        {
            if (fscanf(fout, "%lld", &values[j]) != 1)
            {
                fclose(fin);
                fclose(fout);
                return WA; // 读取选手输出失败
            }
        }

        if (!check_sum_and_product(values, n))
        {
            fclose(fin);
            fclose(fout);
            return WA; // 检查和与积失败
        }
    }

    fclose(fin);
    fclose(fout);
    return AC;
}
