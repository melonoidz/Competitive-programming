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
    //表がj枚の確率を求めて，足す．
    int n;
    cin >> n;
    vc<double> p(n);
    rep(i, n) cin >> p[i];
    vvc<double> dp(n + 1, vc<double>(n + 1, 0.0));
    dp[0][0] = 1.0;
    rep(i, n) { dp[i + 1][0] = dp[i][0] * (1.0 - p[i]); }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] =
                dp[i - 1][j - 1] * p[i - 1] + dp[i - 1][j] * (1.0 - p[i - 1]);
        }
    }
    auto ans = 0.0;
    for (int i = (n + 1) / 2; i <= n; i++) ans += dp[n][i];
    cout << ans << endl;
}