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
int n, x, y;
map<pi, int> res, a;
vc<pi> d{pi(1, 1), pi(0, 1), pi(-1, 1), pi(1, 0), pi(-1, 0), pi(0, -1)};
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> x >> y;
    rep(i, n) {
        int p, q;
        cin >> p >> q;
        a[pi(q, p)] = 1;
    }
    queue<pair<pi, int>> Q;
    Q.push(make_pair(pi(0, 0), 0));
    res[pi(0, 0)] = 0;
    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        auto nx = p.first.first;
        auto ny = p.first.second;
        auto ncnt = p.second;
        if (nx == x && ny == y) {
            cout << res[pi(ny, nx)] << endl;
            return 0;
        }
        if (res[pi(ny, nx)] != 0 && res[pi(ny, nx)] < ncnt) continue;
        for (auto u : d) {
            auto tx = nx + u.first;
            auto ty = ny + u.second;
            if (a[pi(ty, tx)] == 1) continue;
            if (res[pi(ty, tx)] == 0 || res[pi(ty, tx)] > ncnt + 1) {
                res[pi(ty, tx)] = ncnt + 1;
                Q.push(make_pair(pi(tx, ty), ncnt + 1));
            }
        }
    }
    cout << res[pi(y, x)] << endl;
}