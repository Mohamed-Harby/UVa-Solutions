#include <bits/stdc++.h>

#define ll long long
#define IM INT_MAX
#define pb push_back
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


int H, W;
vector<vector<char>> MAP;
vector<vector<bool>> visited;
map<char, int> freq;

bool valid(int i, int j) {
    return (i >= 0 && i < H and j >= 0 && j < W);
}

int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};

void dfs(int i, int j) {
    visited[i][j] = true;
    for (int d = 0; d < 4; ++d) {
        int child_x = i + x[d], child_y = j + y[d];
        if (valid(child_x, child_y) &&
            !visited[child_x][child_y] &&
            MAP[child_x][child_y] == MAP[i][j]
                ) {
            dfs(child_x, child_y);
        }
    }
}

void connected_areas() {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j]) {
                dfs(i, j);
                freq[MAP[i][j]]++;
            }
        }
    }
}

bool greater_state(pair<char, int> &p1, pair<char, int> &p2) {
    return p1.second > p2.second;
}

int main() {
    init();
    int N;
    cin >> N;
    for (int I = 1; I <= N; ++I) {
        cin >> H >> W;
        MAP = vector<vector<char>>(H, vector<char>(W));
        visited = vector<vector<bool>>(H, vector<bool>(W));

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> MAP[i][j];
            }
        }
        freq.clear();
        connected_areas();

        vector<pair<char, int>> states;
        for (pair<const char, int> &p: freq) {
            states.pb(p);
        }
        sort(states.begin(), states.end(),
             [](const pair<char, int> &p1, const pair<char, int> &p2) -> bool {
                 return p1.second > p2.second;
             });

        cout << "World #" << I << '\n';
        for (pair<char, int> &p: states) {
            cout << p.first << ": " << p.second << '\n';
        }
    }
}
// Solved with LOVE <3
