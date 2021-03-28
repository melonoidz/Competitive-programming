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
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = INT_MAX / 2;
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    for (int bit = 0; bit < (1 << (n - 1)); bit++) {
        // 1で分割
        int tot = 0;
        int res = a[0];
        for (int i = 1; i < n; i++) {
            if (bit & (1 << (i - 1))) {
                tot ^= res;
                res = a[i];
            } else {
                res |= a[i];
            }
        }
        tot ^= res;
        ans = min(ans, tot);
    }
    cout << ans << endl;
}