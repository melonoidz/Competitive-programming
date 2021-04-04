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
int x, y;
map<int, int> memo;
int calc(int y) {
    if (x >= y) return abs(x - y);
    if (memo.count(y)) return memo[y];
    int res = abs(x - y);
    if (y % 2 == 0) {
        res = min(res, 1 + calc(y / 2));
    } else {
        res = min(res, calc((y - 1) / 2) + 1 + 1);
        res = min(res, calc((y + 1) / 2) + 1 + 1);
    }
    return memo[y] = res;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> x >> y;
    cout << calc(y) << endl;
    return 0;
}