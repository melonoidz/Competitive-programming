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
    using mint = atcoder::modint1000000007;
    // 2N円以内のコスト M個全部踏む時
    // 2N-M<=x<=2N
    int n, m;
    cin >> n >> m;
    vvc<int> f(n + 1, vc<int>(n + 1, 0));
    rep(i, m) {
        int t, x, y;
        cin >> t >> x >> y;
        f[x][y] = t;
    }
    mint ans = 0;
    vvc<map<int, mint>> dp(n + 1, vc<map<int, mint>>(n + 1));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto u : dp[i][j]) {
                if (f[i][j] == 1) {
                    // Type1
                    dp[i + 1][j][u.first] += dp[i][j][u.first];
                    dp[i][j + 1][u.first + 1] += dp[i][j][u.first];
                } else if (f[i][j] == 2) {
                    // Type2
                    dp[i + 1][j][u.first + 1] += dp[i][j][u.first];
                    dp[i][j + 1][u.first] += dp[i][j][u.first];
                } else {
                    dp[i + 1][j][u.first + 1] += dp[i][j][u.first];
                    dp[i][j + 1][u.first + 1] += dp[i][j][u.first];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto u : dp[i][j]) {
                cout << i << " == " << j << endl;
                cout << u.first << " " << u.second.val() << endl;
            }
        }
    }
    for (auto u : dp[n][n]) {
        cout << u.first << " " << u.second.val() << endl;
        ans += u.first * u.second;
    }
    cout << ans.val() << endl;
}