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
    vvc<int> a(h, vc<int>(w)), b(h, vc<int>(w));
    int sa = 0, sb = 0;
    rep(i, h) { rep(j, w) cin >> a[i][j], sa += a[i][j]; }
    rep(i, h) { rep(j, w) cin >> b[i][j], sb += b[i][j]; }
    if ((sa - sb) % 4 != 0) {
        cout << "No" << endl;
        return 0;
    }
    int diff = 0;

    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w - 1; j++) {
            int tmp = b[i][j] - a[i][j];
            rep(x, 2) rep(y, 2) { a[i + x][j + y] += tmp; }
            diff += abs(tmp);
        }
    }
    bool same = true;
    rep(i, h - 1) rep(j, w - 1) {
        if (a[i][j] != b[i][j]) same = false;
    }
    if (!same) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        cout << diff << endl;
    }
}