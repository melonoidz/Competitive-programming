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
vc<vc<int>> tr(200200), vertexlist(200200);
vc<int> in(200200), out(200200), depth(200200);
int n, q, timer;
void dfs(const int u) {
    in[u] = timer++;
    vertexlist[depth[u]].push_back(in[u]);
    for (const int v : tr[u]) {
        depth[v] = depth[u] + 1;
        dfs(v);
    }
    out[u] = timer++;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n;
    rep(i, n - 1) {
        int p;
        cin >> p;
        p--;
        tr[p].push_back(i + 1);
    }
    dfs(0);
    cin >> q;
    rep(W, q) {
        int u, d;
        cin >> u >> d;
        u--;
        const auto& v = vertexlist[d];
        int ans = lower_bound(ALL(v), out[u]) - lower_bound(ALL(v), in[u]);
        cout << ans << endl;
    }
    return 0;
}