#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lol ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
	lol
	 ll t; cin >> t;
	 ll n;
	 for(ll s=0;s<t;s++){
		 cin >> n;
		 vector<ll> v(n);
		 for(ll i=0;i<n;i++) cin >> v[i];
		 ll max_diff = v[0];

		 for(ll i=0;i<n-1;i++)
			 max_diff = max(max_diff,v[i+1]-v[i]);

		 ll k = max_diff;
		 ll cnt = 0;
		 if(v[0] == k)k--;
		 for(ll i=0;i<n-1;i++){
			 if(v[i+1]-v[i] == k) k--;
			 else if(v[i+1]-v[i] > k){
				 cnt++; break;
			 }
		 }
		 ll res = max_diff + cnt;
		 cout << "Case "<<s+1 << ": "<< res << "\n";
	 }
}
