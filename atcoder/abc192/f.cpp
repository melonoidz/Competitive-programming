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
int n, x;
int calc(int k, vc<int>& a, int x) {
    vc<vc<int>> dp(n + 1, vc<int>(k + 1, -10e9));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][(j - a[i] + k) % k] + a[i]);
        }
    }
    int res = 10e10 + 10LL;
    for (int i = 1; i <= n; i++) {
        res = min(res, (x - dp[i][x % k]) / k);
    }
    cout << k << " = k" << endl;
    for (int i = 1; i <= n; i++) {
        rep(j, k) { cout << dp[i][j] << " "; }
        cout << endl;
    }
    return res;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> x;
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    // k個選んだ時にres%k == x%k となるtime=min{(x-res)%k}を求める
    // sum(A)<=XなのでOK
    int ans = 10e10;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, calc(i, a, x));
    }
    cout << ans << endl;
}