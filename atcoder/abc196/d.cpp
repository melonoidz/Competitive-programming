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
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    int ans = 0;
    vc<vc<vc<int>>> tmp;
    for (int iq = 0; iq < (1 << (h * w)); iq++) {
        vc<vc<int>> f(h, vc<int>(w, 0));
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (iq & (1 << ((y)*w + x))) {
                    f[y][x] = 1;
                }
            }
        }
        int ca = 0;
        int cb = 0;
        for (int ii = 0; ii < h; ii++) {
            for (int jj = 0; jj < w; jj++) {
                if (f[ii][jj] == 0) cb++;
            }
        }
        // cout<<h<<" "<<w<<endl;
        // cout<<"!!"<<endl;
        if (cb == b) {
            vc<vc<int>> tm(h, vc<int>(w, 0));
            vc<vc<vc<int>>> dp(h + 1, vc<vc<int>>(w + 1, vc<int>(1 << w, 0)));
            dp[0][0][0] = 1;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    for (int bb = 0; bb < (1 << h); bb++) {
                        if (((bb & (1 << w)) || f[i][j] == 1) &&
                            (tm[i][j] == 1)) {
                            int nx = bb & (~(1 << j));
                            if (j + 1 < w) {
                                dp[i][j + 1][nx] += dp[i][j][bb];

                            } else {
                                dp[i + 1][0][nx] += dp[i][j][bb];
                            }
                        } else {
                            // empty
                            if ((j + 1 < w && f[i][j + 1] == 1) &&
                                (tm[i][j + 1] == 0 && !(bb & (1 << (j + 1))))) {
                                int nx = (bb | (1 << (j + 1)));
                                dp[i][j + 1][nx] += dp[i][j][bb];
                                tm[i][j + 1] = 1;
                            }
                            if ((i + 1 < h && f[i + 1][j] == 1) &&
                                (tm[i + 1][j] == 0)) {
                                int nx = (bb | (1 << j));
                                if (j + 1 < w) {
                                    dp[i][j + 1][nx] += dp[i][j][bb];
                                } else {
                                    dp[i + 1][0][nx] += dp[i][j][bb];
                                }
                                tm[i + 1][j] = 1;
                            }
                        }
                    }
                }
            }
            // rep(gg, h) {
            //     rep(hh, w) {
            //             cout << gg << "==" << hh << endl;
            //         rep(bit, 1 << w) {
            //             cout << dp[gg][hh][bit] << " ";
            //         }
            //         cout << "^^" << endl;
            //     }
            //     cout << endl;
            // }
            for (int v = 0; v < h; v++) ans += dp[v][w - 1][(1 << (w - 1))];
        }
    }
    cout << ans << endl;
}