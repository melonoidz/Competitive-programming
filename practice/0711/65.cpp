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
    using mint = atcoder::modint998244353;
    int r, g, b, k;
    cin >> r >> g >> b >> k;
    int x, y, z;
    cin >> x >> y >> z;
    mint ans = 0;
    for (int bit = 0; bit < (1 << (r + g + b)); bit++) {
        int X = 0, Y = 0, Z = 0;
        if (popcount(bit) != k) continue;
        for (int i = 0; i < r; i++) {
            if (bit & (1 << i)) {
                X++;
                Z++;
            }
        }
        for (int i = r; i < r + g; i++) {
            if (bit & (1 << i)) {
                X++;
                Y++;
            }
        }
        for (int i = r + g; i < r + g + b; i++) {
            if (bit & (1 << i)) {
                Z++;
                Y++;
            }
        }
        if (X <= x && Y <= y && Z <= z) ans++;
    }
    cout << ans.val() << endl;
}