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
const int kMod = 163577857;
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
    ModInt r;
    e = e % (kMod - 1);
    if (e < 0) e += kMod - 1;
    for (r = 1; e; e >>= 1, b = b * b)
        if (e & 1) r = r * b;
    return r;
}
vector<ModInt> fact, invfact;
void factorials(int n) {
    fact.resize(n + 1, 1);
    invfact.resize(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i;
    invfact[n] = lgpow(fact[n]);
    for (int i = n - 1; i >= 1; --i)
        invfact[i] = invfact[i + 1] * (i + 1);
}
ModInt choose(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] * invfact[n - k];
}
class NumberTheoreticTransform {
   private:
    int root, root_1, root_pw;
    void fft(vector<ModInt>& a, bool invert) {
        int n = a.size();
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1)
                j ^= bit;
            j ^= bit;
            if (i < j)
                swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) {
            ModInt wlen = invert ? root_1 : root;
            for (int i = len; i < root_pw; i <<= 1)
                wlen = wlen * wlen;
            for (int i = 0; i < n; i += len) {
                ModInt w = 1;
                for (int j = 0; j < len / 2; j++) {
                    ModInt u = a[i + j];
                    ModInt v = a[i + j + len / 2] * w;
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                    w = w * wlen;
                }
            }
        }
        if (invert) {
            ModInt invN = lgpow(n);
            for (int i = 0; i < n; i++)
                a[i] = a[i] * invN;
        }
    }

   public:
    NumberTheoreticTransform() {
        int N = 20;
        ModInt cur = 0;
        for (int i = 2;; ++i) {
            bool ok = true;
            for (int j = 1; j < N; ++j) {
                cur = lgpow(i, 1 << j);
                if (cur.get() == 1) {
                    ok = false;
                    break;
                }
            }
            cur = lgpow(i, 1 << N);
            if (ok && cur.get() == 1) {
                root = i;
                root_1 = lgpow(root).get();
                root_pw = 1 << N;
                return;
            }
        }
    }
    vector<ModInt> multiply(vector<ModInt> const& a, vector<ModInt> const& b) {
        vector<ModInt> fa = a, fb = b;
        int n = 1, tot = a.size() + b.size();
        while (n < tot) n <<= 1;
        fa.resize(n), fb.resize(n);
        fft(fa, false), fft(fb, false);
        for (int i = 0; i < n; i++)
            fa[i] = fa[i] * fb[i];
        fft(fa, true);
        vector<ModInt> result(tot - 1);
        for (int i = 0; i < tot - 1; i++)
            result[i] = fa[i];
        return result;
    }
};
NumberTheoreticTransform ntt;
void solve() {
    int n, plus = 0, minus = 0, zero = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        if (e == -1) minus++;
        if (e == 1) plus++;
        if (e == 0) zero++;
    }
    factorials(max(plus, minus) + 5);
    vector<ModInt> pos(n + 1, 0), neg(n + 1, 0);
    for (int i = 0; i <= plus; i++)
        pos[i] = choose(plus, i);
    for (int i = 0; i <= minus; i++)
        neg[i] = choose(minus, i);
    reverse(all(neg));
    vector<ModInt> ans = ntt.multiply(pos, neg);
    ModInt pw = lgpow(2, zero);
    for (int i = 0; i <= 2 * n; i++)
        ans[i] = ans[i] * pw;
    ans[n] = ans[n] - 1;
    for (int i = 0; i <= 2 * n; i++)
        cout << ans[i].get() << ' ';
    cout << '\n';
}
void solve2() {
    int n, plus = 0, minus = 0, zero = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        if (e == -1) minus++;
        if (e == 1) plus++;
        if (e == 0) zero++;
    }
    factorials(plus + minus + 5);
    ModInt pw = lgpow(2, zero), cur;
    for (int i = -n; i <= n; i++) {
        cur = pw * choose(plus + minus, plus - i);
        if (i == 0) cur = cur - 1;
        cout << cur.get() << ' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve2();
}