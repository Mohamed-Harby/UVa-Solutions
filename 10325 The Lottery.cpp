//				بِسْمِ اللَّـهِ الرَّحْمَـٰنِ الرَّحِيمِ

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
                     << "\n\n"
#define ll long long
#define vi vector<int>
#define qi queue<int>
#define pii pair<int, int>
#define ss second
#define ff first

ll LCM(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

int main()
{
    // lol 
    int N, M;

    while (cin >> N >> M)
    {
        vi v(M);
        for (int i = 0; i < M; ++i)
            cin >> v[i];

        ll to_remove = 0;
        int MAX_MASK = 1 << M;
        for (int Mask = 1; Mask < MAX_MASK; ++Mask)
        {
            ll divisor = 1;
            for (int i = 0; i < M; ++i)
            {
                if ((1 << i) & Mask)
                {
                    divisor = LCM(divisor, v[i]);
                }
            }
            if (__builtin_popcount(Mask) & 1)
                to_remove += N / divisor;
            else
                to_remove -= N / divisor;
        }

        cout << N - to_remove << '\n';
    }
    elapsed;
    return 0;
}
