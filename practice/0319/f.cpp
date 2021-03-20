#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
int N;
vc<int> a(3), b(3);
const int MAX = 30000000;
int dp[MAX];

int calc(vc<int>& sei, vc<int>& obj, int M) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 3; i++) {
        for (int v = 0; v + sei[i] <= M; ++v) {
            chmax(dp[v + sei[i]], dp[v] + obj[i]);
        }
    }
    int res = M;
    for (int v = 0; v <= M; ++v) chmax(res, dp[v] + M - v);
    return res;
}

int solve() {
    N = calc(a, b, N);
    N = calc(b, a, N);
    return N;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> N;
    rep(i, 3) cin >> a[i];
    rep(i, 3) cin >> b[i];
    cout << solve() <<  "\n";
    return 0;
}