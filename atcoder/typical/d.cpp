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
    int h, w;
    cin >> h >> w;
    vc<vc<int>> a(h, vc<int>(w, 0)), sa(h, vc<int>(w + 1, 0)),
        sh(h + 1, vc<int>(w, 0));
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h) {
        for (int j = 0; j < w; j++) {
            sa[i][j + 1] = sa[i][j] + a[i][j];
        }
    }
    rep(i, h) rep(j, w) { sh[i + 1][j] = sh[i][j] + a[i][j]; }
    rep(i, h) {
        rep(j, w) { cout << sa[i].back() + sh[h][j] - a[i][j] << " "; }
        cout << endl;
    }
}