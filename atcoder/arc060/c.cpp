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
    int n, a;
    cin >> n >> a;
    vc<int> x(n);
    rep(i, n) {
        cin >> x[i];
        x[i] -= a;
    }
    // dp[i][j] iまでみてj個使用でsum=0の個数
    vc<vc<int>> dp(n + 1, vc<int>(5100, 0));
    const int UP = 2500;
    dp[0][UP] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + x[i] <= 5050; j++) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j + x[i]] += dp[i][j];
        }
    }
    cout << dp[n][UP] - 1 << endl;
}