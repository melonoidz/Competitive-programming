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
//Must upsolve
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    using mint = atcoder::modint1000000007;
    mint ans = 0;
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    vc<int> s(n + 1);
    rep(i, n) s[i + 1] = s[i] + a[i];
    vvc<mint> dp(3005, vc<mint>(3005));
    vvc<mint> ds(3005, vc<mint>(3005));
    ds[1][0] = 1;
    // dp[i][j]:i番目まで見て,次からjグループが始まる場合の数
    dp[0][1] = 1;
    for (int x = 1; x <= n; x++) {
        for (int i = x; i >= 1; i--) {
            dp[x][i + 1] = ds[i][s[x] % i];
            ds[i + 1][s[x] % (i + 1)] += dp[x][i + 1];
        }
    }
    for (int j = 1; j <= n + 1; j++) {
        ans += dp[n][j];
    }
    cout << ans.val() << endl;
}