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
int n, m;
vc<bool> used(100100, false);
void dfs(vc<vc<pi>>& tr, vc<int>& check, int st = 0, int color = 0) {
    check[st] = color;
    for (auto u : tr[st]) {
        if (check[u.first] != -1) continue;
        if (u.second == color)
            dfs(tr, check, u.first, (u.second + 1) % n);
        else
            dfs(tr, check, u.first, u.second);
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    vc<vc<pi>> tr(n);
    rep(i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--, c--;
        tr[u].emplace_back(v, c);
        tr[v].emplace_back(u, c);
    }
    vc<int> ch(n, -1);
    dfs(tr, ch);
    rep(i, n) { cout << ch[i] + 1 << endl; }
}