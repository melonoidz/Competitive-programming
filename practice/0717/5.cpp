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

template <typename T> vector<vector<T>> rotateClockwise(vector<vector<T>> g) {
    int n = g.size();
    int m = g[0].size();
    vector<vector<T>> res(m, vector<T>(n));
    rep(i, n) rep(j, m) res[j][n - i - 1] = g[i][j];
    return res;
}
int h, w, c;
int solve(vvc<int>& a, int h, int w) {
    auto p = a;
    auto q = a;
    rep(i, h) {
        rep(j, w) {
            p[i][j] += c * (i + j);
            q[i][j] -= c * (i + j);
        }
    }

    auto ma = p;
    for (int i = h - 1; i >= 0; i--) {
        for (int j = w - 1; j >= 0; j--) {
            if (i + 1 < h) ma[i][j] = min(ma[i][j], ma[i + 1][j]);
            if (j + 1 < w) ma[i][j] = min(ma[i][j], ma[i][j + 1]);
        }
    }
    int res = 1e18;
    rep(i, h) rep(j, w) {
        int tmp = q[i][j];
        int cur = 1e18;
        if (i + 1 < h) chmin(cur, ma[i + 1][j]);
        if (j + 1 < w) chmin(cur, ma[i][j + 1]);

        chmin(res, tmp + cur);
    }
    return res;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> h >> w >> c;
    vvc<int> a(h, vc<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    int ans = 1LL << 60;
    chmin(ans, solve(a, h, w));
    auto b = rotateClockwise(a);
    chmin(ans, solve(b, w, h));
    cout << ans << endl;
}