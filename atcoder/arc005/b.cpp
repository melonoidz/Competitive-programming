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
    int x, y;
    cin >> x >> y;
    string w;
    cin >> w;
    x--, y--;
    vc<string> b(10);
    rep(i, 9) cin >> b[i];
    int dx, dy;
    if (w == "R") {
        dx = 1;
        dy = 0;
    } else if (w == "L") {
        dx = -1;
        dy = 0;
    } else if (w == "U") {
        dx = 0;
        dy = -1;
    } else if (w == "D") {
        dx = 0;
        dy = 1;
    } else if (w == "RU") {
        dx = 1;
        dy = -1;
    } else if (w == "RD") {
        dx = 1;
        dy = 1;
    } else if (w == "LU") {
        dx = -1;
        dy = -1;
    } else if (w == "LD") {
        dx = -1;
        dy = 1;
    }
    cout << b[y][x];
    rep(i, 3) {
        int tx = x, ty = y;
        tx += dx, ty += dy;
        if (!(0 <= tx && tx < 9)) dx *= -1;
        if (!(0 <= ty && ty < 9)) dy *= -1;
        x += dx, y += dy;
        cout << b[y][x];
    }
    cout << endl;
    return 0;
}