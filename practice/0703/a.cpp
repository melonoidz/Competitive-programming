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
    // 19.cpp
    int n;
    cin >> n;
    vc<int> a(1 << 18);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }
    vvc<int> dp(410, vc<int>(410));
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = i; j <= 2 * n; j++) {
            dp[i][j] = (1 << 29);
        }
        if (i < n * 2) dp[i][i + 1] = abs(a[i] - a[i + 1]);
    }

    for (int i = 3; i <= 2 * n; i += 2) {
        for (int j = 1; j <= 2 * n - i; j++) {
            int cl = j, cr = j + i;
            for (int k = cl; k <= cr - 1; k++) {
                chmin(dp[cl][cr], dp[cl][k] + dp[k + 1][cr]);
            }
            chmin(dp[cl][cr], dp[cl + 1][cr - 1] + abs(a[cl] - a[cr]));
        }
    }
    cout << dp[1][2 * n] << endl;  //区間[1,2n]
    return 0;
}