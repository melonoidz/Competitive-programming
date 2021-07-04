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
int n, ans = 0;
map<int, int> memo;
void rec(int x, int ac, int bc, int cc) {
    if (x > n) return;
    if (memo[x] != 0) return;
    memo[x]++;
    if (ac > 0 && bc > 0 && cc > 0) ans++;
    int a = x * 10 + 3;
    int b = x * 10 + 5;
    int c = x * 10 + 7;
    rec(a, ac + 1, bc, cc);
    rec(b, ac, bc + 1, cc);
    rec(c, ac, bc, cc + 1);
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n;
    rec(3, 1, 0, 0);
    rec(5, 0, 1, 0);
    rec(7, 0, 0, 1);
    cout << ans << endl;
}