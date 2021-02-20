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
using Edge = pair<int, pi>;
using Graph = vc<vc<Edge>>;
int n, m, x, y;
int a, b, t, k;
Graph g;
int INF = 1e9;
void solve() {
    vc<vc<int>> dp(n, vc<int>(100100, INF));
    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>>
        que;
    dp[0][S] = 0;
    que.push(make_pair(0, pi(0, S)));
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        int time = p.first;
        int v = p.second.first;
        int s = p.second.second;
        if (time > dp[v][s]) continue;

        // 補充
        if (s + C[v] <= MAX) {
            int ns = s + C[v];
            int ntime = time + D[v];
            if (dp[v][ns] > ntime) {
                chmin(dp[v][ns], ntime);
                que.push(make_pair(ntime, pi(v, ns)));
            }
        }
        // 辺を通る
        for (auto e : G[v]) {
            if (s < e.second.first) continue;
            int nv = e.first;
            int ns = s - e.second.first;
            int ntime = time + e.second.second;
            if (dp[nv][ns] > ntime) {
                chmin(dp[nv][ns], ntime);
                que.push(make_pair(ntime, pi(nv, ns)));
            }
        }
    }
    for (int v = 1; v < N; ++v) {
        int res = INF;
        for (int s = 0; s <= MAX; ++s) {
            chmin(res, dp[v][s]);
        }
        cout << res << endl;
    }
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
    g.assign(n, vector<Edge>());
    rep(i, m) {
        cin >> a >> b >> t >> k;
        a--, b--;
        g[a].push_back(Edge(b, pi(t, k)));
        g[b].push_back(Edge(a, pi(t, k)));
    }
    solve();
}