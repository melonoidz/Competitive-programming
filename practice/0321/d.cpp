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
int h, w, a, b;
vc<vc<bool>> check(16, vc<bool>(16, false));
int dfs(int x, int y, int a) {
    if (y == h) return (a == 0);
    if (x == w) return dfs(0, y + 1, a);
    if (check[y][x]) return dfs(x + 1, y, a);
    int res = 0;
    if (y + 1 < h && !check[y + 1][x] && a > 0) {
        check[y][x] = true;
        check[y + 1][x] = true;
        res += dfs(x + 1, y, a - 1);
        check[y][x] = false;
        check[y + 1][x] = false;
    }
    if (x + 1 < w && !check[y][x + 1] && a > 0) {
        check[y][x] = true;
        check[y][x + 1] = true;
        // x+1であることに注意
        res += dfs(x + 1, y, a - 1);
        check[y][x] = false;
        check[y][x + 1] = false;
    }
    res += dfs(x + 1, y, a);
    return res;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> h >> w >> a >> b;
    cout << dfs(0, 0, a) << endl;
    return 0;
}