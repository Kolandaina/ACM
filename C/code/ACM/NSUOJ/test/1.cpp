#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = INT64_MAX;
const int mod = 998244353;

string GetName (int x, string s) {
	stringstream ss;
	ss << x << s;
	return ss.str();
}
// 函数用于生成一个从 l 到 r 的随机排列
std::vector<int> generateRandomPermutation (int l, int r) {
	int n = r - l + 1;
	std::vector<int> permutation (n);
	for (int i = 0; i < n; ++i) {
		permutation[i] = l + i;
	}

	std::random_device rd;
	std::mt19937 g (rd());

	std::shuffle (permutation.begin(), permutation.end(), g);

	return permutation;
}

// 函数用于生成一个从 l 到 r 的随机环
std::vector<std::pair<int, int>> generateRandomCycle (int l, int r) {
	std::vector<int> permutation = generateRandomPermutation (l, r);
	int n = r - l + 1;
	std::vector<std::pair<int, int>> cycle;

	// 将生成的排列连接成环
	for (int i = 0; i < n - 1; ++i) {
		cycle.push_back ({permutation[i], permutation[i + 1]});
	}
	// 将最后一个顶点与第一个顶点连接
	cycle.push_back ({permutation[n - 1], permutation[0]});

	return cycle;
}

// 随机划分长度 n 为多个随机长度的部分
std::vector<int> randomPartition (int n) {
	std::vector<int> partition;
	std::random_device rd;
	std::mt19937 g (rd());

	while (n > 0) {
		int part = std::uniform_int_distribution<> (1, n) (g);
		partition.push_back (part);
		n -= part;
	}

	return partition;
}
void generateIO (int caseNum) {
	string Name1 = GetName (caseNum, ".in");
	string Name2 = GetName (caseNum, ".out");

	fstream fp1, fp2;
	fp1.open (Name1, ios::out); // in
	fp2.open (Name2, ios::out); // out

	std::mt19937_64 rng (
	    time (0) + caseNum); // 使用不同的种子值保证不同文件生成的随机数不同
	std::uniform_int_distribution<int> r1 (
	    1, 100);  // l, r 的范围可以根据需要调整，这里设为1到1000
	int t = 1;  // 随机生成测试样例数 t，设为10
	fp1 << t << endl;

	for (int i = 1; i <= t; i++) {
		int n;
		n = 100000;
		std::vector<int> lengths = randomPartition (n);
		std::vector<std::pair<int, int>> allEdges;

		int current = 1;
		for (int length : lengths) {
			std::vector<std::pair<int, int>> cycle = generateRandomCycle (current, current + length - 1);
			allEdges.insert (allEdges.end(), cycle.begin(), cycle.end());
			current += length;
		}
		std::random_device rd;
		std::mt19937 f (rd());
		std::shuffle (allEdges.begin(), allEdges.end(), f);
		std::vector<int> a (n + 1), b (n + 1);
		for (int i = 0; i < n; i++) {
			a[i + 1] = allEdges[i].first;
			b[i + 1] = allEdges[i].second;
		}
		fp1 << n << endl;
		for (int j = 1; j <= n; j++) {
			fp1 << a[j] << " ";
		}
		fp1 << endl;
		for (int j = 1; j <= n; j++) {
			fp1 << b[j] << " ";
		}
		fp1 << endl;
		int ans = 1;
		std::vector<int> buc (n + 1, 0), vis (n + 1, 0);
		for (int i = 1; i <= n; i++) {
			if (a[i] == b[i]) {
				buc[a[i]]++;
				vis[a[i]] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (buc[i] > 1)
				ans = 0;
			else if (buc[i] == 1)
				ans = ans * n % mod;
		}
		std::vector<std::vector<int>> g (n + 1);
		std::vector<int> cnt (n + 1, 0), size (n + 1, 0);
		auto dfs1 = [&] (auto& self, int u, int fa) -> bool {
			for (auto v : g[u]) {
				if (v == fa) continue;
				if (vis[v]) return false;
				vis[v] = true;
				if (!self (self, v, u)) return false;
			}
			return true;
		};
		auto dfs2 = [&] (auto& self, int u, int fa) -> void {
			vis[u] = 1;
			size[fa]++;
			for (auto v : g[u]) {
				cnt[fa]++;
				if (!vis[v]) self (self, v, fa);
			}
		};
		for (int i = 1; i <= n; i++) {
			if (a[i] != b[i]) {
				if (buc[a[i]] && buc[b[i]])
					ans = 0;
				else {
					g[a[i]].push_back (b[i]);
					g[b[i]].push_back (a[i]);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (buc[i]) {
				if (!dfs1 (dfs1, i, 0)) {
					ans = 0;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				dfs2 (dfs2, i, i);
				if (cnt[i] != size[i] * 2)
					ans = 0;
				else
					ans = ans * 2 % mod;
			}
		}
		fp2 << ans << endl;
	}
	fp1.close();
	fp2.close();
}

signed main() {
	ios::sync_with_stdio (false), cin.tie (0), cout.tie (0);

	const int START = 2;  // 开始的编号
	const int SUM_G = 2;  // 生成文件的组数

	for (int Case = START; Case <= SUM_G; Case++) {
		generateIO (Case);
	}

	return 0;
}
