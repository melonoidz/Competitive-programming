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
using mint = atcoder::modint1000000007;
int n, a, b;
vc<char> c(100100);
vvc<int> t(100100);
vvc<mint> dp(100100, vc<mint>(3, 0));
// 0：aのみ 1：bのみ 2：a,b両方
// dp[pos][i]：頂点posの部分木を考えたとき何通りあるか
void dfs(int pos, int pre) {
    mint val1 = 1, val2 = 1;
    for (auto u : t[pos]) {
        if (u == pre) continue;
        dfs(u, pos);
        if (c[pos] == 'a') {
            // a
            val1 *= (dp[u][0] + dp[u][2]);
            val2 *= (dp[u][0] + dp[u][1] + mint(2) * dp[u][2]);  // All
        }
        if (c[pos] == 'b') {
            // b
            val1 *= (dp[u][1] + dp[u][2]);
            val2 *= (dp[u][0] + dp[u][1] + mint(2) * dp[u][2]);
        }
    }
    if (c[pos] == 'a') {
        dp[pos][0] = val1;
        dp[pos][2] = val2 - val1;  // bしかない可能性を引く
        
    }
    if (c[pos] == 'b') {
        dp[pos][1] = val1;
        dp[pos][2] = val2 - val1;
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n;
    rep(i, n) cin >> c[i];
    rep(i, n - 1) {
        cin >> a >> b;
        a--, b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    //木DP
    dfs(0, -1);
    cout << dp[0][2].val() << endl;
    return 0;
}