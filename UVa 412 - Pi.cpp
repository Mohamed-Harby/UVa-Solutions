/*
 *In the name of allah the most gracious and the most merciful
 */
#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define vi vector<int>

using ll = long long;
using namespace std;

void init() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
}

bool no_common_factor(int x, int y) {
	return (__gcd(x,y) == 1);
}

int main() {
	init();
	int n;
	while (cin >> n, n) {
		vi v(n);
		for (int i = 0; i < n && cin >> v[i]; i++);
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int s = i + 1; s < n; ++s) {
				cnt += no_common_factor(v[i], v[s]);
			}
		}
		if (cnt == 0) {
			cout << "No estimate for this data set.\n";
		} else {
			int d = (n * (n - 1)) / 2;
			double res = (d * 6.0) / cnt;
			res = sqrt(res);
			cout << fixed << setprecision(6) << res << '\n';
		}
	}
}
