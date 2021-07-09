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
    using mint = atcoder::modint998244353;
    int h, w, k;
    cin >> h >> w >> k;
    vvc<char> f(5010, vc<char>(5010));
    rep(i, k) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        char z;
        cin >> z;
        f[x][y] = z;
    }
    vvc<mint> dp(5010, vc<mint>(5010));
    dp[0][0] = mint(3).pow(h * w - k);
    mint cur = mint(2) * mint(3).inv();
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= w; j++) {
            if (f[i][j] == 'R') {
                dp[i][j + 1] += dp[i][j];
            } else if (f[i][j] == 'D') {
                dp[i + 1][j] += dp[i][j];
            } else if (f[i][j] == 'X') {
                // X or blank
                dp[i + 1][j] += dp[i][j];
                dp[i][j + 1] += dp[i][j];
            } else {
                // X or blank
                dp[i + 1][j] += dp[i][j] * cur;
                dp[i][j + 1] += dp[i][j] * cur;
            }
        }
    }
    cout << dp[h - 1][w - 1].val() << endl;
}