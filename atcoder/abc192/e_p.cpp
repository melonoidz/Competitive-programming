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
int N, M, X, Y, A, B, T, K;
struct Edge {
    int to;
    int cost;
    int k;
};
vc<Edge> G[220220];
vc<int> dijkstra(int s) {
    vc<int> dist(N, 1e18);
    priority_queue<pi, vc<pi>, greater<pi>> pq;
    dist[s] = 0;
    pq.push(pi(dist[s], s));
    while (!pq.empty()) {
        auto d = pq.top().first;
        auto from = pq.top().second;
        pq.pop();
        if (dist[from] < d) continue;
        for (auto u : G[from]) {
            int nt = u.to;
            int nc = u.cost;
            int nk = u.k;
            int ntime = 0;
            if (dist[from] % nk != 0) {
                ntime = (dist[from] / nk + 1) * nk + nc;
            } else {
                ntime = dist[from] + nc;
            }
            if (dist[nt] > ntime) {
                dist[nt] = ntime;
                pq.push(pi(dist[nt], nt));
            }
        }
    }
    return dist;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> N >> M >> X >> Y;
    if (M == 0) {
        cout << -1 << endl;
        return 0;
    }
    X--, Y--;
    rep(i, M) {
        cin >> A >> B >> T >> K;
        A--, B--;
        G[A].push_back({B, T, K});
        G[B].push_back({A, T, K});
    }
    auto res = dijkstra(X);
    int ans = res[Y];
    if (ans == 1e18) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}