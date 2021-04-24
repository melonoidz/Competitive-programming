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
    vc<double> x(n), y(n);
    rep(i, n) { cin >> x[i] >> y[i]; }
    double ans = 0.00;
    for (int i = 0; i < n; i++) {
        vc<double> vec;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            double nx = x[j] - x[i];
            double ny = y[j] - y[i];
            double rad = acos(nx / sqrt(nx * nx + ny * ny)) * 180.0 / M_PI;
            if (ny < 0.0) rad = 360.0 - rad;
            vec.push_back(rad);
        }
        sort(ALL(vec));
        for (int j = 0; j < vec.size(); j++) {
            double target = vec[j] + 180.0;
            if (target >= 360.0) target -= 360.0;
            auto d = lower_bound(ALL(vec), target) - vec.begin();
            if (d > 0) {
                d--;
            }
            double res = abs(vec[j] - vec[d]);
            if (res >= 180.0) res = 360.0 - res;
            chmax(ans, res);
            if (d > 0) d--;
            double res2 = abs(vec[j] - vec[d]);
            if (res2 >= 180.0) res2 = 360.0 - res2;
            chmax(ans, res2);
        }
    }
    cout << ans << endl;
}