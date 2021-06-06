#include <bits/stdc++.h>
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
    int n, s, t, ans = 0;
    cin >> n >> s >> t;
    vc<int> a(n), b(n);
    rep(i, n) { cin >> a[i] >> b[i]; }
    vc<pi> before;
    vc<int> after;
    int inf = 1e10;
    int mid = n / 2;
    for (int bit = 0; bit < (1 << mid); bit++) {
        int now = 0, mx = -inf;
        for (int i = 0; i < mid; i++) {
            if (bit & (1 << i)) {
                now += b[i];
            } else {
                now -= a[i];
            }
            chmax(mx, now);
        }
        if (s + mx > t) continue;
        before.emplace_back(now, mx);
    }
    for (int bit = 0; bit < (1 << (n - mid)); bit++) {
        int now = 0, mx = -inf;
        for (int i = 0; i < n - mid; i++) {
            if (bit & (1 << i)) {
                now += b[i + mid];
            } else {
                now -= a[i + mid];
            }
            chmax(mx, now);
        }
        if (mx <= t) after.emplace_back(mx);
    }
    before.emplace_back(-inf, -inf);
    after.emplace_back(inf);
    sort(ALL(before));
    sort(ALL(after));
    for (int i = 0; i < before.size(); i++) {
        int tmp = s + before[i].second;
        if (tmp > t || tmp <= 0) continue;
        int res = t - (s + before[i].first);
        auto d = lower_bound(ALL(after), res + 1) - after.begin();
        ans += d;
    }
    cout << ans << endl;
}