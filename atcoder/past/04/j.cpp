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
int n, m, xab, xac, xbc, a, b, c;
string s;
vc<vc<pi>> edge(100100);
vector<int> dijkstra(int start) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> dist(100100, 10e14);
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
    cin >> xab >> xac >> xbc;
    cin >> s;
    rep(i, m) {
        cin >> a >> b >> c;
        a--, b--;
        edge[a].emplace_back(b, c);
        edge[b].emplace_back(a, c);
    }
    // Ain=n, Aout=n+1, Bin=n+2, Bout=n+3, Cin=n+4, Cout=n+5
    edge[n].emplace_back(n + 3, xab);
    edge[n + 2].emplace_back(n + 1, xab);
    edge[n].emplace_back(n + 5, xac);
    edge[n + 4].emplace_back(n + 1, xac);
    edge[n + 2].emplace_back(n + 5, xbc);
    edge[n + 4].emplace_back(n + 3, xbc);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            edge[i].emplace_back(n, 0);
            edge[n + 1].emplace_back(i, 0);
        } else if (s[i] == 'B') {
            edge[i].emplace_back(n + 2, 0);
            edge[n + 3].emplace_back(i, 0);
        } else {
            edge[i].emplace_back(n + 4, 0);
            edge[n + 5].emplace_back(i, 0);
        }
    }
    auto dist = dijkstra(0);
    cout << dist[n - 1] << endl;
}