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
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vc<int> a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(ALL(a), greater<int>());
    sort(ALL(b), greater<int>());
    sort(ALL(c), greater<int>());
    vc<int> yz;
    for (const auto& bb : b) {
        for (const auto& cc : c) {
            yz.emplace_back(bb + cc);
        }
    }
    sort(ALL(yz), greater<int>());
    vc<int> res;
    for (const auto& aa : a) {
        for (int i = 0; i < min(int(yz.size()), k); i++) {
            res.push_back(aa + yz[i]);
        }
    }
    sort(ALL(res), greater<int>());
    rep(i, k) cout << res[i] << endl;
}