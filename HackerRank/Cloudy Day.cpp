// #pragma GCC optimize("O3")
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c> {i, j}; }
sim > auto dud(c* x) -> decltype(cout << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
	~debug() { cout << endl; }
	eni( != ) cout << boolalpha << i; ris;
}
eni( == ) ris << range(begin(i), end(i));
}
sim, class b dor(pair < b, c > d) {
	ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
	*this << "[";
	for (auto it = d.b; it != d.e; ++it)
		*this << ", " + 2 * (it == d.b) << *it;
	ris << "]";
}
#else
	sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
typedef string str;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;
typedef pair<long double, long double> pd;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<long double> vd;
typedef vector<string> vs;
typedef vector<pair<ll, ll>> vpl;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)

#define forn(i, a, b) for (int i = (a); i <= (b); i++)
#define rfor(i, b, a) for (int i = (b); i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forv(i, v) for (auto& (i) : (v))
#define trav(i, v) for (auto i = (v).begin(); i != (v).end(); i++)

#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define rall(v) (v).rbegin(), (v).rend()
#define pc(c) putchar(c)
#define gc(c) getchar(c)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define flush() cout << flush
#define max_queue(t) priority_queue<t>
#define min_queue(t) priority_queue<t,vector<t>,greater<t>>

#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define ef emplace_front
#define eb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define rsz resize
#define ins insert
#define endl "\n"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
#define shuf(v) shuffle((v).begin(), (v).end(), rng);
// Use mt19937_64 for 64 bit random numbers.

#define Set(n, i) n = (n) | (1LL << (i))
#define Reset(n, i) n = (n) & ~(1LL << (i))
#define Test(n, i) ((n) >> (i) & 1LL)
#define par(n) (n) & 1LL

inline int read() {int x; cin >> x; return x;}
inline long long readl() {long long x; cin >> x; return x;}
inline char readc() {char x; cin >> x; return x;}
inline string reads() {string x; cin >> x; return x;}

const double Pi = 3.1415926535898;
inline void solve();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cout << fixed << setprecision(10);
	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
#ifdef LOCAL
	cout << "\nTime Elapsed: " << runtime() << " sec\n";
#endif
	return 0;
}
//------------------------------------------ end -----------------------------------------------//
const int N = 1e9 + 7;
const int mod = 998244353;
vector<pair<int, int>> x, y;
vector<ll> s;
map<int, ll> sums;
inline void solve() {
	int n = read();
	rep(i, n) x.eb(0, read());
	rep(i, n) x[i].fi = read();
	int m = read();
	rep(i, m) y.eb(read(), 0);
	rep(i, m) {
		y[i].se = y[i].fi + read();
		y[i].fi = 2 * y[i].fi - y[i].se;
		s.eb(y[i].se);
	}
	sort(all(x)); sort(all(y)); sort(all(s));
	ll ans = 0, mx = 0;
	debug() << imie(y);
	rep(i, n) {
		int less = lb(all(s), x[i].fi) - s.begin();
		int ind = lb(all(y), mp(x[i].fi, N)) - y.begin();
		int cover = ind - less;
		debug() << imie(x[i])imie(ind)imie(less);
		if (cover == 0) ans += x[i].se;
		if (cover == 1) {
			while (y[ind - 1].se < x[i].fi) ind--;
			if (sums.find(ind - 1) == sums.end())
				sums[ind - 1] = x[i].se;
			else sums[ind - 1] += x[i].se;
		}
	}
	trav(it, sums) mx = max(it->se, mx);
	cout << ans + mx << endl;
}