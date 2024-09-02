#include <iostream>
#include <cstdio>
#include <cmath>

#define max(a, b) a > b ? a : b
using namespace std;
const double Pi = acos(-1.0);

struct Complex
{
    double x, y;

    Complex(double _x = 0, double _y = 0)
    {
        x = _x, y = _y;
    }
};

Complex operator+(const Complex &a, const Complex &b)
{
    return Complex(a.x + b.x, a.y + b.y);
}

Complex operator-(const Complex &a, const Complex &b)
{
    return Complex(a.x - b.x, a.y - b.y);
}

Complex operator*(const Complex &a, const Complex &b)
{
    return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

const int M = 1e6 + 6;
int ans, limit, tot, n, m;
int r[M], B[M];
Complex A[M], cnt[M];

inline void swap(Complex &a, Complex &b)
{
    Complex tmp = a;
    a = b, b = tmp;
}

void FFT(Complex *A, int type)
{
    for (int i = 0; i < limit; i++)
        if (i < r[i])
            swap(A[i], A[r[i]]);
    for (int mid = 1; mid < limit; mid <<= 1)
    {
        Complex Wn(cos(Pi / mid), type * sin(Pi / mid));
        for (int R = mid << 1, j = 0; j < limit; j += R)
        {
            Complex w(1, 0);
            for (int k = 0; k < mid; k++, w = w * Wn)
            {
                Complex x = A[j + k], y = w * A[j + mid + k];
                A[j + k] = x + y;
                A[j + mid + k] = x - y;
            }
        }
    }
}

inline void init()
{
    for (int i = 0; i < limit; i++)
        A[i].x = A[i].y = r[i] = 0;
    ans = 0;
    limit = 1;
    tot = 0;
}

signed main()
{
    while (cin >> n >> m)
    {

        init();
        int N = 0;
        A[0].x = 1;
        cnt[0].x = 1;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            A[x].x = 1;
            cnt[x].x = 1;
            N = max(N, x);
        }

        for (int i = 1; i <= m; i++)
            cin >> B[i];
        while (limit <= (N << 1))
            limit <<= 1, tot++;
        for (int i = 0; i < limit; i++)
            r[i] = (r[i >> 1] >> 1) | ((i & 1) << (tot - 1));
        FFT(A, 1);
        for (int i = 0; i <= limit; i++)
            A[i] = A[i] * A[i];
        FFT(A, -1);
        for (int i = 1; i <= m; i++)
        {
            if ((int)(A[B[i]].x / limit + 0.5))
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}