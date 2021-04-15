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
int N, X;
const int INF = 1LL << 60;
vc<int> A;
int calc(int k) {
    vc<vc<vc<int>>> dp(N + 1, vc<vc<int>>(k + 2, vc<int>(k + 1, -INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= k; j++) {
            for (int mod = 0; mod < k; mod++) {
                if (dp[i][j][mod] == -INF) continue;
                chmax(dp[i + 1][j][mod], dp[i][j][mod]);
                chmax(dp[i + 1][j + 1][(mod + A[i]) % k], dp[i][j][mod] + A[i]);
            }
        }
    }
    int res = dp[N][k][X % k];
    if (res == -INF) return INF;
    return (X - res) / k;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> N >> X;
    A.resize(N);
    rep(i, N) cin >> A[i];
    int ans = INF;
    for (int k = 1; k <= N; k++) {
        chmin(ans, calc(k));
    }
    cout << ans << endl;
}