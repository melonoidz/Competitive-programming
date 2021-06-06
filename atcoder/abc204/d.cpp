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
    int n;
    cin >> n;
    vc<int> t(n);
    rep(i, n) cin >> t[i];
    int tsum = accumulate(ALL(t), 0LL);
    vvc<bool> dp(n + 1, vc<bool>(100100, false));
    rep(i, n + 1) dp[i][0] = true;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= 100010; k++) {
            if (k - t[i] >= 0) dp[i + 1][k] = dp[i + 1][k] | dp[i][k - t[i]];
            dp[i + 1][k] = dp[i + 1][k] | dp[i][k];
        }
    }
    for (int t = (tsum + 1) / 2; t <= tsum; t++) {
        if (dp[n][t]) {
            cout << t << endl;
            return 0;
        }
    }
}