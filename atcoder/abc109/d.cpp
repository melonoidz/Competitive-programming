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
    int h, w;
    cin >> h >> w;
    vc<vc<int>> a(h, vc<int>(w));
    vc<pi> fi, af;
    rep(i, h) { rep(j, w) cin >> a[i][j]; }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w - 1; j++) {
            if (a[i][j] % 2 == 1) {
                fi.emplace_back(i + 1, j + 1);
                a[i][j]--;
                a[i][j + 1]++;
            }
        }
    }
    for (int i = 0; i < h - 1; i++) {
        if (a[i][w - 1] % 2 == 1) {
            af.emplace_back(i + 1, w);
            a[i][w - 1]--;
            a[i + 1][w - 1]++;
        }
    }
    int ans = fi.size() + af.size();
    cout << ans << endl;
    for (auto q : fi) {
        cout << q.first << " " << q.second << " " << q.first << " "
             << q.second + 1 << endl;
    }
    for (auto p : af) {
        cout << p.first << " " << p.second << " " << p.first + 1 << " "
             << p.second << endl;
    }
    return 0;
}