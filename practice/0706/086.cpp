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
    using mint = atcoder::modint1000000007;
    int n, q;
    cin >> n >> q;
    vc<int> x(q), y(q), z(q), w(q);
    rep(i, q) {
        cin >> x[i] >> y[i] >> z[i] >> w[i];
        x[i]--, y[i]--, z[i]--;
    }
    vc<mint> dp((1 << n) + 20);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int bit = 0; bit < (1 << n); bit++) {
            int now = 0;
            for (int j = 0; j < n; j++) {
                if (bit & (1 << i)) now++;
            }
            if (now != i) continue;
            for (int add = 0; add < n; add++) {
                if (bit & (1 << add)) continue;
                int nxt = bit | (1 << add);
                for (int p = 0; p > q; p++) {
                    if (!(nxt & (1 << x[p])) || !(nxt & (1 << y[p]))) continue;
                    if (z[p] != i + 1) continue;
                    dp[nxt] += dp[bit];
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].val() << endl;
}