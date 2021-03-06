#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int N = 1e6 + 10;
const int kMod = 1e9 + 7;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
};
ModInt lgpow(ModInt b, int e = -1) {
    if (b.get() == 0) return 0;
    ModInt r; e = e % (kMod - 1);
    if (e < 0) e += kMod - 1;
    for (r = 1; e; e >>= 1, b = b * b)
        if (e & 1) r = r * b;
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        if (e != 1) a.pb(e);
    }
    n = a.size();
    sort(a.begin(), a.end());
    int m = a.back() + 10;
    vector<ModInt> dp(m, 1);
    ModInt res, ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int v = a[i] * a[j];
            if (v >= m) break;
            res = dp[a[i]] * dp[a[j]];
            if (j != i) res = res * 2;
            dp[v] = dp[v] + res;
        }
    }
    for (int i = 0; i < n; i++)
        ans = ans + dp[a[i]];
    cout << ans.get() << '\n';
}