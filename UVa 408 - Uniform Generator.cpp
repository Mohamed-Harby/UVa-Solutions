#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define lol                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define vi vector<int>

void output(int step, int mod, string out) {
    cout << setw(10) << step << setw(10) << mod << "    "   // four spaces
     << out << "\n\n";
}

int main() {
    
    int STEP, MOD;
    vector<bool> vis;
    while(cin >> STEP >> MOD){
        vis = vector<bool> (MOD);
        int seed = 0;
        vis[seed] = true;
        for (int i = 0; i < MOD; ++i) {
            seed = (seed + STEP) % MOD;
            vis[seed] = true;
        }
        bool Bad = false;
        for (int i = 0; i < MOD; ++i) {
            if (!vis[i]) {
                Bad = true;
                break;
            }
        }
        if (Bad) {
            output(STEP, MOD, "Bad Choice");
        }else{
            output(STEP, MOD, "Good Choice");
        }    
    }
}
