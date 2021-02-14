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
int N, M, A, B, C;
vc<pi> edge[2010];
vc<pi> revedge[2010];

vc<int> dijk(int start) {
    vc<int> dist(N, 1e9);
    dist[start] = 0;
    priority_queue<pi, vc<pi>, greater<pi>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        int from = tmp.second;
        if (dist[from] < tmp.first) continue;
        for (auto e : edge[from]) {
            auto to = e.first;
            auto cost = e.second;
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
                pq.push({dist[to], to});
            }
        }
    }
    return dist;
}

vc<int> revdijk(int start) {
    vc<int> dist(N, 1e9);
    dist[start] = 0;
    priority_queue<pi, vc<pi>, greater<pi>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        int from = tmp.second;
        if (dist[from] < tmp.first) continue;
        for (auto e : revedge[from]) {
            auto to = e.first;
            auto cost = e.second;
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
                pq.push({dist[to], to});
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
    rep(i, M) {
        cin >> A >> B >> C;
        A--, B--;
        edge[A].push_back({B, C});
        revedge[B].push_back({A, C});
    }
    for (int i = 0; i < N; i++) {
        auto d = dijk(i);
        auto revd = revdijk(i);
        int res = 1e10;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int tmp = d[j] + revd[j];
            // cout << tmp << endl;
            res = min(res, tmp);
        }
        for (auto e : edge[i]) {
            if (e.first == i) {
                res = min(res, e.second);
            }
        }
        if (res >= 1e9)
            cout << -1 << endl;
        else
            cout << res << endl;
    }
    return 0;
}