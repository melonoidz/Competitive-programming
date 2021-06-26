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
int dx[]{-1, 1, 0, 0};
int dy[]{0, 0, 1, -1};
int h, w, ans = -1;
vc<string> c;
vvc<bool> used(20, vc<bool>(20, false));
int rec(int sx, int sy, int px, int py) {
    if (sx == px && sy == py && used[px][py]) return 0;
    int res = -10000;
    used[px][py] = true;
    rep(i, 4) {
        int nx = px + dx[i];
        int ny = py + dy[i];
        if (0 > nx || 0 > ny || nx >= h || ny >= w) continue;
        if (c[nx][ny] == '#') continue;
        if (used[nx][ny] && (nx != sx || ny != sy)) continue;
        // OK
        chmax(res, rec(sx, sy, nx, ny) + 1);
    }
    used[px][py] = false;
    return res;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> h >> w;
    rep(i, h) {
        string a;
        cin >> a;
        c.push_back(a);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            chmax(ans, rec(i, j, i, j));
        }
    }
    if (ans <= 2) ans = -1;
    cout << ans << endl;
    return 0;
}