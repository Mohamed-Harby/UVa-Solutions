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


ll Choose(int n, int m) {
    vector<int> num;
    vector<int> den;

    int c = n - m;
    while (n) {
        num.push_back(n--);
    }

    while (c) {
        den.push_back(c--);
    }

    while (m) {
        den.push_back(m--);
    }
    for (int i = 0; i < num.size(); ++i) {
        for (int k = 0; k < den.size(); ++k) {
            if (__gcd(num[i], den[k]) == den[k]) {
                num[i] /= den[k], den[k] = 1;
            }
        }
    }

    double res = 1.0;
    for (int i = 0; i < num.size(); ++i) {
        res *= num[i];
    }
    for (int i = 0; i < den.size(); ++i) {
        res /= den[i];
    }

    return 1LL * res;
}


int main() {
//	init();

    int n, m;
    while (scanf("%d%d", &n, &m), n || m) {
        printf("%d things taken %d at a time is %lld exactly.\n", n, m, Choose(n, m));
    }
}
