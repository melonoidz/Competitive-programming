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
vc<mint> fact(1LL << 20), factinv(1LL << 20);
mint ncr(int n, int r) { return (fact[n] * factinv[r]) * factinv[n - r]; }

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    vc<int> t(m), x(m), y(m);
    rep(i, m) cin >> t[i] >> x[i] >> y[i];
    fact[0] = 1;
    for (int i = 1; i <= 400400; i++) fact[i] = fact[i - 1] * i;
    for (int i = 0; i <= 400400; i++) factinv[i] = fact[i].inv();
    mint ans = ncr(n + n, n) * mint(2 * n);

    for (int i = 0; i < m; i++) {
        if (t[i] == 1) {
            // Type1
            mint p1 = ncr(x[i] + y[i], y[i]);
            mint p2 = ncr((n - (x[i] + 1) + n - y[i]), n - y[i]);
            ans -= p1 * p2;
        } else {
            // Type2
            mint p1 = ncr(x[i] + y[i], y[i]);
            mint p2 = ncr(n - x[i] + n - (y[i] + 1), n - (y[i] + 1));
            ans -= p1 * p2;
        }
    }
    cout << ans.val() << endl;
}