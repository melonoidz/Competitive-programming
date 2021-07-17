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
    int m;
    cin >> m;
    using mint = atcoder::modint1000000007;
    vc<mint> dp(1 << 17);
    // dp[i]：要素の合計がiである"良い数列"の個数
    vvc<int> f(m + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j += i) {
            f[j].push_back(i);
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (auto j : f[i]) {
            dp[i] += dp[i / j - 1];
        }
    }
    cout << dp[m].val() << endl;
}