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
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    atcoder::dsu uf(200);
    vc<int> ch(110, 0);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        if (uf.same(u, v)) {
            ch[u] = 1;
            ch[v] = 1;
        }
        uf.merge(u, v);
    }
    set<int> res;
    set<int> dub;
    for (int i = 1; i <= n; i++) {
        res.insert(uf.leader(i));
        if (ch[i] == 1) {
            auto gr = uf.leader(i);
            dub.insert(gr);
        }
    }
    cout << res.size() - dub.size() << endl;
}