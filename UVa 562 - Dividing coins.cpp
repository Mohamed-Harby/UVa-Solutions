#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define lol                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define vi vector<int>
#define ll long long
const int OO = 500004;

int n;
vi v;
int MAX;
int mem[104][50004];

int min_dif(int i, int pre_sum) {
	if (i == n)
		return abs(pre_sum - (MAX - pre_sum));

	if (mem[i][pre_sum] != -1)
		return mem[i][pre_sum];

	int &res = mem[i][pre_sum];
	res = OO;

	res = min(res, min_dif(i + 1, pre_sum));
	res = min(res, min_dif(i + 1, pre_sum + v[i]));

	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	lol
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		v.resize(n);

		MAX = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			MAX += v[i];
		}

		memset(mem, -1, sizeof mem);
		int x = min_dif(0, 0);
		cout << x << '\n';

	}

}
