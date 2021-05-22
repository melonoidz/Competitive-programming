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
vc<vc<int>> tree;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    tree.resize(n);
    atcoder::dsu uf(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
        uf.merge(a, b);
    }
    vc<int> cnt;
    auto groups = uf.groups();
    for (auto gp : groups) {
        int l = gp.size();
        auto st = gp.front();
        map<int, int> now;
        for (int i = 0; i < l; i++) {
            now[gp[i]] = i;
        }
        int res = 0;
        for (int bit = 0; bit < (1 << l); bit++) {
            bool ok = true;
            for (int i = 0; i < l; i++) {
                if (i == 0) continue;
                if (bit & (1 << i)) {
                    for (auto u : tree[gp[i]]) {
                        auto ind = now[u];
                        if (u != st && (bit & (1 << ind))) ok = false;
                    }
                } else {
                    for (auto u : tree[gp[i]]) {
                        auto ind = now[u];
                        if (u != st && (bit & (1 << ind)) == 0) ok = false;
                    }
                }
            }
            if (ok) res += 3;
        }
        cnt.push_back(res);
    }
    int ans = 1LL;
    for (auto u : cnt) ans *= u;
    cout << ans << endl;
}