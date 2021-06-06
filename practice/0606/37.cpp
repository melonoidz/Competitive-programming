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
int op(int a, int b) { return max(a, b); }
int e() { return 0; }
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int w, n;
    cin >> w >> n;
    // dp[i番目まで見て][spiceの合計]=(価値のmax)
    // dp[i][j]=dp[i-1][j] (iを選択しない場合)
    // dp[i][j]=v(i)+max(dp[i-1][j-R[i]]~~~~dp[i-1][j-L[i]])
    // SEGTree
    // 1：Ax=yにする　2：l,rからmax(Al~~Ar)を求める.
    atcoder::segtree<int, op, e> dp(1010100);
    rep(i, n) {
        int l, r, v;
        cin >> l >> r >> v;
        for(int j=0; j<=w; j++){
            auto mx=dp.prod(max(0LL, j-r), max(0LL, j-l+1));
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+mx);
        }
    }
}