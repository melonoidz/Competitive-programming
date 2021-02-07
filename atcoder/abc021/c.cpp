#include <bits/stdc++.h>
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

const int mod = 1000000007;
int n;
int s, t;
int m;
int mincost[110];
vc<vc<int>> G(110);

void bfs1() {
    queue<pi> que;
    rep(k, 110) mincost[k] = 117117;
    que.push(make_pair(0, s));  // start地点cost0
    while (!que.empty()) {
        int cost = que.front().first;
        int v = que.front().second;
        que.pop();

        if (mincost[v] <= cost) {
            continue;
        }
        mincost[v] = cost;
        for (auto gl : G[v]) {
            que.push(make_pair(cost + 1, gl));
        }
    }
}
//その地点からの最短距離を求めておいて，dpに生かす
int dp[110] = {0};
int see[110] = {0};
int bfs2() {
    queue<pi> que;
    dp[s] = 1;
    que.push(make_pair(0, s));
    while (!que.empty()) {
        auto cost = que.front().first;
        int v = que.front().second;
        que.pop();
        if (see[v]) continue;
        see[v] = 1;
        for (int i = 0; i < G[v].size(); i++) {
            if (mincost[G[v][i]] == cost + 1) {
                dp[G[v][i]] += dp[v];
                dp[G[v][i]] %= mod;
                que.push(make_pair(cost + 1, G[v][i]));
            }
        }
    }
    return (dp[t] + mod) % mod;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n;
    cin >> s >> t;
    s--, t--;
    cin >> m;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    bfs1();
    auto res = bfs2();
    cout << res << endl;
    return 0;
}