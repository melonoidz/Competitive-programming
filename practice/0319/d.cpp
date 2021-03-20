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
    int n, m, q;
    cin >> n >> m >> q;
    vc<pi> wv(n);
    rep(i, n) {
        int w, v;
        cin >> w >> v;
        wv[i] = pi(w, v);
    }
    vc<int> x(m);
    rep(i, m) cin >> x[i];
    rep(Z, q) {
        int l, r;
        cin >> l >> r;
        l--;
        vc<int> tmp;
        for (int i = 0; i < m; i++) {
            if (!(l <= i && i < r)) {
                tmp.push_back(x[i]);
            }
        }
        sort(ALL(tmp));
        vc<int> check(n, 0), cost(tmp.size(), 0);
        for (int u = 0; u < tmp.size(); u++) {
            int num = -1;
            int now = -1;
            for (int v = 0; v < n; v++) {
                if (wv[v].first <= tmp[u] && check[v] == 0) {
                    if (now < wv[v].second) {
                        now = wv[v].second;
                        num = v;
                    }
                }
            }
            if (!(num == -1 || now == -1)) {
                check[num] = 1;
                cost[u] = now;
            }
        }
        cout << accumulate(ALL(cost), 0LL) << endl;
    }
}