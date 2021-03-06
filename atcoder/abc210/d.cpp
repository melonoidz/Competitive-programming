#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define ALL(a) (a).begin(), (a).end()
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
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int h, w, c;
    cin >> h >> w >> c;
    vvc<int> a(h, vc<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    auto p = a;
    auto q = a;
    rep(i, h) {
        rep(j, w) {
            p[i][j] += c * (i + j);
            q[i][j] -= c * (i + j);
        }
    }
    // cout << "--" << endl;
    // rep(i, h) {
    //     rep(j, w) { cout << p[i][j] << " "; }
    //     cout << endl;
    // }
    // cout << "##" << endl;
    // rep(i, h) {
    //     rep(j, w) { cout << q[i][j] << " "; }
    //     cout << endl;
    // }
    auto ma = p;
    for (int i = h - 1; i >= 0; i--) {
        for (int j = w - 1; j >= 0; j--) {
            if (i + 1 < h) ma[i][j] = min(ma[i][j], ma[i + 1][j]);
            if (j + 1 < w) ma[i][j] = min(ma[i][j], ma[i][j + 1]);
        }
    }
    auto mma = q;
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w - 1; j++) {
            if (i + 1 < h) mma[i + 1][j] = min(mma[i + 1][j], mma[i][j]);
            if (j + 1 < w) mma[i][j + 1] = min(mma[i][j + 1], mma[i][j]);
        }
    }
    // cout << "$$" << endl;
    // rep(i, h) {
    //     rep(j, w) { cout << ma[i][j] << " "; }
    //     cout << endl;
    // }
    // cout << "))" << endl;
    // rep(i, h) {
    //     rep(j, w) { cout << mma[i][j] << " "; }
    //     cout << endl;
    // }
    int res = 1LL << 60;
    rep(i, h) rep(j, w) {
        int cur = 1LL << 60;
        if (i + 1 < h) chmin(cur, ma[i + 1][j]);
        if (j + 1 < w) chmin(cur, ma[i][j + 1]);
        int bef = 1LL << 60;
        if (i - 1 >= 0) chmin(bef, mma[i - 1][j]);
        if (j - 1 >= 0) chmin(bef, mma[i][j - 1]);
        chmin(res, q[i][j] + cur);
        chmin(res, p[i][j] + bef);
    }
    cout << res << endl;
}