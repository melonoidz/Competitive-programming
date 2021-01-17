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

struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }
    int root(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }
    bool issame(int x, int y) { return root(x) == root(y); }
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);  // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x) { return -par[root(x)]; }
};

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    vc<pair<pair<int, int>, int>> lo;
    rep(i, n) {
        int x, y, c;
        cin >> x >> y >> c;
        lo.emplace_back(make_pair(x, y), c);
    }
    vc<pair<pair<int, int>, int>> sm;
    rep(i, m) {
        int x, y, c;
        cin >> x >> y >> c;
        sm.emplace_back(make_pair(x, y), c);
    }
    double ans = 1e9;

    for (int p = 0; p < (1 << m); p++) {
        auto tmp = lo;
        for (int q = 0; q < m; q++) {
            if (p & (1 << q)) {
                tmp.emplace_back(sm[q]);
            }
        }
        vc<pair<int, pi>> cost;
        for (int i = 0; i < tmp.size(); i++) {
            for (int j = 0; j < i; j++) {
                int dist = (tmp[i].first.first - tmp[j].first.first) *
                               (tmp[i].first.first - tmp[j].first.first) +
                           (tmp[i].first.second - tmp[j].first.second) *
                               (tmp[i].first.second - tmp[j].first.second);
                if (tmp[i].second != tmp[j].second) dist *= 100;
                cost.emplace_back(dist, make_pair(i, j));
            }
        }

        sort(cost.begin(), cost.end());
        int now = 0;
        UnionFind uf(tmp.size());
        for (auto c : cost) {
            int d = c.first;
            //小さい塔は無視してもよい
            //頂点の取り方？
            if (!uf.issame(c.second.first, c.second.second)) {
                now += d;
                uf.merge(c.second.first, c.second.second);
            }
        }
        chmin(ans, sqrt(now));
    }
    cout << fixed << setprecision(20) << ans << endl;
}