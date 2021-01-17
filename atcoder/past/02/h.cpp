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
    int n, m;
    cin >> n >> m;
    vc<vc<int>> f(n, vc<int>(m, 12));
    int sx, sy, gx, gy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            if (a == 'S') {
                f[i][j] = 0;
                sy = i;
                sx = j;
            } else if (a == 'G') {
                f[i][j] = 10;
                gy = i;
                gx = j;
            } else {
                f[i][j] = a - '0';
            }
        }
    }
    vc<vc<int>> dp(n, vc<int>(m, 1e9));
    dp[sy][sx] = 0;
    for (int k = 0; k <= 10; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (f[i][j] == k) {
                    for (int p = 0; p < n; p++) {
                        for (int q = 0; q < m; q++) {
                            if (f[p][q] == k - 1) {
                                int tmp = dp[p][q] + abs(p - i) + abs(q - j);
                                dp[i][j] = min(dp[i][j], tmp);
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = dp[gy][gx];
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
}