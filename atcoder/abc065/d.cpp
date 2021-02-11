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

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vc<pi> X;
    vc<pi> Y;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        X.emplace_back(x, i + 1);
        Y.emplace_back(y, i + 1);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    vc<pair<int, pi>> Edge;
    for (int i = 0; i < n - 1; i++) {
        pi xuv = pi(X[i].second, X[i + 1].second);
        auto ex = make_pair(X[i + 1].first - X[i].first, xuv);
        pi yuv = pi(Y[i].second, Y[i + 1].second);
        auto ey = make_pair(Y[i + 1].first - Y[i].first, yuv);
        Edge.push_back(ex);
        Edge.push_back(ey);
    }
    sort(Edge.begin(), Edge.end());
    atcoder::dsu uf(100100);
    int cost = 0;
    for (auto e : Edge) {
        pi con = e.second;
        if (uf.same(con.first, con.second)) continue;
        cost += e.first;
        uf.merge(con.first, con.second);
    }
    cout << cost << endl;
    return 0;
}