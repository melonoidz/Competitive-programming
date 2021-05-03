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
    int n, c;
    cin >> n >> c;
    vc<vc<int>> D(c, vc<int>(c));
    rep(i, c) rep(j, c) cin >> D[i][j];
    vc<vc<int>> s(n, vc<int>(n));
    rep(i, n) rep(j, n) cin >> s[i][j];
    int ans = 1LL << 60;
    vc<map<int, int>> cnt(3);
    rep(i, n) rep(j, n) { cnt[(i + j) % 3][s[i][j] - 1]++; }
    for (int x = 0; x < c; x++) {
        for (int y = 0; y < c; y++) {
            for (int z = 0; z < c; z++) {
                if (x == y || y == z || z == x) continue;
                int now = 0;
                for (int i = 0; i < 3; i++) {
                    for (auto u : cnt[i]) {
                        if (i == 0)
                            now += D[u.first][x] * u.second;
                        else if (i == 1)
                            now += D[u.first][y] * u.second;
                        else
                            now += D[u.first][z] * u.second;
                    }
                }
                chmin(ans, now);
            }
        }
    }
    cout << ans << endl;
}