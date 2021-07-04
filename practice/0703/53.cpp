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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vc<int> a(n + 1);
    rep(i, n + 1) cin >> a[i];
    int k = 1e9;
    rep(i, n) { chmin(k, abs(a[i] - a[i + 1])); }
    vvc<int> ans(k, vc<int>(n + 1));
    for (int j = 0; j <= n; j++) {
        int r = a[j] % k;
        for (int i = 0; i < k; i++) {
            ans[i][j] = a[j] / k;
            if (i < r) ans[i][j]++;  //余剰を振り分け
        }
    }
    cout << k << endl;
    rep(i, k) {
        rep(j, n + 1) cout << ans[i][j] << " ";
        cout << endl;
    }
}