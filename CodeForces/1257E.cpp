#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >=0; i--)
#define forv(i, v) for (auto i = v.begin(); i != v.end(); i++)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define pp pair<int, int>
#define vi vector<int>
const int N = int(1e9);
int kn = 3, n, el, ind;
vi k(kn), a, res;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	rep(i, kn) cin >> k[i];
	n = accumulate(all(k), 0); a.resize(n);
	rep(i, kn) rep(j, k[i]) cin >> el, a[el - 1] = i;
	rep(i, n) {
		ind  = ub(all(res), a[i]) - res.begin();
		if (ind < sz(res)) res[ind] = a[i];
		else res.pb(a[i]);
	}
	cout << n - sz(res) << endl;
	return 0;
}