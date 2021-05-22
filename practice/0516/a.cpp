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
vc<vc<int>> blocked(505, vc<int>(505, 0)), mi(505, vc<int>(505, 0));
const int MA = 500;
const int BASE = 250;
vc<vc<bool>> vis(505, vc<bool>(505, false));
vc<pi> d{pi(1, 1), pi(0, 1), pi(-1, 1), pi(1, 0), pi(-1, 0), pi(0, -1)};
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> x >> y;
    x += BASE;
    y += BASE;
    rep(i, n) {
        int p, q;
        cin >> p >> q;
        blocked[q + BASE][p + BASE] = 1;
    }
    queue<pi> que;
    que.push(pi(BASE, BASE));
    vis[BASE][BASE] = true;
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        auto nx = p.first;
        auto ny = p.second;
        for (const auto& [dx, dy] : d) {
            int xx = nx + dx;
            int yy = ny + dy;
            if (0 <= xx && xx < MA && 0 <= yy && yy < MA) {
                if (blocked[yy][xx] == 1) continue;
                if (vis[yy][xx]) continue;
                vis[yy][xx] = true;
                mi[yy][xx] = mi[ny][nx] + 1;
                que.push(pi(xx, yy));
            }
        }
    }
    if (vis[y][x])
        cout << mi[y][x] << endl;
    else
        cout << -1 << endl;
}