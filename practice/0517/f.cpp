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
    int n;
    cin >> n;
    int ans = 0LL;
    vc<pi> xdist, ydist;
    atcoder::dsu uf(100100);
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        xdist.emplace_back(x, i);
        ydist.emplace_back(y, i);
    }
    sort(ALL(xdist));
    sort(ALL(ydist));
    vc<pair<int, pi>> dist;
    for (int i = 0; i < xdist.size() - 1; i++) {
        int tmp = xdist[i + 1].first - xdist[i].first;
        dist.emplace_back(tmp, make_pair(xdist[i + 1].second, xdist[i].second));
    }
    for (int i = 0; i < ydist.size() - 1; i++) {
        int tmp = ydist[i + 1].first - ydist[i].first;
        dist.emplace_back(tmp, make_pair(ydist[i + 1].second, ydist[i].second));
    }
    sort(ALL(dist));
    for (auto u : dist) {
        auto d = u.first;
        auto p = u.second.first;
        auto q = u.second.second;
        if (!uf.same(p, q)) {
            uf.merge(p, q);
            ans += d;
        }
    }
    cout << ans << endl;
}