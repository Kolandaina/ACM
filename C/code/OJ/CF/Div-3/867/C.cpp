#include <bits/stdc++.h>
using namespace std;

namespace io
{
    template <typename First, typename Second>
    ostream &operator<<(ostream &os, const pair<First, Second> &p)
    {
        return os << p.first << " " << p.second;
    }
    template <typename First, typename Second>
    ostream &operator<<(ostream &os, const map<First, Second> &mp)
    {
        for (auto it : mp)
        {
            os << it << endl;
        }
        return os;
    }
    template <typename First>
    ostream &operator<<(ostream &os, const vector<First> &v)
    {
        bool space = false;
        for (First x : v)
        {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }
    template <typename First>
    ostream &operator<<(ostream &os, const set<First> &st)
    {
        bool space = false;
        for (First x : st)
        {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }
    template <typename First>
    ostream &operator<<(ostream &os, const multiset<First> &st)
    {
        bool space = false;
        for (First x : st)
        {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }
    template <typename First, typename Second>
    istream &operator>>(istream &is, pair<First, Second> &p)
    {
        return is >> p.first >> p.second;
    }
    template <typename First>
    istream &operator>>(istream &is, vector<First> &v)
    {
        for (First &x : v)
        {
            is >> x;
        }
        return is;
    }
    int fastread()
    {
        char c;
        int d = 1, x = 0;
        do
            c = getchar();
        while (c == ' ' || c == '\n');
        if (c == '-')
            c = getchar(), d = -1;
        while (isdigit(c))
        {
            x = x * 10 + c - '0';
            c = getchar();
        }
        return d * x;
    }
    static bool sep = false;
    using std::to_string;
    string to_string(bool x)
    {
        return (x ? "true" : "false");
    }
    string to_string(const string &s)
    {
        return "\"" + s + "\"";
    }
    string to_string(const char *s)
    {
        return "\"" + string(s) + "\"";
    }
    string to_string(const char &c)
    {
        string s;
        s += c;
        return "\'" + s + "\'";
    }
    template <typename Type>
    string to_string(vector<Type>);
    template <typename First, typename Second>
    string to_string(pair<First, Second>);
    template <typename Collection>
    string to_string(Collection);
    template <typename First, typename Second>
    string to_string(pair<First, Second> p)
    {
        return "{" + to_string(p.first) + ", " + to_string(p.second) + "}";
    }
    template <typename Type>
    string to_string(vector<Type> v)
    {
        bool sep = false;
        string s = "[";
        for (Type x : v)
        {
            if (sep)
                s += ", ";
            sep = true;
            s += to_string(x);
        }
        s += "]";
        return s;
    }
    template <typename Collection>
    string to_string(Collection collection)
    {
        bool sep = false;
        string s = "{";
        for (auto x : collection)
        {
            if (sep)
                s += ", ";
            sep = true;
            s += to_string(x);
        }
        s += "}";
        return s;
    }
    void print()
    {
        cerr << endl;
        sep = false;
    }
    template <typename First, typename... Other>
    void print(First first, Other... other)
    {
        if (sep)
            cerr << " | ";
        sep = true;
        cerr << to_string(first);
        print(other...);
    }
}
using namespace io;

namespace utils
{
    class Range
    {
    private:
        const int start;
        const int stop;
        const int step;

    public:
        class iterator
        {
        private:
            int value;
            const int step;
            const int boundary;
            const bool sign;

        public:
            typedef std::forward_iterator_tag iterator_category;
            typedef int &reference;
            typedef int *pointer;
            iterator(int value, int step, int boundary) : value(value), step(step), boundary(boundary), sign(step > 0) {}
            iterator operator++()
            {
                value += step;
                return *this;
            }
            reference operator*()
            {
                return value;
            }
            // const pointer operator->()
            // {
            // 	return &value;
            // }
            bool operator==(const iterator &rhs)
            {
                return sign ? (value >= rhs.value && value > boundary) : (value <= rhs.value && value < boundary);
            }
            bool operator!=(const iterator &rhs)
            {
                return sign ? (value < rhs.value && value >= boundary) : (value > rhs.value && value <= boundary);
            }
        };
        Range(const int &start, const int &stop, const int &step) : start(start), stop(stop), step(step) {}
        iterator begin()
            const
        {
            return iterator(start, step, start);
        }
        iterator end()
            const
        {
            return iterator(stop, step, start);
        }
    };
    Range range(const int &stop)
    {
        return Range(0, stop, 1);
    }
    Range range(const int &start, const int &stop)
    {
        return Range(start, stop, 1);
    }
    Range range(const int &start, const int &stop, const int &step)
    {
        return Range(start, stop, step);
    }
    template <typename T>
    auto max(T a, T b, char c)
    {
        return max(a, max(b, c));
    }
    template <typename T>
    auto max(T a, T b, unsigned char c)
    {
        return max(a, max(b, c));
    }
    template <typename T>
    auto max(T a, T b, int32_t c)
    {
        return max(a, max(b, c));
    }
    template <typename T>
    auto max(T a, T b, unsigned int c)
    {
        return max(a, max(b, c));
    }
    template <typename T>
    auto max(T a, T b, float c)
    {
        return max(a, max(b, c));
    }
    template <typename T>
    auto max(T a, T b, double c)
    {
        return max(a, max(b, c));
    }
    template <typename T>
    auto max(T a, T b, int64_t c)
    {
        return max(a, max(b, c));
    }
    template <typename T>
    auto max(T a, T b, unsigned long long c)
    {
        return max(a, max(b, c));
    }
    template <typename T>
    inline T max(T t)
    {
        return t;
    }
    template <typename First, typename... Others>
    inline auto max(First first, Others... others)
    {
        auto result = max(others...);
        return result > first ? result : first;
    }
    template <typename T>
    inline T min(T t) { return t; }
    template <typename First, typename... Others>
    inline auto min(First first, Others... others)
    {
        auto result = min(others...);
        return result < first ? result : first;
    }
    template <typename T1, typename T2>
    inline void updmax(T1 &a, T2 b)
    {
        a = a > b ? a : b;
    }
    template <typename T1, typename T2>
    inline void updmin(T1 &a, T2 b)
    {
        a = a < b ? a : b;
    }
    template <typename T1, typename T2>
    inline bool chkmax(T1 &a, T2 b)
    {
        if (a < b)
        {
            a = b;
            return true;
        }
        return false;
    }
    template <typename T1, typename T2>
    inline bool chkmin(T1 &a, T2 b)
    {
        if (a > b)
        {
            a = b;
            return true;
        }
        return false;
    }
    constexpr long long operator"" _E(unsigned long long n)
    {
        long long p = 1, a = 10;
        int len = n;
        for (int i = 0; i < len; i++)
            p *= a;
        return p;
    }
    long double operator"" _deg(long double deg)
    {
        long double PI = acos(-1);
        return deg * PI / 180;
    }
    random_device rd;
    mt19937 mt(rd());
    template <typename T>
    T rand(T l, T r)
    {
        uniform_int_distribution<T> dist(l, r);
        return dist(mt);
    };
}
using namespace utils;

template <typename T>
class nparray
{
private:
    T *_data = nullptr, *_max = nullptr, *_min = nullptr, *_sum = nullptr;
    size_t _size;

public:
    nparray() {}
    nparray(size_t size)
    {
        __init(size);
    }
    void __init(size_t size)
    {
        _size = size;
        _data = new T[size];
        fill(0);
    }
    T sum()
    {
        return std::accumulate(_data, _data + _size, 0);
    }
    T sum(size_t stop)
    {
        return sum(0, stop);
    }
    T sum(size_t start, size_t stop)
    {
        if (_sum == nullptr)
            __sumrecalc();
        T sum_ = _sum[stop];
        if (start)
            sum_ -= _sum[start - 1];
        return sum_;
    }
    T sum(size_t start, size_t stop, size_t step)
    {
        T sum_ = 0;
        for (size_t i = start; i < stop; i += step)
        {
            sum_ += _data[i];
        }
        return sum_;
    }

    T max()
    {
        return *std::max_element(_data, _data + this->_size);
    }
    T max(size_t index)
    {
        assert(index < _size);
        if (_max == nullptr)
            __maxrecalc();
        return _max[index];
    }
    T min()
    {
        return *std::min_element(_data, _data + _size);
    }
    T min(size_t index)
    {
        assert(index < _size);
        if (_min == nullptr)
            __minrecalc();
        return _min[index];
    }
    T *begin()
    {
        return _data;
    }
    T *end()
    {
        return _data + _size;
    }
    T *cbegin()
    {
        return _data + _size - 1;
    }
    T *cend()
    {
        return _data - 1;
    }
    void fill(int value)
    {
        std::fill(_data, _data + _size, value);
    }
    void reverse()
    {
        std::reverse(_data, _data + _size);
        if (_sum != nullptr)
            std::reverse(_sum, _sum + _size);
        if (_max != nullptr)
            std::reverse(_max, _max + _size);
        if (_min != nullptr)
            std::reverse(_min, _min + _size);
    }
    void sort()
    {
        std::sort(_data, _data + _size);
        if (_sum != nullptr)
            __sumrecalc();
        if (_max != nullptr)
            __maxrecalc();
        if (_min != nullptr)
            __minrecalc();
    }
    void shift(int count)
    {
        count %= (int32_t)_size;
        T *temp = new T[_size];
        int j = (count < 0 ? _size + count : count);
        for (size_t i = 0; i < _size; i++, j++)
        {
            if (j == _size)
                j = 0;
            temp[j] = _data[i];
        }
        for (size_t i = 0; i < _size; i++)
        {
            _data[i] = temp[i];
        }
        delete temp;
    }
    void random_shuffle() { std::random_shuffle(this->_data, this->_data + this->_size); }
    bool is_sorted()
    {
        for (int i = 1; i < _size; i++)
        {
            if (_data[i - 1] > _data[i + 1])
            {
                return false;
            }
        }
        return true;
    }
    void resize(size_t size)
    {
        __clear();
        __init(size);
    }

    void __clear()
    {
        _size = 0;
        delete _data;
        if (_max)
            delete _max;
        if (_min)
            delete _min;
        if (_sum)
            delete _sum;
    }
    void __sumrecalc()
    {
        _sum = new T[_size];
        _sum[0] = _data[0];
        for (int i = 1; i < _size; i++)
        {
            _sum[i] = _sum[i - 1] + _data[i];
        }
    }
    void __maxrecalc()
    {
        _max = new T[_size];
        _max[0] = _data[0];
        for (int i = 1; i < _size; i++)
        {
            _max[i] = (_data[i] > _max[i - 1] ? _data[i] : _max[i - 1]);
        }
    }
    void __minrecalc()
    {
        _min = new T[_size];
        _min[0] = _data[0];
        for (int i = 1; i < _size; i++)
        {
            _min[i] = (_data[i] < _min[i - 1] ? _data[i] : _min[i - 1]);
        }
    }

    T &operator[](int index)
    {
        if (index < 0)
        {
            assert(-index <= _size);
            return _data[_size + index];
        }
        else
        {
            assert(index < _size);
            return _data[index];
        }
    }
    size_t size() { return _size; }
    bool empty() { return (_size == 0); }

    friend ostream &operator<<(ostream &os, nparray<T> &array)
    {
        for (size_t i = 0; i < array.size(); i++)
        {
            if (i)
                os << " ";
            os << array[i];
        }
        return os;
    }
    friend istream &operator>>(istream &is, nparray<T> &array)
    {
        for (size_t i = 0; i < array.size(); i++)
        {
            is >> array[i];
        }
        return is;
    }
    friend string to_string(nparray<T> &array)
    {
        string s = "{";
        for (size_t i = 0; i < array.size(); i++)
        {
            if (i)
                s += ", ";
            s += to_string(array[i]);
        }
        s += "}";
        return s;
    }
    ~nparray() { __clear(); }
};
template <typename T, int32_t MOD = 1'000'000'007>
struct modular
{
    T x = 0;
    modular() {}
    modular(const modular<T> &m) { this->x = m.x; }
    template <typename C>
    modular(const C &x) { this->x = norm(x); };
    modular<T, MOD> &operator--()
    {
        return *this -= 1;
    }
    modular<T, MOD> &operator++()
    {
        return *this += 1;
    }
    modular<T, MOD> operator--(int32_t)
    {
        modular<T, MOD> m(*this);
        *this -= 1;
        return m;
    }
    modular<T, MOD> operator++(int32_t)
    {
        modular<T, MOD> m(*this);
        *this += 1;
        return m;
    }
    modular<T, MOD> &operator+=(const modular<T, MOD> &m)
    {
        x = norm(x + m.x);
        return *this;
    }
    modular<T, MOD> &operator-=(const modular<T, MOD> &m)
    {
        x = norm(x - m.x);
        return *this;
    }
    modular<T, MOD> &operator*=(const modular<T, MOD> &m)
    {
        x = 1ll * x * m.x % MOD;
        return *this;
    }
    modular<T, MOD> &operator/=(const modular<T, MOD> &m) { return *this *= inv(m.x); }
    template <typename C>
    modular<T, MOD> &operator+=(const C &y)
    {
        x = norm(x + y);
        return *this;
    }
    template <typename C>
    modular<T, MOD> &operator-=(const C &y)
    {
        x = norm(x - y);
        return *this;
    }
    template <typename C>
    modular<T, MOD> &operator*=(const C &y)
    {
        x = norm(x * norm(y));
        return *this;
    }
    template <typename C>
    modular<T, MOD> &operator/=(const C &y)
    {
        assert(0 <= y && y < MOD);
        return *this *= inv(modular<T, MOD>(y));
    }
    friend bool operator<(const modular<T, MOD> &a, const modular<T, MOD> &b)
    {
        return a.x < b.x;
    }
    friend bool operator<=(const modular<T, MOD> &a, const modular<T, MOD> &b)
    {
        return a.x <= b.x;
    }
    friend bool operator>(const modular<T, MOD> &a, const modular<T, MOD> &b)
    {
        return a.x > b.x;
    }
    friend bool operator>=(const modular<T, MOD> &a, const modular<T, MOD> &b)
    {
        return a.x >= b.x;
    }
    friend bool operator==(const modular<T, MOD> &a, const modular<T, MOD> &b)
    {
        return a.x == b.x;
    }
    friend bool operator!=(const modular<T, MOD> &a, const modular<T, MOD> &b)
    {
        return a.x != b.x;
    }
    friend modular<T, MOD> operator+(const modular<T, MOD> &a, const modular<T, MOD> &b)
    {
        return modular<T, MOD>(a.x + b.x);
    }
    friend modular<T, MOD> operator-(const modular<T, MOD> &a, const modular<T, MOD> &b)
    {
        return modular<T, MOD>(a.x - b.x);
    }
    friend modular<T, MOD> operator*(const modular<T, MOD> &a, const modular<T, MOD> &b)
    {
        return modular<T, MOD>(1ll * a.x * b.x);
    }
    friend modular<T, MOD> operator/(const modular<T, MOD> &a, const modular<T, MOD> &b)
    {
        return modular<T, MOD>(a * inv(b));
    }
    friend modular inv(const modular<T, MOD> &m) { return pow(m, MOD - 2); }
    template <typename C>
    friend modular pow(const modular<T, MOD> &m, C n)
    {
        modular<T, MOD> res(1), a(m);
        while (n)
        {
            if (n & 1)
                res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }
    template <typename C>
    friend modular mul(const modular<T, MOD> &m, C n)
    {
        modular<T, MOD> res(0), a(m);
        while (n)
        {
            if (n & 1)
                res += a;
            a += a;
            n >>= 1;
        }
        return res;
    }
    modular<T, MOD> operator-()
        const
    {
        return modular<T, MOD>(-x);
    }
    int32_t mod()
    {
        return MOD;
    }
    template <typename C>
    operator C()
        const
    {
        return (C)x;
    }
    const T &operator()()
        const
    {
        return x;
    }
    friend ostream &operator<<(ostream &os, const modular &m)
    {
        return os << m.x;
    }
    friend istream &operator>>(istream &is, const modular &m)
    {
        return is >> m.x;
    }
    friend string to_string(const modular &m)
    {
        return std::to_string(m.x);
    }
    template <typename C>
    inline T norm(const C &a)
    {
        if (a >= MOD)
        {
            if (a < MOD + MOD)
            {
                return a - MOD;
            }
            else
            {
                return a % MOD;
            }
        }
        else if (a < 0)
        {
            return a % MOD + MOD;
        }
        else
        {
            return a;
        }
    }
};
struct SegmentTree
{
    struct node
    {
        int val = 0;
        int y = -1;

        void apply(int l, int r, int x)
        {
            val = x;
            y = x;
            l = r, r = l;
        }

        static node unite(const node &a, const node &b)
        {
            node res;
            res.val = max(a.val, b.val);
            return res;
        }
    };
    inline void pull(int x, int z)
    {
        tree[x] = node::unite(tree[x + 1], tree[z]);
    }
    inline void push(int v, int l, int r)
    {
        int y = (l + r) >> 1;
        int z = v + ((y - l + 1) << 1);
        if (tree[v].y != -1)
        {
            tree[v + 1].apply(l, y, tree[v].y);
            tree[z].apply(y + 1, r, tree[v].y);
            tree[v].y = -1;
        }
    }
    vector<node> tree;
    void build(int v, int l, int r)
    {
        if (l == r)
        {
            return;
        }
        int y = (l + r) >> 1;
        int z = v + ((y - l + 1) << 1);
        build(v + 1, l, y);
        build(z, y + 1, r);
        pull(v, z);
    }
    template <typename ValueType>
    void build(int v, int l, int r, const vector<ValueType> &a)
    {
        if (l == r)
        {
            tree[v].apply(l, r, a[l]);
            return;
        }
        int y = (l + r) >> 1;
        int z = v + ((y - l + 1) << 1);
        build(v + 1, l, y, a);
        build(z, y + 1, r, a);
        pull(v, z);
    }
    template <typename ValueType>
    void build(int v, int l, int r, ValueType a[])
    {
        if (l == r)
        {
            tree[v].apply(l, r, a[l]);
            return;
        }
        int y = (l + r) >> 1;
        int z = v + ((y - l + 1) << 1);
        build(v + 1, l, y, a);
        build(z, y + 1, r, a);
        pull(v, z);
    }
    node get(int x, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return tree[x];
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        node res;
        if (qr <= y)
        {
            res = get(x + 1, l, y, ql, qr);
        }
        else
        {
            if (ql > y)
            {
                res = get(z, y + 1, r, ql, qr);
            }
            else
            {
                res = node::unite(get(x + 1, l, y, ql, qr), get(z, y + 1, r, ql, qr));
            }
        }
        pull(x, z);
        return res;
    }
    template <typename... M>
    void modify(int x, int l, int r, int ql, int qr, const M &...v)
    {
        if (ql <= l && r <= qr)
        {
            tree[x].apply(l, r, v...);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        if (ql <= y)
        {
            modify(x + 1, l, y, ql, qr, v...);
        }
        if (qr > y)
        {
            modify(z, y + 1, r, ql, qr, v...);
        }
        pull(x, z);
    }
    int find_first_knowingly(int x, int l, int r, const function<bool(const node &)> &f)
    {
        if (l == r)
        {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[x + 1]))
        {
            res = find_first_knowingly(x + 1, l, y, f);
        }
        else
        {
            res = find_first_knowingly(z, y + 1, r, f);
        }
        pull(x, z);
        return res;
    }
    int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node &)> &f)
    {
        if (ll <= l && r <= rr)
        {
            if (!f(tree[x]))
            {
                return -1;
            }
            return find_first_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (ll <= y)
        {
            res = find_first(x + 1, l, y, ll, rr, f);
        }
        if (rr > y && res == -1)
        {
            res = find_first(z, y + 1, r, ll, rr, f);
        }
        pull(x, z);
        return res;
    }
    int find_last_knowingly(int x, int l, int r, const function<bool(const node &)> &f)
    {
        if (l == r)
        {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[z]))
        {
            res = find_last_knowingly(z, y + 1, r, f);
        }
        else
        {
            res = find_last_knowingly(x + 1, l, y, f);
        }
        pull(x, z);
        return res;
    }
    int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node &)> &f)
    {
        if (ll <= l && r <= rr)
        {
            if (!f(tree[x]))
            {
                return -1;
            }
            return find_last_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (rr > y)
        {
            res = find_last(z, y + 1, r, ll, rr, f);
        }
        if (ll <= y && res == -1)
        {
            res = find_last(x + 1, l, y, ll, rr, f);
        }
        pull(x, z);
        return res;
    }
    int tl, tr, n;
    SegmentTree(int _n) : tl(0), tr(n - 1), n(_n)
    {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }
    SegmentTree(int l, int r) : tl(l), tr(r), n(r - l + 1)
    {
        assert(n > 0);
        tree.resize(2 * n + 1);
        build(tl, tl, tr);
    }
    template <typename ValueType>
    SegmentTree(const vector<ValueType> &v)
    {
        n = v.size();
        tl = 0;
        tr = n - 1;
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(tl, tl, tr, v);
    }
    template <typename ValueType>
    SegmentTree(ValueType a[], int n_) : n(n_), tl(1), tr(n_)
    {
        assert(n > 0);
        tree.resize(2 * n + 1);
        build(tl, tl, tr, a);
    }
    node get(int l, int r)
    {
        assert(tl <= l && l <= r && r <= tr);
        return get(tl, tl, tr, l, r);
    }
    node get(int p)
    {
        assert(tl <= p && p <= tr);
        return get(tl, tl, tr, p, p);
    }
    template <typename... ValueType>
    void modify(int l, int r, const ValueType &...v)
    {
        assert(tl <= l && l <= r && r <= tr);
        modify(tl, tl, tr, l, r, v...);
    }
    int find_first(int l, int r, const function<bool(const node &)> &f)
    {
        assert(tl <= l && l <= r && r <= tr);
        return find_first(tl, tl, tr, l, r, f);
    }
    int find_last(int l, int r, const function<bool(const node &)> &f)
    {
        assert(tl <= l && l <= r && r <= tr);
        return find_last(tl, tl, tr, l, r, f);
    }
};

namespace nt
{
    template <typename T>
    struct bigger_type
    {
    };
    template <typename T>
    using bigger_type_t = typename bigger_type<T>::type;
    template <>
    struct bigger_type<int>
    {
        using type = long long;
    };
    template <>
    struct bigger_type<unsigned int>
    {
        using type = unsigned long long;
    };
    template <typename int_t = unsigned long long>
    struct mod_int
    {
        static inline int_t add(int_t const &a, int_t const &b, int_t const &mod)
        {
            int_t ret = a + b;
            if (ret >= mod)
                ret -= mod;
            return ret;
        }
        static inline int_t sub(int_t const &a, int_t const &b, int_t const &mod)
        {
            return add(a, mod - b);
        }
        static inline int_t mul(int_t const &a, int_t const &b, int_t const &mod)
        {
            uint64_t ret = a * (uint64_t)b - (uint64_t)((long double)a * b / mod - 1.1) * mod;
            if (-ret < ret)
            {
                ret = mod - 1 - (-ret - 1) % mod;
            }
            else
            {
                ret %= mod;
            }
            int64_t out = ret;
            return out;
        }
        static inline int_t pow(int_t const &a, int_t const &b, int_t const &mod)
        {
            int_t ret = 1;
            int_t base = a;
            for (int i = 0; b >> i; ++i)
            {
                if ((b >> i) & 1)
                    ret = mul(ret, base, mod);
                base = mul(base, base, mod);
            }
            return ret;
        }
    };
    template <typename T>
    typename enable_if<is_integral<T>::value, bool>::type is_prime(T x)
    {
        if (x < T(4))
            return x > T(1);
        for (T i = 2; i * i <= x; ++i)
        {
            if (x % i == 0)
                return false;
        }
        return true;
    }
    template <typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_single(T const &x, T base)
    {
        if (x < T(4))
            return x > T(1);
        if (x % 2 == 0)
            return false;
        base %= x;
        if (base == 0)
            return true;
        T xm1 = x - 1;
        int j = 1;
        T d = xm1 / 2;
        while (d % 2 == 0)
        {
            d /= 2;
            ++j;
        }
        T t = mod_int<T>::pow(base, d, x);
        if (t == T(1) || t == T(xm1))
            return true;
        for (int k = 1; k < j; ++k)
        {
            t = mod_int<T>::mul(t, t, x);
            if (t == xm1)
                return true;
            if (t <= 1)
                break;
        }
        return false;
    }
    template <typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_multi(T const &)
    {
        return true;
    }
    template <typename T, typename... S>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_multi(T const &x, T const &base, S const &...bases)
    {
        if (!miller_rabin_single(x, base))
            return false;
        return miller_rabin_multi(x, bases...);
    }
    template <typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin(T const &x)
    {
        if (x < 316349281)
            return miller_rabin_multi(x, T(11000544), T(31481107));
        if (x < 4759123141ull)
            return miller_rabin_multi(x, T(2), T(7), T(61));
        return miller_rabin_multi(x, T(2), T(325), T(9375), T(28178), T(450775), T(9780504), T(1795265022));
    }
    template <typename T>
    typename enable_if<is_integral<T>::value, T>::type isqrt(T const &x)
    {
        assert(x >= T(0));
        T ret = static_cast<T>(sqrtl(x));
        while (ret > 0 && ret * ret > x)
            --ret;
        while (x - ret * ret > 2 * ret)
            ++ret;
        return ret;
    }
    template <typename T>
    typename enable_if<is_integral<T>::value, T>::type icbrt(T const &x)
    {
        assert(x >= T(0));
        T ret = static_cast<T>(cbrt(x));
        while (ret > 0 && ret * ret * ret > x)
            --ret;
        while (x - ret * ret * ret > 3 * ret * (ret + 1))
            ++ret;
        return ret;
    }
    vector<uint16_t> saved;
    uint64_t squfof_iter_better(uint64_t const &x, uint64_t const &k, uint64_t const &it_max, uint32_t cutoff_div)
    {
        if (__gcd((uint64_t)k, x) != 1)
            return __gcd((uint64_t)k, x);
        saved.clear();
        uint64_t scaledn = k * x;
        if (scaledn >> 62)
            return 1;
        uint32_t sqrtn = isqrt(scaledn);
        uint32_t cutoff = isqrt(2 * sqrtn) / cutoff_div;
        uint32_t q0 = 1;
        uint32_t p1 = sqrtn;
        uint32_t q1 = scaledn - p1 * p1;
        if (q1 == 0)
        {
            uint64_t factor = __gcd(x, (uint64_t)p1);
            return factor == x ? 1 : factor;
        }
        uint32_t multiplier = 2 * k;
        uint32_t coarse_cutoff = cutoff * multiplier;
        uint32_t i, j;
        uint32_t p0 = 0;
        uint32_t sqrtq = 0;
        for (i = 0; i < it_max; ++i)
        {
            uint32_t q, bits, tmp;
            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;
            if (q1 < coarse_cutoff)
            {
                tmp = q1 / __gcd(q1, multiplier);
                if (tmp < cutoff)
                {
                    saved.push_back((uint16_t)tmp);
                }
            }
            bits = 0;
            tmp = q0;
            while (!(tmp & 1))
            {
                bits++;
                tmp >>= 1;
            }
            if (!(bits & 1) && ((tmp & 7) == 1))
            {
                sqrtq = (uint32_t)isqrt(q0);

                if (sqrtq * sqrtq == q0)
                {
                    for (j = 0; j < saved.size(); ++j)
                    {
                        if (saved[j] == sqrtq)
                            break;
                    }
                    if (j == saved.size())
                        break;
                }
            }
            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;
            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;

            if (q0 < coarse_cutoff)
            {
                tmp = q0 / __gcd(q0, multiplier);

                if (tmp < cutoff)
                {
                    saved.push_back((uint16_t)tmp);
                }
            }
        }
        if (sqrtq == 1)
        {
            return 1;
        }
        if (i == it_max)
        {
            return 1;
        }
        q0 = sqrtq;
        p1 = p0 + sqrtq * ((sqrtn - p0) / sqrtq);
        q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;
        for (j = 0; j < it_max; ++j)
        {
            uint32_t q, tmp;
            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;

            if (p0 == p1)
            {
                q0 = q1;
                break;
            }
            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;
            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;
            if (p0 == p1)
                break;
        }
        uint64_t factor = __gcd((uint64_t)q0, x);
        if (factor == x)
            factor = 1;
        return factor;
    }
    uint64_t squfof(uint64_t const &x)
    {
        static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3 * 5, 3 * 7, 3 * 11, 5 * 7,
                                               5 * 11, 7 * 11, 3 * 5 * 7, 3 * 5 * 11, 3 * 7 * 11,
                                               5 * 7 * 11, 3 * 5 * 7 * 11};
        uint64_t cbrt_x = icbrt(x);
        if (cbrt_x * cbrt_x * cbrt_x == x)
            return cbrt_x;
        uint32_t iter_lim = 300;
        for (uint32_t iter_fact = 1; iter_fact < 20000; iter_fact *= 4)
        {
            for (uint32_t const &k : multipliers)
            {
                if (numeric_limits<uint64_t>::max() / k <= x)
                    continue;
                uint32_t const it_max = iter_fact * iter_lim;
                uint64_t factor = squfof_iter_better(x, k, it_max, 1);
                if (factor == 1 || factor == x)
                    continue;
                return factor;
            }
        }
        return 1;
    }
    template <typename T>
    typename enable_if<is_integral<T>::value, vector<T>>::type factorize_brute(T x)
    {
        vector<T> ret;
        while (x % 2 == 0)
        {
            x /= 2;
            ret.push_back(2);
        }
        for (uint32_t i = 3; i * (T)i <= x; i += 2)
        {
            while (x % i == 0)
            {
                x /= i;
                ret.push_back(i);
            }
        }
        if (x > 1)
            ret.push_back(x);
        return ret;
    }
    template <typename T>
    typename enable_if<is_integral<T>::value, vector<T>>::type factorize(T x)
    {
        vector<T> ret;
        const uint32_t trial_limit = 5000;
        auto trial = [&](uint32_t const &i)
        {
            while (x % i == 0)
            {
                x /= i;
                ret.push_back(i);
            }
        };
        trial(2);
        trial(3);
        for (uint32_t i = 5, j = 2; i < trial_limit && i * i <= x; i += j, j = 6 - j)
        {
            trial(i);
        }

        if (x > 1)
        {
            static stack<T> s;
            s.push(x);
            while (!s.empty())
            {
                x = s.top();
                s.pop();
                if (!miller_rabin(x))
                {
                    T factor = squfof(x);
                    if (factor == 1 || factor == x)
                    {
                        assert(0);
                        return ret;
                    }
                    s.push(factor);
                    s.push(x / factor);
                }
                else
                {
                    ret.push_back(x);
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
}
////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

#define base (int)1e9
class BigInteger
{
private:
    vector<int> Integer;
    void SetInteger()
    {
        while (this->Integer.size() > 1 && this->Integer.back() == 0)
        {
            this->Integer.pop_back();
        }
    }
    void print()
    {
        SetInteger();
        printf("%d", this->Integer.size() == 0 ? 0 : this->Integer.back());
        int len = this->Integer.size() - 2;
        for (int i = len; i >= 0; i--)
        {
            printf("%09d", this->Integer[i]);
        }
    }

public:
    BigInteger() {}
    // 使用string初始化BigInteger，不支持负数
    BigInteger(string s)
    {
        if (s.size() == 0)
        {
            Integer.push_back(0);
            return;
        }
        while (s.size() % 9 != 0)
        {
            s = '0' + s;
        }
        int len = s.size();
        for (int i = 0; i < len; i += 9)
        {
            int v = 0;
            for (int j = i; j < i + 9; j++)
                v = v * 10 + (s[j] - '0');
            Integer.insert(Integer.begin(), v);
        }
    }
    // 使用char 数组初始化 BigInteger
    BigInteger(char c[])
    {
        string s = c;
        new (this) BigInteger(s);
    }
    // 使用 long long 类型初始化 BigInteger
    BigInteger(long long x)
    {
        string s = "";
        while (x > 0)
        {
            s = char(x % 10 + '0') + s;
            x /= 10;
        }
        new (this) BigInteger(s);
    }
    // 使用int类型初始化 BigInteger
    BigInteger(int x)
    {
        new (this) BigInteger((long long)x);
    }
    // 重载输入运算符
    friend istream &operator>>(istream &in, BigInteger &a)
    {
        string s;
        cin >> s;
        BigInteger temp(s);
        a = temp;
        return in;
    }
    // 重载输出运算符
    friend ostream &operator<<(ostream &out, BigInteger a)
    {
        a.print();
        return out;
    }
    // 重载=运算符
    BigInteger &operator=(const BigInteger &a)
    {
        this->Integer = a.Integer;
        return *this;
    }
    // 重载<运算符，用于两个大数之间的比较
    friend bool operator<(BigInteger a, BigInteger b)
    {
        a.SetInteger();
        b.SetInteger();
        if (a.Integer.size() != b.Integer.size())
            return a.Integer.size() < b.Integer.size();
        int len = a.Integer.size() - 1;
        for (int i = len; i >= 0; i--)
        {
            if (a.Integer[i] != b.Integer[i])
                return a.Integer[i] < b.Integer[i];
        }
        return false;
    }
    // 重载<运算符，可以用于任意类型的比较
    template <typename T>
    friend bool operator<(BigInteger a, T b)
    {
        BigInteger t((long long)b);
        return a < t;
    }
    // 重载>运算符，用于两个大数之间的比较
    friend bool operator>(BigInteger a, BigInteger b)
    {
        return b < a;
    }
    // 重载>运算符，可以用于任意类型的比较
    template <typename T>
    friend bool operator>(BigInteger a, T b)
    {
        BigInteger t((long long)b);
        return t < a;
    }
    // 重载==运算符
    friend bool operator==(BigInteger a, BigInteger b)
    {
        return !(a < b) && !(b < a);
    }
    // 重载！=运算符
    friend bool operator!=(BigInteger a, BigInteger b)
    {
        return !(a == b);
    }
    // 重载==运算符，可以用于任意类型的比较
    template <typename T>
    friend bool operator==(BigInteger a, T b)
    {
        BigInteger t((long long)b);
        return !(a < t) && !(t < a);
    }
    // 重载<=运算符，可以用于任意类型的比较
    template <typename T>
    friend bool operator<=(BigInteger a, T b)
    {
        return a < b || a == b;
    }
    // 重载>=运算符，可以用于任意类型的比较
    template <typename T>
    friend bool operator>=(BigInteger a, T b)
    {
        return b < a || b == a;
    }
    // 重载+运算符，用于两个大数相加
    BigInteger operator+(BigInteger x)
    {
        BigInteger y = *this, ans;
        x.SetInteger();
        y.SetInteger();
        int carry = 0;
        int len = max(x.Integer.size(), y.Integer.size());
        for (int i = 0; i < len; i++)
        {
            if (i < (int)x.Integer.size())
                carry += x.Integer[i];
            if (i < (int)y.Integer.size())
                carry += y.Integer[i];
            ans.Integer.push_back(carry % base);
            carry /= base;
        }
        if (carry)
            ans.Integer.push_back(carry);
        ans.SetInteger();
        return ans;
    }
    // 重载+运算符，用于大数和任意类型相加
    template <typename T>
    BigInteger operator+(T x)
    {
        BigInteger t((long long)x);
        return *this + t;
    }
    // 重载后置++运算符
    const BigInteger operator++(int)
    {
        BigInteger t = *this;
        *this = *this + 1;
        return t;
    }
    // 重载前置++运算符
    BigInteger &operator++()
    {
        *this = *this + 1;
        return *this;
    }
    // 重载+=运算符，用于两个大数相加
    BigInteger &operator+=(BigInteger x)
    {
        *this = *this + x;
        return *this;
    }
    // 重载+=运算符，用于任意类型相加
    template <typename T>
    BigInteger &operator+=(T x)
    {
        BigInteger t((long long)x);
        *this = *this + t;
        return *this;
    }
    // 重载-运算符，用于两个大数相减
    BigInteger operator-(BigInteger x)
    {
        BigInteger y = *this, ans;
        x.SetInteger();
        y.SetInteger();
        int carry = 0, len = y.Integer.size();
        for (int i = 0; i < len; i++)
        {
            carry += y.Integer[i] - (i < (int)x.Integer.size() ? x.Integer[i] : 0);
            if (carry < 0)
            {
                ans.Integer.push_back(carry + base);
                carry = -1;
            }
            else
            {
                ans.Integer.push_back(carry);
                carry = 0;
            }
        }
        ans.SetInteger();
        return ans;
    }
    // 重载-运算符，用于大数与任意类型相减
    template <typename T>
    BigInteger operator-(T x)
    {
        BigInteger t((long long)x);
        return *this - t;
    }
    // 重载后置--运算符
    const BigInteger operator--(int)
    {
        BigInteger t = *this;
        *this = *this - 1;
        return t;
    }
    // 重载前置--运算符
    BigInteger &operator--()
    {
        *this = *this - 1;
        return *this;
    }
    // 重载-=运算符，用于两个大数相减
    BigInteger &operator-=(BigInteger x)
    {
        *this = *this - x;
        return *this;
    }
    // 重载-=运算符，用于大数和任意类型相减
    template <typename T>
    BigInteger &operator-=(T x)
    {
        BigInteger t((long long)x);
        *this = *this - t;
        return *this;
    }
    // 重载*运算符，用于两个两个大数相乘
    BigInteger operator*(BigInteger x)
    {
        BigInteger y = *this, ans;
        x.SetInteger();
        y.SetInteger();
        int xlen = x.Integer.size(), ylen = y.Integer.size();
        ans.Integer.assign(xlen + ylen, 0);
        for (int i = 0; i < xlen; i++)
        {
            long long carry = 0ll;
            for (int j = 0; j < ylen || carry > 0; j++)
            {
                long long s =
                    ans.Integer[i + j] + carry + (long long)x.Integer[i] * (j < (int)y.Integer.size() ? (long long)y.Integer[j] : 0ll);
                ans.Integer[i + j] = s % base;
                carry = s / base;
            }
        }
        ans.SetInteger();
        return ans;
    }
    //  重载 *运算符, 用于大数和任意两个数相乘
    template <typename T>
    BigInteger operator*(T x)
    {
        BigInteger t((long long)x);
        return *this * t;
    }
    // 重载*= 算符,      用于两个大数相乘
    BigInteger &operator*=(BigInteger x)
    {
        *this = *this * x;
        return *this;
    }
    // 重载*=运算符, 用于大数与任意类型的数相乘
    template <typename T>
    BigInteger &operator*=(T x)
    {
        BigInteger t((long long)x);
        *this = *this * t;
        return *this;
    }
    // 重载 / 运算符, 用于两个大数相除
    BigInteger operator/(BigInteger x)
    {
        BigInteger y = *this, ans, cur;
        x.SetInteger();
        y.SetInteger();
        int len = y.Integer.size() - 1;
        for (int i = len; i >= 0; i--)
        {
            cur.Integer.insert(cur.Integer.begin(), y.Integer[i]);
            int t = 0, l = 0, r = base;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (x * BigInteger(mid) > cur)
                {
                    t = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            cur = cur - BigInteger(t - 1) * x;
            ans.Integer.insert(ans.Integer.begin(), t - 1);
        }
        ans.SetInteger();
        return ans;
    }
    // 重载/运算符, 用于大数和任意类型相除
    template <typename T>
    BigInteger operator/(T x)
    {
        BigInteger y = *this, ans, t((long long)x);
        y.SetInteger();
        long long cur = 0ll;
        int len = y.Integer.size() - 1;
        for (int i = len; i >= 0; i--)
        {
            cur = cur * (long long)base + (long long)y.Integer[i];
            ans.Integer.insert(ans.Integer.begin(), cur / x);
            cur %= x;
        }
        ans.SetInteger();
        return ans;
    }
    //  重载 /=运算符,  用于大数和大数相除
    BigInteger &operator/=(BigInteger x)
    {
        *this = *this / x;
        return *this;
    }
    // 重载 /=运算符,  用于大数和任意类型相除
    template <typename T>
    BigInteger &operator/=(T x)
    {
        BigInteger t((long long)x);
        *this = *this / t;
        return *this;
    }
    // 重载%运算符，用于两个大数之间的取余数操作
    BigInteger operator%(BigInteger x)
    {
        BigInteger y = *this, ans;
        x.SetInteger();
        y.SetInteger();
        int len = y.Integer.size() - 1;
        for (int i = len; i >= 0; i--)
        {
            ans.Integer.insert(ans.Integer.begin(), y.Integer[i]);
            int t = 0, l = 0, r = base;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (x * BigInteger(mid) > ans)
                {
                    t = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            ans = ans - BigInteger(t - 1) * x;
        }
        ans.SetInteger();
        return ans;
    }
    //  重载 % 算符, 用于大数和任意类型的数
    template <typename T>
    T operator%(T x)
    {
        BigInteger y = *this;
        y.SetInteger();
        T ans = (T)0;
        int len = y.Integer.size() - 1;
        for (int i = len; i >= 0; i--)
        {
            ans = (ans * (base % x) + y.Integer[i] % x) % x;
        }
        return ans;
    }
    //  重载%= 算符, 大数之间
    BigInteger &operator%=(BigInteger x)
    {
        *this = *this % x;
        return *this;
    }
    // 重载%=运算符     大数和任意类型
    template <typename T>
    BigInteger &operator%=(T x)
    {
        BigInteger t((long long)x);
        *this = *this % t;
        return *this;
    }
    friend BigInteger power(BigInteger a, BigInteger x)
    {
        if (x == BigInteger(0) || a == BigInteger(1))
            return BigInteger(1);
        BigInteger tmp = power(a, x / 2);
        if (x % 2 == 0)
            return tmp * tmp;
        return tmp * tmp * a;
    }
    // 大数和较小数
    template <typename T>
    friend BigInteger power(BigInteger a, T x)
    {
        return power(a, BigInteger((long long)x));
    }
    // 大数和大数
    friend BigInteger gcd(BigInteger a, BigInteger b)
    {
        a.SetInteger();
        b.SetInteger();
        while (b > BigInteger(0))
        {
            BigInteger r = a % b;
            a = b;
            b = r;
        }
        a.SetInteger();
        return a;
    }
    //  最小公倍数
    friend BigInteger lcm(BigInteger a, BigInteger b)
    {
        return a * b / gcd(a, b);
    }
    // 大数开方
    friend BigInteger sqrt(BigInteger a)
    {
        BigInteger x0 = a, x1 = (a + 1) / 2;
        while (x1 < x0)
        {
            x0 = x1;
            x1 = (x1 + a / x1) / 2;
        }
        return x0;
    }
    //  大数 log
    friend int log(BigInteger a, int n)
    { // log_n(a)
        int ans = 0;
        a.SetInteger();
        while (a > BigInteger(1))
        {
            ans++;
            a /= n;
        }
        return ans;
    }
};

/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣶⣶⣶⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣹⣿⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣼|⣿⣿⣿⣿⣿|⣶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿|⣿⣿⣿⣿⣿|⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣿⣿⣿|⣿⣿⣿⣿⣿⣿|⣿⣿⣿⣿⣷⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿|⣿⣿⣿⣿⣿⣿⡿⠟⠉⠙⠻⠿⢿⣿⣿⣿⣿⣶⣦⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿|⣿⣿⣿⣿⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠉⢙⣻⣿⣿⣿⣷⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿你⣿⣿⠁⠀
⣷⣄⠀⠀⠀⠀⠀⣴⣿⣿⠋⠁⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿淦⣿麻⣿⣿⠀
⣿⣿⣷⣦⡀⢀⣼⣿⣿⡏⠀⠀⠀⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠙⠿⣿⣿⣿⠟⠁⠀
⣿⣿⣿⣿⣿⣾⣿⡿⠻⠃⠀⠀⠀⢻⣿⣿⣿⣿⠈⢿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠘⣿⣿⣿⣿⠀⠀⢻⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⡀⠀⠀⣿⣿⣿⣿⡇⠀⠀⢹⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣠⣿⣿⣿⡿⠁⠀⠀⠀⢻⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            坤坤保佑       速速AC     永无BUG
*/
#define int long long
#define endl "\n"
inline void slove()
{
    int ans;
    cin >> ans;
    cout << (ans + 1) * (ans + 1) + 1 << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}