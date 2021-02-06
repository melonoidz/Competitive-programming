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

vc<vc<vc<double>>> dp(110, vc<vc<double>>(110, vc<double>(110, -1)));
double rec(int x, int y, int z) {
    if (x == 100 || y == 100 || z == 100) {
        return 0.0;
    }
    if (dp[x][y][z] >= 0) return dp[x][y][z];
    int cnt = x + y + z;
    double tmp = (rec(x + 1, y, z) + 1) * x + (1 + rec(x, y + 1, z)) * y +
                 (1 + rec(x, y, z + 1)) * z;
    tmp /= (double)cnt;
    return dp[x][y][z] = tmp;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int a, b, c;
    cin >> a >> b >> c;
    cout << rec(a, b, c) << endl;
    return 0;
}