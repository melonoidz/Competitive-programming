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
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    vc<pi> g;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g.emplace_back(a, b);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        atcoder::dsu uf(n);
        pi node = g[i];
        for (int j = 0; j < m; j++) {
            if (g[j] == node) continue;
            uf.merge(g[j].first, g[j].second);
        }
        bool f = true;
        for (int v = 0; v < n - 1; v++) {
            for (int u = v + 1; u < n; u++) {
                if (f) {
                    if (!uf.same(v, u)) {
                        ans++;
                        f = false;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}