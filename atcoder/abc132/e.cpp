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
vc<vc<int>> dp(100100, vc<int>(3, 1e9));
vc<bool> check(100100, false);
int S, T;
void bfs() {
    dp[S][0] = 0;
    queue<int> que;
    que.push(S);
    while (!que.empty()) {
        auto now = que.front();
        que.pop();
        for (auto p : G[now]) {
            for (int turn = 0; turn < 3; turn++) {
                if (turn == 0) {
                    if (dp[p][turn + 1] == 1e9) {
                        if (dp[p][turn + 1] <= (dp[now][turn] + 1)) continue;
                        dp[p][turn + 1] = dp[now][turn] + 1;
                        que.push(p);
                    }
                } else {
                    if (dp[p][(turn + 1) % 3] == 1e9) {
                        if (dp[p][(turn + 1) % 3] <= dp[now][turn]) continue;
                        dp[p][(turn + 1) % 3] = dp[now][turn];
                        que.push(p);
                    }
                }
            }
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }
    cin >> S >> T;
    S--, T--;
    bfs();
    if (dp[T][0] == 1e9)
        cout << -1 << endl;
    else
        cout << dp[T][0] << endl;
    return 0;
}