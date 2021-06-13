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
int N, M, X, Y, A, B, C, D;
double f(double x, int C, int D) {
    double q = D / (x + 1);
    return q + C;
}
// tk cd
struct Edge {
    int to;
    int c;
    int d;
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
            int to = u.to;
            int C = u.c;
            int D = u.d;
            int t = dist[from];
            int ntime = 2e18;
            int k = sqrt(double(D));
            rep(i, 5) {
                int s = k - 3 + i;
                if (s < 0 || s < t) continue;
                ntime = min(ntime, C + (s - t) + D / (s + 1));
            }
            //差分だけ計算する
            ntime = min(ntime, C + D / (t + 1));
            if (dist[to] > ntime + t) {
                dist[to] = ntime + t;
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
    cin >> N >> M;
    if (M == 0) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, M) {
        cin >> A >> B >> C >> D;
        A--, B--;
        G[A].push_back({B, C, D});
        G[B].push_back({A, C, D});
    }
    auto res = dijkstra(0);
    int ans = res[N - 1];
    if (ans == 1e18) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}