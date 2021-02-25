#include <bits/stdc++.h>
// #include <atcoder/all>
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
int cur(int n, int p) {
    if (p < n) {
        return n - p;
    }
    if (p % n == 0) {
        return 0;
    }
    int res = 0;
    if (n % p != 0) {
        res = (p / n + 1) * n - p;
    }
    return res;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int t;
    cin >> t;
    rep(i, t) {
        int p, a, b, c;
        cin >> p >> a >> b >> c;
        cout << min({cur(a, p), cur(b, p), cur(c, p)}) << endl;
    }
}