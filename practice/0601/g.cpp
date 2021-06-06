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
    int n, q;
    cin >> n >> q;
    vc<int> c(n + 1), ans(n + 1), a(n + 1, 0);
    atcoder::fenwick_tree<int> BIT(n + 1);
    vvc<int> ql(n + 1), id(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        ql[r].push_back(l);
        id[r].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (a[c[i]] > 0) BIT.add(a[c[i]], -1);
        BIT.add(i, 1);
        a[c[i]] = i;
        rep(j, ql[i].size()) { ans[id[i][j]] = BIT.sum(ql[i][j] - 1, i); }
    }
    rep(i, q) cout << ans[i] << endl;
}