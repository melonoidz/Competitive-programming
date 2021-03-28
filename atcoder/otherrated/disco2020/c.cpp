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
int H, W, K;
vc<string> s;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> H >> W >> K;
    vc<vc<int>> ans(H, vc<int>(W, 0));
    int cnt = 1;
    rep(i, H) {
        string g;
        cin >> g;
        s.push_back(g);
        for (int j = 0; j < W; j++) {
            if (g[j] == '#') {
                ans[i][j] = cnt;
                cnt++;
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 1; j < W; j++) {
            if (ans[i][j] == 0) {
                ans[i][j] = ans[i][j - 1];
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = W - 1; j > 0; j--) {
            if (ans[i][j - 1] == 0) {
                ans[i][j - 1] = ans[i][j];
            }
        }
    }
    for (int i = 0; i < W; i++) {
        for (int j = 1; j < H; j++) {
            if (ans[j][i] == 0) {
                ans[j][i] = ans[j - 1][i];
            }
        }
    }
    for (int i = 0; i < W; i++) {
        for (int j = H - 1; j > 0; j--) {
            if (ans[j - 1][i] == 0) {
                ans[j - 1][i] = ans[j][i];
            }
        }
    }
    rep(i, H) {
        rep(j, W) cout << ans[i][j] << " ";
        cout << endl;
    }
}