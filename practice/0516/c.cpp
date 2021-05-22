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
    int h, w;
    const int INF = 1LL << 30;
    cin >> h >> w;
    vc<vc<int>> score(2010, vc<int>(2010));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char c;
            cin >> c;
            if (c == '+') {
                score[i][j] = 1;
            } else {
                score[i][j] = -1;
            }
        }
    }
    vc<vc<int>> dp(2010, vc<int>(2010));
    // takahashiはdp max , Aokiはdp min
    for (int i = h; i > 0; i--) {
        for (int j = w; j > 0; j--) {
            if (i == h && j == w) {
                dp[i][j] = 0;
            } else if ((i + j) % 2 == 0) {
                // takahashi
                dp[i][j] = -INF;
                if (i + 1 <= h) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j] + score[i + 1][j]);
                }
                if (j + 1 <= w) {
                    dp[i][j] = max(dp[i][j], dp[i][j + 1] + score[i][j + 1]);
                }
            } else {
                // Aoki
                dp[i][j] = INF;
                if (i + 1 <= h) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] - score[i + 1][j]);
                }
                if (j + 1 <= w) {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] - score[i][j + 1]);
                }
            }
        }
    }
    if (dp[1][1] > 0) {
        cout << "Takahashi" << endl;
    } else if (dp[1][1] < 0) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }
}