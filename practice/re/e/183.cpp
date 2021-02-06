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
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    const int mod = 1000000007;
    int h, w;
    cin >> h >> w;
    vc<string> S;
    rep(i, h) {
        string k;
        cin >> k;
        S.push_back(k);
    }
    vc<vc<int>> dp(2020, vc<int>(2020, 0));
    auto x = dp, y = dp, z = dp;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (S[i - 1][j - 1] == '#') {
                x[i][j] = 0;
                y[i][j] = 0;
                z[i][j] = 0;
                continue;
            }
            dp[i][j] += x[i - 1][j] + y[i][j - 1] + z[i - 1][j - 1];
            dp[i][j] %= mod;
            x[i][j] += x[i - 1][j] + dp[i][j];
            y[i][j] += y[i][j - 1] + dp[i][j];
            z[i][j] += z[i - 1][j - 1] + dp[i][j];
        }
    }
    cout << dp[h][w] << endl;
    return 0;
}