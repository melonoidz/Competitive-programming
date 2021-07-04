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
    vc<int> d(5010), c(5010), s(5010);
    vc<tuple<int, int, int>> t;
    rep(i, n) {
        int d, c, s;
        cin >> d >> c >> s;
        t.emplace_back(d, c, s);
    }
    sort(ALL(t));
    rep(i, n) {
        d[i] = get<0>(t[i]);
        c[i] = get<1>(t[i]);
        s[i] = get<2>(t[i]);
    }
    vvc<int> dp(5010, vc<int>(5010));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 5000; j++) {
            //仕事i+1をやらない
            chmax(dp[i + 1][j], dp[i][j]);
            //やる
            //ソートしてナップサック
            if (j + c[i] <= d[i]) {
                chmax(dp[i + 1][j + c[i]], dp[i][j] + s[i]);
            }
        }
    }
    int ans = 0;
    rep(i, 5001) { chmax(ans, dp[n][i]); }
    cout << ans << endl;
    return 0;
}