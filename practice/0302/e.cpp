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
    int n, m;
    cin >> n >> m;
    vc<vc<int>> dp(1010, vc<int>(6));
    rep(i, 6) {
        if (i % 2 == 0)
            dp[0][i] = -1e18;
        else
            dp[0][i] = 1e18;
    }
    vc<int> a(n), b(n), c(n), d(n), e(n), f(n), g(n), h(n);
    rep(i, n) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = x - y - z;
        b[i] = x - y + z;
        c[i] = x + y + z;
        d[i] = x + y - z;
        e[i] = -x - y - z;
        f[i] = -x - y + z;
        g[i] = -x + y - z;
        h[i] = -x + y + z;
    }
    sort(ALL(a), greater<int>());
    sort(ALL(b), greater<int>());
    sort(ALL(c), greater<int>());
    sort(ALL(d), greater<int>());
    sort(ALL(e), greater<int>());
    sort(ALL(f), greater<int>());
    sort(ALL(g), greater<int>());
    sort(ALL(h), greater<int>());
    int sa = 0, sb = 0, sc = 0, sd = 0, se = 0, sf = 0, sg = 0, sh = 0;
    rep(i, m) {
        sa += a[i];
        sb += b[i];
        sc += c[i];
        sd += d[i];
        se += e[i];
        sf += f[i];
        sg += g[i];
        sh += h[i];
    }
    cout << max({sa, sb, sc, sd, se, sf, sg, sh}) << endl;
}