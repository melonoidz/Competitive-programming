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
int h, w;
string a[2020];
bool vis[2020][2020];
int memo[2020][2020];
const int INF = 1LL << 60;
int dp(int x, int y) {
    if (vis[y][x]) return memo[y][x];
    vis[y][x] = true;
    int turn = (x + y) % 2;
    if (x == w - 1 && y == h - 1) return memo[y][x] = 0;
    if (turn == 0) {
        // Takahashi
        memo[y][x] = -INF;
        if (y < h - 1)
            chmax(memo[y][x], dp(x, y + 1) + (a[y + 1][x] == '+' ? 1 : -1));
        if (x < w - 1)
            chmax(memo[y][x], dp(x + 1, y) + (a[y][x + 1] == '+' ? 1 : -1));
        return memo[y][x];
    } else {
        memo[y][x] = INF;
        if (y < h - 1)
            chmin(memo[y][x], dp(x, y + 1) - (a[y + 1][x] == '+' ? 1 : -1));
        if (x < w - 1)
            chmin(memo[y][x], dp(x + 1, y) - (a[y][x + 1] == '+' ? 1 : -1));
        return memo[y][x];
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> h >> w;
    rep(i, h) cin >> a[i];
    int opt = dp(0, 0);
    if (0 < opt)
        cout << "Takahashi" << endl;
    else if (opt == 0)
        cout << "Draw" << endl;
    else
        cout << "Aoki" << endl;
}