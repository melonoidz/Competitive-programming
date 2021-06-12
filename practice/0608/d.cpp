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
    vvc<int> D(n, vc<int>(n));
    rep(i, n) rep(j, n) cin >> D[i][j];
    map<int, int> mp;
    vvc<int> imos(n + 1, vc<int>(n + 1, 0));
    rep(i, n) {
        rep(j, n) {
            imos[i + 1][j + 1] =
                imos[i][j + 1] + imos[i + 1][j] - imos[i][j] + D[i][j];
        }
    }
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            for (int i = 0; i < n - x + 1; i++) {
                for (int j = 0; j < n - y + 1; j++) {
                    int now = imos[i + x][j + y] - imos[i + x][j] -
                              imos[i][j + y] + imos[i][j];
                    int s = x * y;
                    chmax(mp[s], now);
                }
            }
        }
    }
    int Q;
    cin >> Q;
    rep(i, Q) {
        int p;
        cin >> p;
        int res = 0;
        for (int j = 1; j <= p; j++) {
            chmax(res, mp[j]);
        }
        cout << res << endl;
    }
}