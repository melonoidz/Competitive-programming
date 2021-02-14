#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
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
    int h, w;
    cin >> h >> w;
    vc<vc<int>> C(h, vc<int>(w));
    vc<vc<int>> wi(h + 1, vc<int>(w + 1, 0));
    vc<vc<int>> bl(h + 1, vc<int>(w + 1, 0));
    rep(i, h) { rep(j, w) cin >> C[i][j]; }

    rep(i, h) {
        rep(j, w) {
            if ((i + j) % 2 == 1)
                wi[i + 1][j + 1] =
                    wi[i][j + 1] + wi[i + 1][j] - wi[i][j] + C[i][j];
            else
                wi[i + 1][j + 1] = wi[i][j + 1] + wi[i + 1][j] - wi[i][j];
        }
    }
    rep(i, h) {
        rep(j, w) {
            if ((i + j) % 2 == 0)
                bl[i + 1][j + 1] =
                    bl[i][j + 1] + bl[i + 1][j] - bl[i][j] + C[i][j];
            else
                bl[i + 1][j + 1] = bl[i][j + 1] + bl[i + 1][j] - bl[i][j];
        }
    }
    int ans = 0;
    for (int lh = 0; lh < h; lh++) {
        for (int dh = lh + 1; dh < h + 1; dh++) {
            for (int lw = 0; lw < w; lw++) {
                for (int rw = lw + 1; rw < w + 1; rw++) {
                    int tmpwhite =
                        wi[dh][rw] - wi[lh][rw] - wi[dh][lw] + wi[lh][lw];
                    int tmpblack =
                        bl[dh][rw] - bl[lh][rw] - bl[dh][lw] + bl[lh][lw];
                    // cout << lh << "=lh " << dh << "=dh " << lw << "=lw " <<
                    // rw
                    //      << "=rw " << tmpwhite << "=White " << tmpblack
                    //      << "=Black " << endl;
                    if (tmpwhite == tmpblack) {
                        ans = max(ans, (dh - lh) * (rw - lw));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}