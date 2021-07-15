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
using mint = atcoder::modint998244353;
int n, m;
vc<bool> used(100100);
vc<mint> memo(100100);
vc<mint> fact(1LL << 20), factinv(1LL << 20);
mint ncr(int n, int r) { return (fact[n] * factinv[r]) * factinv[n - r]; }

mint dfs(vc<bool>& used, vc<mint>& memo, int n, int m) {
    if (used[m]) return memo[m];
    used[m] = true;
    if (m % 2 != 0) {
        return (memo[m] = 0);
    }
    if (m == 0) return (memo[m] = 1);
    for (int i = 0; i <= min(n, m); i += 2) {
        // iは偶数個しかない
        mint ret = dfs(used, memo, n, (m - i) / 2LL);
        ret *= ncr(n, i);
        memo[m] += ret;
    }
    return memo[m];
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    if (m % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    fact[0] = 1;
    for (int i = 1; i <= 100100; i++) fact[i] = fact[i - 1] * i;
    for (int i = 0; i <= 100100; i++) factinv[i] = fact[i].inv();
    dfs(used, memo, n, m);
    cout << memo[m].val() << endl;
}