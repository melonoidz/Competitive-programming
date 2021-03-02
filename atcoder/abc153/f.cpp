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
    int n, d, a;
    cin >> n >> d >> a;
    atcoder::fenwick_tree<int> BIT(n + 10);
    vc<int> x(n), h(n);
    rep(i, n) cin >> x[i] >> h[i];
    int res = 0;
    vc<int> monsters(n);
    rep(i, n) monsters[i] = i;
    sort(ALL(monsters), [&](int i, int j) { return x[i] < x[j]; });
    vc<int> nh(n), nx(n);
    rep(i, n) {
        nx[i] = x[monsters[i]];
        nh[i] = h[monsters[i]];
    }
    x = nx, h = nh;
    rep(i, n) { BIT.add(i, h[i]); }
    rep(i, n) {
        auto cur = BIT.sum(i, i + 1);
        if (cur <= 0) continue;
        int need = (cur + a - 1) / a;
        int right = x[i] + d * 2;
        int id = upper_bound(ALL(x), right) - x.begin();
        BIT.add(i, -need * a);
        res += need;
    }
    cout << res << endl;
}