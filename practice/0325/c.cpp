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
    int n, m, x;
    cin >> n >> m >> x;
    vc<int> c(n);
    vc<vc<int>> a(n, vc<int>(m, 0));
    rep(i, n) {
        cin >> c[i];
        rep(j, m) { cin >> a[i][j]; }
    }
    int ans = 1e9;
    for (int bit = 0; bit < (1 << n); bit++) {
        int tmp = 0;
        vc<int> now(m, 0);
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                tmp += c[i];
                rep(k, m) { now[k] += a[i][k]; }
            }
        }
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if (now[j] < x) ok = false;
        }
        if (ok) {
            ans = min(ans, tmp);
        }
    }
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
}