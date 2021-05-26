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
vc<vc<int>> t(110);
int n, x, ans = 1e9;
vc<int> h(110);
int dfs(int now, int par = -1) {
    int r = 0, x;
    int ndist = 0;
    if (h[now]) ndist = 2;
    for (auto u : t[now]) {
        if (u != par) {
            x = dfs(u, now);
            if (x > 0) {
                ndist = 2;
                r += x;
            }
        }
    }
    return ndist + r;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> x;
    x--;
    rep(i, n) cin >> h[i];
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    int res = dfs(x);
    cout << max(0LL, res - 2) << endl;
}