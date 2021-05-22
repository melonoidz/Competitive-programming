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
using mint = atcoder::modint1000000007;
mint ans = 0;
int k;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> k;
    if (k % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }
    vc<mint> dp(100100, 0);
    // dp[各桁の数字の和]
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        int dig = min(i, 9LL);
        for (int j = 1; j <= dig; j++) {
            dp[i] += dp[i - j];
        }
    }
    cout << dp[k].val() << endl;
}