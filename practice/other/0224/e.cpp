#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
template <class t, class u> void chmax(t& a, u b) {
    if (a < b) a = b;
}
template <class t, class u> void chmin(t& a, u b) {
    if (b < a) a = b;
}
template <class t> using vc = vector<t>;
template <class t> using vvc = vc<vc<t>>;
using pi = pair<int, int>;
using vi = vc<int>;
using uint = unsigned;
using ull = unsigned long long;
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
int lcm(int a, int b) { return a / __gcd(a, b) * b; }
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
    int x;
    mint(int x = 0) : x((x % mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(int t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vc<int> t(n), a(n);
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> a[i];
    mint ans = 1;
    if (a[0] != t[n - 1]) {
        cout << 0 << endl;
        return 0;
    }
    bool ok = true;
    rep(i, n - 1) {
        if (t[i] > t[i + 1]) ok = false;
    }
    for (int i = n - 1; i > 0; i--) {
        if (a[i] > a[i - 1]) ok = false;
    }
    if (!ok) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1) continue;
        if (t[i - 1] < t[i]) {
            if (t[i] > a[i]) ans *= 0;
            if (a[i] > a[i + 1]) {
                if (t[i] != a[i]) {
                    ans *= 0;
                } else {
                    ans *= 1;
                }
            }
        }
        if (a[i] > a[i + 1]) {
            if (a[i] > t[i]) ans *= 0;
            if (t[i - 1] < t[i]) {
                if (a[i] != t[i]) {
                    ans *= 0;
                } else
                    ans *= 1;
            }
        } else if (!(a[i] > a[i + 1]) && !(t[i - 1] < t[i])) {
            ans *= min(t[i], a[i]);
        }
    }
    cout << ans << endl;
}