#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define lol                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define vi vector<int>
#define ll long long

const int N = 40000 * 1000 + 7;

bool prime[N];

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	memset(prime, 1, sizeof prime);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= N; ++i) {
		if (prime[i]) {
			for (int j = i + i; j < N; j += i)
				prime[j] = false;
		}
	}
	vector<int> v;
	for (int i = 0; i < N; ++i) {
		if (prime[i])
			v.push_back(i);
	}
	int sz = v.size();
	vector<pair<int, int>> twin;

	for (int i = 1; i < sz; ++i) {
		if (v[i] - v[i - 1] == 2)
			twin.push_back( { v[i - 1], v[i] });
	}
	int cs;
	while (cin >> cs) {
		--cs;
		cout << '(' << twin[cs].first << ", " << twin[cs].second << ")\n";
	}

}

