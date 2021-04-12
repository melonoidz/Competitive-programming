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
    vc<vc<int>> a(n, vc<int>(n, 0));
    rep(i, n) rep(j, n) cin >> a[i][j];
    vc<vc<int>> md(n, vc<int>(n, 0));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = a[i][j];
            for (int k = 0; k < n; k++) {
                dist = min(dist, a[i][k] + a[k][j]);
            }
            md[i][j] = dist;
            md[j][i] = dist;
        }
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = 1LL << 60;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                dist = min(dist, md[i][k] + md[k][j]);
            }
            if (dist < a[i][j]) {
                cout << -1 << endl;
                return 0;
            }
            //dist>a[i][j]の時，道はある
            if (dist > a[i][j]) {
                ans += a[i][j];
            }
        }
    }
    cout << ans << endl;
}