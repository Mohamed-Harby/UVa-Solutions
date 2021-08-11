#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define lol                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define vi vector<int>
#define ll long long

const int MAX = 2000000;
const int S = 0;
int Intervals[4194304];
bool lucky[MAX + 9];

// insert and return position
int insert(int num, int s = S, int e = MAX, int p = 1) {
	Intervals[p]++;
	if (s == e)
		return Intervals[p];
	if (num <= (s + e) / 2)
		return insert(num, s, (s + e) / 2, p * 2);
	else
		return Intervals[p * 2] + insert(num, (s + e) / 2 + 1, e, p * 2 + 1);
}

int getKth(int k, int s = S, int e = MAX, int p = 1) {
	if (s == e)
		return s;
	if (k <= Intervals[p * 2])
		return getKth(k, s, (s + e) / 2, p * 2);
	else
		return getKth(k - Intervals[p * 2], (s + e) / 2 + 1, e, p * 2 + 1);
}

void delKth(int k, int s = S, int e = MAX, int p = 1) {
	Intervals[p]--;
	if (s == e)
		return;
	if (k <= Intervals[p * 2])
		delKth(k, s, (s + e) / 2, p * 2);
	else
		delKth(k - Intervals[p * 2], (s + e) / 2 + 1, e, p * 2 + 1);
}

void preprocess() {
	for (int i = 1; i <= MAX; i += 2)
		insert(i);

	lucky[1] = true;
	int available = 1000000;
	int deleted;
	for (int idx = 2; idx <= available; ++idx) {
		deleted = 0;
		int step = getKth(idx);
		lucky[step] = true;
		for (int i = step; i - deleted <= available; i += step) {
			delKth(i - deleted);
			available--;
			deleted++;
		}
	}
}

void solve(int n) {
	if (n & 1) { // odd = odd + even ==> we don't have even values
		cout << n << " is not the sum of two luckies!\n";
		return;
	}

	bool flag = false;
	for (int i = n / 2; i >= 1; --i) {
		if (lucky[i] and lucky[n - i]) {
			flag = true;
			cout << n << " is the sum of " << i << " and " << n - i << ".\n";
			break;
		}
	}
	if (!flag)
		cout << n << " is not the sum of two luckies!\n";

}
int main() {
	lol
	preprocess();
	int n;
	while (cin >> n)
		solve(n);
}
