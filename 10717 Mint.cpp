//			بِسْمِ اللَّـهِ الرَّحْمَـٰنِ الرَّحِيمِ

#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v), end(v)
#define lol                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define PREC(n) cout << fixed << setprecision(n);
#define eps 1E-10
#define sz(v) int(sizeof(v) / sizeof(v[0]))
#define pi 2 * acos(0.0)
#define inf 1.797E308
#define elapsed cerr << "\n"                                      \
                     << float(clock()) / CLOCKS_PER_SEC << " sec" \
                     << "\n\n";
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define qi queue<int>
#define pii pair<int, int>
#define ss second
#define ff first

ll LCM(ll a, ll b) {
	return a * b / __gcd(a, b);
}

int main() {
	lol
	int N, T;
	while (cin >> N >> T && (N && T)) {
		vll coins(N), tables(T);
		for (int i = 0; i < N; ++i)
			cin >> coins[i];
		for (int i = 0; i < T; ++i)
			cin >> tables[i];

		for (int table = 0; table < T; ++table) {
			vll hights;
			ll bar = 1;
			ll hight = tables[table];
			for (int i = 0; i < N; ++i) {
				for (int j = i + 1; j < N; ++j) {
					for (int k = j + 1; k < N; ++k) {
						for (int l = k + 1; l < N; ++l) {
							bar = LCM(coins[i],
									LCM(coins[j], LCM(coins[k], coins[l])));

							hights.push_back((hight / bar) * bar);
							hights.push_back(((hight / bar) + 1) * bar);
						}
					}
				}
			}
			sort(all(hights));
			ll great = *lower_bound(all(hights), hight);
			ll small;
			if (great == hight)
				small = great;
			else
				small = *(lower_bound(all(hights), hight) - 1);
			cout << small << ' ' << great << '\n';
		}
	}
//	elapsed
	return 0;
}
