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

vvc<int> g;
vc<int> color(210, -1);
bool flag = true;
void dfs(int x, int c, int p = -1) {
    if (color[x] != -1) {
        if (color[x] != c) flag = false;
        return;
    }
    color[x] = c;
    for (auto u : g[x]) {
        if (u != p) {
            dfs(u, c ^ 1, x);
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    g.resize(n);
    int st = -1;
    vvc<int> dp(n, vc<int>(n, 1e9));
    // 木の直径？
    rep(i, n) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                if (st == -1) st = i;
                // cout << i << " " << j << endl;
                g[i].push_back(j);
                dp[i][j] = 1;
            }
        }
    }
    if (st == -1) {
        cout << -1 << endl;
        return 0;
    }
    dfs(st, 0);
    if (!flag) {
        cout << -1 << endl;
        return 0;
    }
    int ans = -1;
    rep(i, n) dp[i][i] = 0;
    rep(k, n) {
        rep(i, n) {
            rep(j, n) { dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); }
        }
    }
    rep(i, n) { chmax(ans, *max_element(ALL(dp[i]))); }
    cout << ans + 1 << endl;
}