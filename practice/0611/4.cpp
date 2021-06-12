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
    int n, q;
    cin >> n >> q;
    vc<int> a(n), b(n + 10);
    rep(i, n) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        b[i + 1] = a[i + 1] - a[i];
        ans += abs(b[i + 1]);
    }
    rep(i, q) {
        int l, r, v;
        cin >> l >> r >> v;
        int before = abs(b[l - 1]) + abs(b[r]);
        if (l > 1) b[l - 1] += v;
        if (r < n) b[r] -= v;
        int after = abs(b[l - 1]) + abs(b[r]);
        ans += (after - before);
        cout << ans << endl;
    }
}