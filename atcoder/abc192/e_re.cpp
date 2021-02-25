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
int n, m, x, y;
int a, b, t, k;

struct Edge {
    int to;
    int cost;
    int k;
};
vc<Edge> G[100100];
vc<int> dijkstra(int st) {
    vc<int> dist(n, 1e18);
    priority_queue<pi, vc<pi>, greater<pi>> pq;
    dist[st] = 0;
    pq.push(pi(dist[st], st));
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        auto d = p.first;
        auto from = p.second;
        if (dist[from] < d) continue;
        for (auto nxt : G[from]) {
            int to = nxt.to;
            int c = nxt.cost;
            int k = nxt.k;
            int ntime = 0;
            if (dist[from] % k != 0) {
                ntime = (dist[from] / k + 1) * k + c;
            } else {
                ntime = dist[from] + c;
            }
            if (dist[to] > ntime) {
                dist[to] = ntime;
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
    cin >> n >> m >> x >> y;
    if (m == 0) {
        cout << -1 << endl;
        return 0;
    }
    x--, y--;
    rep(i, m) {
        cin >> a >> b >> t >> k;
        a--, b--;
        G[a].push_back({b, t, k});
        G[b].push_back({a, t, k});
    }
    auto res = dijkstra(x);
    if (res[y] == 1e18) {
        cout << -1 << endl;
    } else {
        cout << res[y] << endl;
    }
}