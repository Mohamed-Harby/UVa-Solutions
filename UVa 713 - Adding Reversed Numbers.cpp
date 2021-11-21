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
	string s, d, sum;
	int med, rem;
	char to_append;

	int t;
	cin >> t;
	while (t--) {
		cin >> s >> d;
		while (s.size() < d.size())
			s += '0';
		while (d.size() < s.size())
			d += '0';

		sum = "";
		rem = 0;
		for (int i = 0; i < int(s.size()); ++i) {
			med = int((s[i] - '0') + (d[i] - '0') + rem);
			rem = med / 10;
			to_append = '0' + (med % 10);
			sum += to_append;
		}

		if (rem) {
			sum += char('0' + rem);
		}
		int st = 0;
		while (sum[st] == '0') {
			st++;
		}
		for (; st < int(sum.size()); ++st)
			cout << sum[st];

		cout << '\n';
	}
}
