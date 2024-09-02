import numpy as np


def fill(n):
    a = np.zeros((n, n))
    r, c = n // 2, n - 1
    for i in range(n * n, 0, -1):
        a[r][c] = i
        r = (r + 1) % n
        c = (c + 1) % n
        if a[r][c] != 0:
            r = (r - 1) % n
            c = (c - 2) % n
    return a


def display(n):
    print(fill(n))


if __name__ == "__main__":
    x = int(input())
    display(x)
