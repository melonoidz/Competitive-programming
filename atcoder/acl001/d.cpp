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

int max(int a, int b) { return std::max(a, b); }
int zero() { return 0; }
const int M = 300000;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    // dp[j] 1,2,...j までの列で末尾がxとなる個数
    // dp[j+1]=dp[j] (IF abs(dp[j+1]-dp[j])>K)
    // dp[j+1]=dp[j]+1 else
    // 1点更新・要素allprodの取得
    atcoder::segtree<int, max, zero> dp(M + 1);
    while (N--) {
        int a;
        cin >> a;
        int l = std::max(a - K, 0LL);
        int r = std::min(a + K, M);
        int len = dp.prod(l, r + 1);
        dp.set(a, len + 1);
    }
    cout << dp.all_prod() << endl;
}