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
    // https://horoyoisawa.hateblo.jp/entry/2020/03/19/114954
    int n;
    cin >> n;
    vc<vc<int>> graph(n);
    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            if (n % 2 == 0 && i + j == n - 1) continue;
            if (n % 2 == 1 && i + j == n - 2) continue;
            graph[i].push_back(j);
        }
    }
    int ans = 0;
    if (n % 2 == 0)
        ans = n * (n - 2) / 2;
    else
        ans = (n - 1) * (n - 3) / 2 + n - 1;
    cout << ans << endl;
    rep(i, n) {
        for (const auto& u : graph[i]) {
            if (i > u) continue;
            cout << i + 1 << " " << u + 1 << endl;
        }
    }
}