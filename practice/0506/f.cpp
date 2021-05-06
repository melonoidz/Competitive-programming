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
int n;
vc<vc<int>> tree(100100);
int dist = 0;
int ind = 0;
void dfs(int st = 0, int p = -1, int d = 0) {
    if (d > dist) {
        dist = d;
        ind = st;
    }
    for (auto u : tree[st]) {
        if (u != p) {
            dfs(u, st, d + 1);
        }
    }
}
int glind = 0, gldist = 0;
void dfs2(int st, int p = -1, int now = 0) {
    if (now > gldist) {
        gldist = now;
        glind = st;
    }
    for (auto u : tree[st]) {
        if (u != p) {
            dfs2(u, st, now + 1);
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs();
    dfs2(ind);
    cout << gldist + 1 << endl;
}