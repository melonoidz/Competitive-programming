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
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int w;
    cin >> w;
    int n, k;
    cin >> n >> k;
    vc<pi> l;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        l.emplace_back(a, b);
    }
    // dp[i][j][m]：i枚までみてj枚使用して幅がmのときの重要度max(v)
    vc<vvc<int>> dp(55, vvc<int>(55, vc<int>(10010)));
    rep(i, n) {
        for (int j = 0; j < k; j++) {
            for (int m = 0; m <= w; m++) {
                if (m - l[i].first >= 0)
                    dp[i + 1][j + 1][m] =
                        max(dp[i + 1][j + 1][m],
                            dp[i][j][m - l[i].first] + l[i].second);
                chmax(dp[i + 1][j][m], dp[i][j][m]);
                if (i >= j) chmax(dp[i + 1][j + 1][m], dp[i][j + 1][m]);
            }
        }
    }
    int ans = 0;
    rep(i, k + 1) {
        rep(j, w + 1) { chmax(ans, dp[n][i][j]); }
    }
    cout << ans << endl;
}