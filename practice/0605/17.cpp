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
    int n, k;
    cin >> n >> k;
    vc<int> x(n), y(n), xp(n), yp(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
        xp[i] = x[i];
        yp[i] = y[i];
    }
    int ans = LLONG_MAX;
    sort(ALL(x));
    sort(ALL(y));
    rep(i, n) {
        rep(j, n) {
            rep(s, n) {
                rep(t, n) {
                    int xl, xr, yl, yr, cnt = 0;
                    xl = min(x[i], x[j]);
                    xr = max(x[i], x[j]);
                    yl = min(y[s], y[t]);
                    yr = max(y[s], y[t]);
                    if ((xr - xl) == 0 || (yr - yl) == 0) continue;
                    rep(q, n) {
                        if (xl <= xp[q] && xp[q] <= xr && yl <= yp[q] &&
                            yp[q] <= yr)
                            cnt++;
                    }
                    if (k <= cnt) {
                        chmin(ans, (xr - xl) * (yr - yl));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}