#include <bits/stdc++.h>
using namespace std;
#define all(v) begin(v), end(v)
#define lol                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define PREC(n) cout << fixed << setprecision(n);
#define eps 1E-10
#define sz(v) int(sizeof(v)/sizeof(v[0]))
#define pi  2*acos(0.0)
#define inf 1.797E308
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pii pair<int, int>

int main() {
	lol

	// to unlock a room, its number must have odd number of divsiors.
	// all numbers have even number of divisors except perfect squares.
	// number of perfect squre in range 1~n is sqrt(n)
	// e.g. number of perfect squre in range 1~100 is 10 : 100, 81, 64, 49, 36, 25, 16, 9, 4, 1

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << int(sqrt(n)) << '\n';
	}

}

