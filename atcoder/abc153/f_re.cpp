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
    vc<pi> mons(n);
    vc<int> x(n), h(n);
    rep(i, n) { cin >> mons[i].first >> mons[i].second; }
    sort(ALL(mons));
    rep(i, n) {
        x[i] = mons[i].first;
        h[i] = mons[i].second;
    }
    int res = 0;
    vc<int> sa(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (sa[i] < h[i]) {
            int range = x[i] + 2 * d;
            int right = upper_bound(ALL(x), range) - x.begin();
            int need = (h[i] - sa[i] + a - 1) / a;
            sa[i] += need * a;
            sa[right] -= need * a;
            res += need;
        }
        sa[i + 1] += sa[i];
    }
    cout << res << endl;
}