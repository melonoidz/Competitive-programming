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
int n, m, ans = 0;
vvc<pi> g(410);
map<pi, int> add;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    vvc<int> dp(410, vc<int>(410, 1e9));
    rep(i, n) dp[i][i] = 0;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dp[a][b] = c;
    }
    rep(k, n) {
        vvc<int> nxt(410, vc<int>(410, 0));
        rep(i, n) {
            rep(j, n) {
                // kを通るか通らないかしかない
                nxt[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                if (nxt[i][j] != 1e9) ans += nxt[i][j];
            }
        }
        dp = nxt;
    }

    cout << ans << endl;
}