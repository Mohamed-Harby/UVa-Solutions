#include <bits/stdc++.h>

#define ll long long
#define IM INT_MAX
#define pb push_back
using namespace std;

map<char, vector<char>> adj_list;
map<char, bool> exist;
map<char, bool> visited;
vector<char> sequence;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfs(char c) {
    visited[c] = true;
    for (char &cc: adj_list[c]) {
        if (!visited[cc]) {
            dfs(cc);
        }
    }
    sequence.pb(c);
}

int main() {
    init();
    string prev, curr;
    cin >> prev;
    while (cin >> curr, curr != "#") {
        for (int i = 0; i < min(prev.size(), curr.size()); ++i) {
            if (prev[i] != curr[i]) {
                exist[prev[i]] = exist[curr[i]] = true;
                adj_list[prev[i]].pb(curr[i]);
                break;
            }
        }
        prev = curr;
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (exist.find(c) != exist.end() and !visited[c]) { // item exist
            dfs(c);
        }
    }
    reverse(sequence.begin(), sequence.end());
    for (char &letter: sequence) {
        cout << letter;
    }
    cout << '\n';
}
