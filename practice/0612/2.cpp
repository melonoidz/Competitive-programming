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
void visit(int v, vc<int>& s, vc<bool>& visited) {
    visited[v] = true;
    s.push_back(v);
    for (auto w : g[v]) {
        if (!visited[w]) {
            visit(w, s, visited);
        }
    }
}
int paint(int p, vc<int>& c, vc<int>& s) {
    // c used
    int v = s[p];
    for (auto w : g[v]) {
        if (c[v] == c[w]) {
            return 0;
        }
    }
    if (p == s.size() - 1) {
        // goal
        return 1;
    }
    int ret = 0;
    rep(i, 3) {
        c[s[p + 1]] = i;
        ret += paint(p + 1, c, s);
    }
    c[s[p + 1]] = -1;  // 元に戻す？
    return ret;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vc<bool> visited(n, false);
    int ans = 1;
    rep(i, n) {
        if (!visited[i]) {
            vc<int> s;
            visit(i, s, visited);  //到達順
            //帰り
            vc<int> c(n, -1);
            c[i] = 0;  // startは0
            ans *= paint(0, c, s) * 3;
        }
    }
    cout << ans << endl;
}