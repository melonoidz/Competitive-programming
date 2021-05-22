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
    int mx = 1e18, my = 1e18, lx = 0, ly = 0;
    vc<pi> points;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        int nx = x - y;
        int ny = x + y;
        points.emplace_back(nx, ny);
        chmin(mx, nx);
        chmin(my, ny);
        chmax(lx, nx);
        chmax(ly, ny);
    }
    rep(i, q) {
        int j;
        cin >> j;
        j--;
        auto p = points[j];
        cout << max({abs(p.first - mx), abs(p.first - lx), abs(p.second - my),
                     abs(p.second - ly)})
             << endl;
    }
}