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
    int n, m;
    cin >> n >> m;
    vc<vc<int>> a(n, vc<int>(m, 0)), b(n, vc<int>(m, 0));
    rep(i, n) {
        string g;
        cin >> g;
        for (int j = 0; j < m; j++) {
            a[i][j] = g[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) {
                if (i + 1 < n) b[i + 1][j] = a[i][j];
                if (i + 1 < n && j - 1 >= 0) a[i + 1][j - 1] -= a[i][j];
                if (i + 1 < n && j + 1 < m) a[i + 1][j + 1] -= a[i][j];
                if (i + 2 < n) a[i + 2][j] -= a[i][j];
                a[i][j] = 0;
            }
        }
    }
    rep(i, n) {
        rep(j, m) cout << max(0LL, b[i][j]);
        cout << endl;
    }
}