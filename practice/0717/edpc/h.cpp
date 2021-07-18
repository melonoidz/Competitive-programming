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
    cin >> h >> w;
    using mint = atcoder::modint1000000007;
    vc<string> a;
    rep(i, h) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    vvc<mint> dp(h + 1, vc<mint>(w + 1));
    dp[0][0] = 1;
    for (int i = 0; i < h; i++) {
        rep(j, w) {
            if (a[i][j] != '#') {
                dp[i + 1][j] += dp[i][j];
                dp[i][j + 1] += dp[i][j];
            }
        }
    }
    cout << dp[h - 1][w - 1].val() << endl;
}