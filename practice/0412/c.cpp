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
    vc<vc<int>> c(3, vc<int>(3, 0));
    rep(i, 3) rep(j, 3) cin >> c[i][j];
    bool ok = true;
    for (int i = 0; i < 2; i++) {
        if (!((c[0][i] - c[1][i] == c[0][i + 1] - c[1][i + 1]) &&
              (c[2][i] - c[1][i] == c[2][i + 1] - c[1][i + 1]) &&
              (c[0][i] - c[2][i] == c[0][i + 1] - c[2][i + 1]))) {
            ok = false;
        }
        if (!((c[i][0] - c[i][1] == c[i + 1][0] - c[i + 1][1]) &&
              (c[i][2] - c[i][1] == c[i + 1][2] - c[i + 1][1]) &&
              (c[i][0] - c[i][2] == c[i + 1][0] - c[i + 1][2]))) {
            ok = false;
        }
    }
    if (!((c[0][0] - c[1][0] == c[0][2] - c[1][2]) &&
          (c[2][0] - c[1][0] == c[2][2] - c[1][2]) &&
          (c[0][0] - c[2][0] == c[0][2] - c[2][2]))) {
        ok = false;
    }
    if (!((c[0][0] - c[0][1] == c[2][0] - c[2][1]) &&
          (c[0][2] - c[0][1] == c[2][2] - c[2][1]) &&
          (c[0][0] - c[0][2] == c[2][0] - c[2][2]))) {
        ok = false;
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}