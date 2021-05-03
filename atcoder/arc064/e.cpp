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
int sx, sy, gx, gy;
int n;
vc<pair<pi, int>> b;
vc<vc<pair<int, double>>> path(1100);
vector<double> dijkstra(int start) {
    priority_queue<pair<double, int>, vector<pair<double, int>>,
                   greater<pair<double, int>>>
        pq;
    vector<double> dist(1100, 10000000000000.0);
    dist[start] = 0.0;
    pq.push(make_pair(dist[start], start));
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        double d = p.first;
        int from = p.second;
        if (dist[from] < d) continue;
        for (auto nxt : path[from]) {
            int to = nxt.first;
            double c = nxt.second;
            if (dist[from] + c < dist[to]) {
                dist[to] = dist[from] + c;
                pq.push(make_pair(dist[to], to));
            }
        }
    }
    return dist;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> sx >> sy >> gx >> gy;
    cin >> n;
    auto start = make_pair(pi(sx, sy), 0);
    auto goal = make_pair(pi(gx, gy), 0);
    b.push_back(start);
    b.push_back(goal);
    // start=0,goal=1
    rep(i, n) {
        int x, y, r;
        cin >> x >> y >> r;
        auto tmp = make_pair(pi(x, y), r);
        b.push_back(tmp);
    }
    // start,goal含めてn+2頂点とする
    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            auto dist = (b[i].first.first - b[j].first.first) *
                            (b[i].first.first - b[j].first.first) +
                        (b[i].first.second - b[j].first.second) *
                            (b[i].first.second - b[j].first.second);
            auto now = sqrt(dist) - double(b[i].second + b[j].second);
            auto cost = max(0.0, now);
            path[i].emplace_back(j, cost);
            path[j].emplace_back(i, cost);
        }
    }
    auto cur = dijkstra(0);
    cout << cur[1] << endl;
}