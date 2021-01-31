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
int n;
vc<vc<int>> g;
vc<int> c, ans;
int itr = 0;
void dfs(int v, int p) {
    ans[v] = c[itr++];
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n;
    g.resize(n);
    c.resize(n);
    ans.resize(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    rep(i, n) cin >> c[i];
    sort(c.begin(), c.end(), greater<int>());
    int score =
        accumulate(c.begin(), c.end(), 0LL) - *max_element(c.begin(), c.end());
    dfs(0, -1);
    cout << score << endl;
    rep(i, n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}