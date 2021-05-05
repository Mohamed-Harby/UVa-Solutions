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
    freopen("output.txt", "w", stdout);
#endif
}

int mod_expon(int b, int p, int mod) {
	if(p == 0) return 1;

	int res = mod_expon(b, p / 2, mod);

	res *= res;
	res %= mod;

	if(p & 1) {
		res *= b;
	}
	return res % mod;
} 


int main() {
	init();

    int B, P, M;
    while(cin >> B >> P >> M && cin.good()) {
        cout << mod_expon(B%M, P, M) << '\n';
    }
    return 0;
}
