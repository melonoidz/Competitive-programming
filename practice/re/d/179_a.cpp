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
    int n, k;
    const int MOD = 998244353;
    cin >> n >> k;
    vc<pi> D;
    rep(i, k) {
        int l, r;
        cin >> l >> r;
        D.emplace_back(l, r);
    }
    vc<int> dp(n, 0), sdp(n + 1, 0);
    dp[0] = 1, sdp[1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int left = max(0LL, i - D[j].second);
            int right = max(0LL, i - D[j].first + 1);
            dp[i] += sdp[right] - sdp[left];
            dp[i] %= MOD;
        }
        sdp[i + 1] = sdp[i] + dp[i];
        sdp[i + 1] %= MOD;
    }
    if (dp[n - 1] < 0) dp[n - 1] += MOD;
    cout << dp[n - 1] << endl;
    return 0;
}