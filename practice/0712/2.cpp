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
int ans = 1e9;
map<int, int> memo;
int rec(int n) {
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];
    int res = n;
    for (int six = 6; six <= n; six *= 6) {
        chmin(res, rec(n - six) + 1);
    }
    for (int nine = 9; nine <= n; nine *= 9) {
        chmin(res, rec(n - nine) + 1);
    }
    return memo[n] = res;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    const int MAX = 110000;
    rep(i, MAX) memo[i] = -1;
    cout << rec(n) << endl;
}