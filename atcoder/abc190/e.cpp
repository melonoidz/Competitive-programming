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

int n, m;
vc<vc<int>> G(100100);
vc<int> bfs(int s) {
    vc<int> dist(n, 1e18);
    dist[s] = 0;
    vc<int> check(n, 0);
    check[s] = 1;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (auto u : G[now]) {
            if (check[u] != 1) {
                check[u] = 1;
                dist[u] = min(dist[u], now + 1);
                que.push(u);
            }
        }
    }
    return dist;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    // edge, vertex(=stone)
    // bitDP?
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int k;
    cin >> k;
    vc<int> c(k, 0);
    rep(i, k) {
        cin >> c[i];
        c[i]--;
    }
    vc<vc<int>> dists;
    for (int i = 0; i < k; i++) {
        dists.emplace_back(bfs(c[i]));
    }
    vc<vc<int>> dp(1 << k, vc<int>(k, 1e18));
    rep(i, k) { dp[1 << i][i] = 1; }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            dp[(1 << i) | (1 << j)][j] = dists[i][c[j]];
        }
    }
    for (int S = 1; S < (1 << k); S++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (!(S & (1 << i))) continue;
                if (!(S & (1 << j)) && i != j) {
                    int ncost = dp[S][i] + dists[i][c[j]];
                    if (ncost < 0) ncost = 1e18;
                    dp[S | (1 << j)][j] = min(dp[S | (1 << j)][j], ncost);
                }
            }
        }
    }
    int ans = 1e18;
    rep(i, k) { ans = min(ans, dp[(1 << k) - 1][i]); }
    if (ans == 1e18) {
        cout << -1 << endl;
    } else
        cout << ans + 1 << endl;
    return 0;
}