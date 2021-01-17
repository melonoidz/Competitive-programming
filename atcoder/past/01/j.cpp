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
int h, w;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vc<vc<int>> g, dist;
vc<vc<int>> dijkstra_grid(int sy, int sx) {
    dist.assign(h, vc<int>(w, 10e10));
    dist[sy][sx] = 0;
    priority_queue<pair<int, pi>, vc<pair<int, pi>>, greater<pair<int, pi>>> pq;
    pq.push(make_pair(0LL, make_pair(sy, sx)));

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int c = p.first;
        int vy = p.second.first;
        int vx = p.second.second;
        rep(i, 4) {
            int nx = vx + dx[i];
            int ny = vy + dy[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (dist[ny][nx] <= g[ny][nx] + c) continue;
            dist[ny][nx] = g[ny][nx] + c;
            pq.push(make_pair(dist[ny][nx], make_pair(ny, nx)));
        }
    }
    return dist;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> h >> w;
    g.assign(h, vc<int>(w, 10e10));
    rep(i, h) rep(j, w) cin >> g[i][j];
    int cost = 10e10;
    auto a = dijkstra_grid(h - 1, 0);
    auto b = dijkstra_grid(h - 1, w - 1);
    auto c = dijkstra_grid(0, w - 1);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int tmp = a[i][j] + b[i][j] + c[i][j] - g[i][j] * 2;
            cost = min(cost, tmp);
        }
    }
    cout << cost << endl;
}