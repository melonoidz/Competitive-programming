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
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << 1 << endl;
        return 0;
    }
    vc<int> a(m);
    rep(i, m) cin >> a[i];
    a.push_back(n + 1);
    a.push_back(0);
    sort(ALL(a));
    vc<int> d;
    for (int i = 0; i < a.size() - 1; i++) {
        int now = a[i + 1] - a[i] - 1LL;
        if (now > 0) d.push_back(now);
    }
    if (d.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    int r = *min_element(ALL(d));
    int ans = 0;
    for (auto u : d) {
        if (u % r == 0)
            ans += u / r;
        else
            ans += 1 + u / r;
    }
    cout << ans << endl;
}