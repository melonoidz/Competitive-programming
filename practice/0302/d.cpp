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
    vc<int> h(n), w(m);
    rep(i, n) cin >> h[i];
    rep(i, m) cin >> w[i];

    if (n == 1 || m == 1) {
        if (n == 1) {
            int ans = 1e18;
            for (auto u : w) {
                ans = min(ans, abs(u - h[0]));
            }
            cout << ans << endl;
            return 0;
        } else {
            h.push_back(w[0]);
            sort(ALL(h));
            int ans = 0;
            for (int i = 0; i < h.size() - 1; i += 2) {
                ans += abs(h[i + 1] - h[i]);
            }
            cout << ans << endl;
            return 0;
        }
    }
    sort(ALL(h));
    vc<int> odd, even;
    for (int i = 0; i < n - 1; i = i + 2) {
        odd.push_back(h[i + 1] - h[i]);
    }
    for (int i = 1; i < n; i = i + 2) {
        even.push_back(h[i + 1] - h[i]);
    }
    vc<int> sodd(odd.size() + 1, 0), seven(even.size() + 1, 0);
    rep(i, odd.size()) sodd[i + 1] = sodd[i] + odd[i];
    rep(i, even.size()) seven[i + 1] = seven[i] + even[i];
    int ans = 1e18;
    for (int i = 0; i < m; i++) {
        auto d = upper_bound(ALL(h), w[i]) - h.begin();
        int now = 0;
        if (d % 2 == 0) {
            now = sodd[d / 2] + abs(w[i] - h[d]) +
                  (seven[seven.size() - 1] - seven[d / 2]);
        } else {
            now = sodd[d / 2] + abs(w[i] - h[d - 1]) +
                  (seven[seven.size() - 1] - seven[d / 2]);
        }
        ans = min(ans, now);
    }
    cout << ans << endl;
}