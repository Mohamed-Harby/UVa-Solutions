// In the name of ALLAH the most merciful the most gracious
#include <bits/stdc++.h>
using namespace std;

#define PREC(n)		cout << fixed <<  setprecision(n);
#define lol		ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define eps 1E-10
#define pi 	2*acos(0.0)
#define inf 1.797E308
#define ll long long

int main() {
	lol
	map <int ,int> remainders; 
	vector<int> values;
	int x,y;

	while(cin >> x >> y and cin.good()){
		remainders.clear(),values.clear();
		
		int rem = (x % y)*10;
		int i = 0;
		while(!remainders.count(rem)){
		remainders[rem] = i++;
		values.push_back(rem / y);
		rem = (rem % y) *10;
		}
		int first_index_of_cycle = remainders[rem];
		cout << x <<"/"<< y <<" = "<< x/y <<".";

		int it = 0;
		//print what is before the cycle
		while(it < first_index_of_cycle and it < 50)	cout << values[it++];

		if(it >= 50) {cout << endl;continue;}

		cout << '(';
		while(it < i and it < 50)	cout << values[it++];
		if(it == i) cout << ")\n";
		else cout << "...)\n";

		cout << "   "<< i-first_index_of_cycle <<" = number of digits in repeating cycle" << endl << endl;

	}
}

