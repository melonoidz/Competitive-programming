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

int dist(tuple<int, int, int> a, tuple<int, int, int> b) {
    return abs(get<0>(b) - get<0>(a)) + abs(get<1>(b) - get<1>(a)) +
           max(0LL, get<2>(b) - get<2>(a));
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vc<tuple<int, int, int>> city;
    rep(i, n) {
        int x, y, z;
        cin >> x >> y >> z;
        city.emplace_back(x, y, z);
    }
    int INF = 1e18;
    vc<vc<int>> dp(150000, vc<int>(20, INF));
    // dp[S|v][v]=chmin(dp[S|i][v],dp[S][u->v])
    dp[0][0] = 0;
    for (int s = 0; s < (1 << n); s++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (s != 0 && !(s & (1 << u))) {
                    continue;
                }
                if (u != v && !(s & (1 << v))) {
                    dp[s | (1 << v)][v] = min(
                        dp[s | (1 << v)][v], dp[s][u] + dist(city[u], city[v]));
                }
            }
        }
    }
    int ans = dp[(1 << n) - 1][0];
    if (ans == INF) ans = -1;
    cout << ans << endl;
}