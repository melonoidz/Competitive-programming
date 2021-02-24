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
int N, M, X, Y;
int A, B, T, K;
struct Edge {
    int to;
    int cost;
    int k;
};
vector<Edge> edge[1100000];
vector<int> dijkstra(int start) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> dist(N, 1e18);
    dist[start] = 0;
    pq.push(pi(0, start));
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int d = p.first;
        int from = p.second;
        if (dist[from] < d) continue;
        for (auto nxt : edge[from]) {
            int to = nxt.to;
            int c = nxt.cost;
            int k = nxt.k;
            int nt;
            if (dist[from] % k == 0) {
                nt = dist[from] + c;
            } else {
                nt = (dist[from] / k + 1) * k + c;
            }
            if (dist[to] > nt) {
                dist[to] = nt;
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
    cin >> N >> M >> X >> Y;
    X--, Y--;
    if (M == 0) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, M) {
        cin >> A >> B >> T >> K;
        A--, B--;
        edge[A].push_back({B, T, K});
        edge[B].push_back({A, T, K});
    }
    auto res = dijkstra(X);
    auto ans = res[Y];
    if (ans == 1e18) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}