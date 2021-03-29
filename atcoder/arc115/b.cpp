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
    vc<vc<int>> C(n, vc<int>(n, 0));
    vc<int> mi;
    rep(i, n) { rep(j, n) cin >> C[i][j]; }
    int m = 1e18;
    int to = 0;
    for (int i = 0; i < n; i++) {
        if (C[i][0] < m) {
            m = C[i][0];
            to = i;
        }
    }
    mi = C[to];
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        int dif = C[i + 1][0] - C[i][0];
        for (int j = 0; j < n; j++) {
            if ((C[i + 1][j] - C[i][j]) != dif) ok = false;
        }
        if (!ok) break;
    }
    if (!ok) {
        cout << "No" << endl;
    } else {
        vc<int> a(n), b(n);
        b = mi;
        for (int i = 0; i < n; i++) {
            if (i == to) {
                a[i] = 0;
            } else {
                a[i] = C[i][0] - mi[0];
            }
        }
        cout << "Yes" << endl;
        rep(i, n) cout << a[i] << " ";
        cout << endl;
        rep(i, n) cout << b[i] << " ";
        cout << endl;
    }
}