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
int n, ans = 0;
vvc<int> t(100100);
vc<int> dp(100100, 0);
vc<pi> edge;
void dfs(int x, int p = -1) {
    dp[x] = 1;
    for (auto u : t[x]) {
        if (u != p) {
            dfs(u, x);
            dp[x] += dp[u];
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    //主客転倒
    //部分木を考える．u*v
    cin >> n;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        t[a].push_back(b);
        t[b].push_back(a);
        edge.emplace_back(a, b);
    }
    dfs(0);
    rep(i, n) { ans += dp[i] * (n - dp[i]); }
    cout << ans << endl;
}