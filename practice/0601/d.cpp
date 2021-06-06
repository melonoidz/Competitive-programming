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
int n, m, s, t, x, y, d;
vector<pi> edge[1100000];
vector<int> dijkstra(int start) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> dist(n, 10e9);
    dist[start] = 0;
    pq.push(pi(dist[start], start));
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int d = p.first;
        int from = p.second;
        if (dist[from] < d) continue;
        for (auto nxt : edge[from]) {
            int to = nxt.first;
            int c = nxt.second;
            if (dist[from] + c < dist[to]) {
                dist[to] = dist[from] + c;
                pq.push(pi(dist[to], to));
            }
        }
    }
    return dist;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    cin >> s >> t;
    s--, t--;
    rep(i, m) {
        cin >> x >> y >> d;
        x--, y--;
        edge[x].emplace_back(y, d);
        edge[y].emplace_back(x, d);
    }
    auto st = dijkstra(s);
    auto gl = dijkstra(t);
    for (int u = 0; u < n; u++) {
        if (u == s || u == t) continue;
        if (st[u] == gl[u] && st[u] != 10e9) {
            cout << u + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}