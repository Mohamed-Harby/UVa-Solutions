/*				بِسْمِ اللَّـهِ الرَّحْمَـٰنِ الرَّحِيمِ				*/
#include <bits/stdc++.h>

using namespace std;
#define all(v) begin(v), end(v)
#define lol                       \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define PREC(n) cout << fixed << setprecision(n);
#define eps 1E-10
#define sz(v) int(sizeof(v)/sizeof(v[0]))
#define pi  2*acos(0.0)
#define inf 1.797E308
#define elapsed cerr << float(clock()) / CLOCKS_PER_SEC << " sec" << "\n"
#define ll long long
#define vi vector<int>
#define qi queue<int>
#define pii pair<int, int>
#define ss second
#define ff first

int n = 1e7;
vector<bool> isPrime(n + 1, true);

void get_prime() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i + i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

vector<int> primes;

int previous_prime(int val) {   // using binary search
    int st = 0, en = primes.size() - 1;
    int mid;
    // 1111|1|0000
    while (st < en) {
        mid = ((st + en) >> 1) + 1;
        if (primes[mid] < val)
            st = mid;
        else
            en = mid - 1;
    }
    return primes[st]; // return index of the previous prime
}

int main() {

    // prime - any_previous_prime = x , where x can always be formed of three or less prime numbers

    get_prime();
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i])
            primes.push_back(i);
    }
    elapsed;

    int in;
    while (cin >> in) {
        if (in < 8) {
            cout << "Impossible.\n";
            continue;
        }
        vi res;
        int tmp;
        int i = 3;
        while (in) {
            tmp = in;
            while (in - tmp < i * 2) {
                tmp = previous_prime(tmp);
            }
            res.push_back(tmp);
            in -= tmp;
            --i;
        }
        for (int x: res)
            cout << x << ' ';
        cout << '\n';
    }

//    for (int x: primes) {
//        for (int y: primes) {
//            mp[x + y] = {x, y};
//        }
//    }
//    cout << (mp[1] == make_pair(0, 0));
//    elapsed;

//    int max_diff = -1e9;
//    for (int i = 1; i < primes.size(); ++i) {
//        max_diff = max(max_diff, primes[i] - primes[i - 1]);
//    }
//

//    cerr << max_diff << '\n';
//    cout << "[ ";
//    for (int i = 1; i < 20; ++i) {
//        cout << primes[i] << ", ";
//    }
//    cout << "]\n";

}
