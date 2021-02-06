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
int ans = 0;
bool is_tree = true;
vc<bool> check(400010, false);
int N;
vc<vc<int>> G;
void dfs(int v, int u, bool& flag) {
    if (flag) {
        check[v] = true;
        for (auto p : G[v]) {
            if (check[p]) is_tree = false;
            if (p != u) {
                dfs(p, v, is_tree);
            }
        }
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> N;
    atcoder::dsu uf(400000);
    G.resize(N + 1);
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        uf.merge(a, b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    auto pairs = uf.groups();
    int ans = 0;
    rep(i, pairs.size()) {
        is_tree = true;
        dfs(pairs[i][0], 0, is_tree);
        if (is_tree) {
            ans += pairs[i].size() - 1;
        } else {
            ans += pairs[i].size();
        }
    }
    cout << ans << endl;
    // dfsとUFの相性は悪い
    return 0;
}