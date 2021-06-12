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
    int n;
    cin >> n;
    const int inf = 1LL << 30;
    int cnt = 0;
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    vc<int> ldp(n + 1), rdp(n + 1), dp(n + 1, inf);
    for (int i = 0; i < n; i++) {
        auto idx = lower_bound(dp.begin(), dp.begin() + cnt, a[i]) - dp.begin();
        dp[idx] = a[i];
        ldp[i] = idx + 1;
        if (idx == cnt) cnt++;  //末尾なら1idx足す
    }
    cnt = 0;
    reverse(ALL(a));
    dp.resize(n + 1, inf);
    for (int i = 0; i < n; i++) {
        auto idx = lower_bound(dp.begin(), dp.begin() + cnt, a[i]) - dp.begin();
        dp[idx] = a[i];
        rdp[i] = idx + 1;
        if (idx == cnt) cnt++;  //末尾なら1idx足す
    }
    int ans = 0;
    rep(i, n) { chmax(ans, ldp[i] + rdp[n - 1 - i] - 1); }
    cout << ans << endl;
}