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
    vc<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    int m;
    cin >> m;
    vc<int> xx(m + 1), xy(m + 1), xp(m + 1), yx(m + 1), yy(m + 1), yp(m + 1);
    // x={1,0}, y={0,1}, p={0,0}
    xx[0] = 1, xy[0] = 0, xp[0] = 0, yx[0] = 0, yy[0] = 1, yp[0] = 0;
    rep(i, m) {
        int t;
        cin >> t;
        if (t == 1) {
            xx[i + 1] = yx[i];
            xy[i + 1] = yy[i];
            xp[i + 1] = yp[i];
            yx[i + 1] = -xx[i];
            yy[i + 1] = -xy[i];
            yp[i + 1] = -xp[i];
        } else if (t == 2) {
            xx[i + 1] = -yx[i];
            xy[i + 1] = -yy[i];
            xp[i + 1] = -yp[i];
            yx[i + 1] = xx[i];
            yy[i + 1] = xy[i];
            yp[i + 1] = xp[i];
        } else if (t == 3) {
            int p;
            cin >> p;
            xx[i + 1] = -xx[i];
            xy[i + 1] = -xy[i];
            xp[i + 1] = 2 * p - xp[i];
            yx[i + 1] = yx[i];
            yy[i + 1] = yy[i];
            yp[i + 1] = yp[i];
        } else {
            int p;
            cin >> p;
            xx[i + 1] = xx[i];
            xy[i + 1] = xy[i];
            xp[i + 1] = xp[i];
            yx[i + 1] = -yx[i];
            yy[i + 1] = -yy[i];
            yp[i + 1] = 2 * p - yp[i];
        }
    }
    int q;
    cin >> q;
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        b--;
        int nx, ny;
        nx = xx[a] * x[b] + xy[a] * y[b] + xp[a];
        ny = yx[a] * x[b] + yy[a] * y[b] + yp[a];
        cout << nx << " " << ny << endl;
    }
    return 0;
}