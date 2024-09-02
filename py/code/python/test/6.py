import sys

MOD = 998244353
N = 100006


def calculate_pre():
    pre = [0] * N
    pre[0] = 1
    sum_val = 1
    for i in range(1, N):
        sum_val = (sum_val * i) % MOD
        pre[i] = sum_val
    return pre


def solve(n):
    return pre[n]


if __name__ == "__main__":
    count = int(sys.stdin.readline())
    pre = calculate_pre()

    for _ in range(count):
        n = int(sys.stdin.readline())
        result = solve(n)
        sys.stdout.write(str(result) + '\n')
