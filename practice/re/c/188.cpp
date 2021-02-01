#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
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
    vc<int> a(1 << n, 0);
    rep(i, 1 << n) cin >> a[i];
    vc<pi> pe;
    rep(i, 1 << n) { pe.emplace_back(a[i], i + 1); }
    vc<int> vs = a;
    for (int i = 1; i < n; i++) {
        vc<int> tmp;
        for (int j = 0; j < vs.size() - 1; j += 2) {
            tmp.push_back(max(vs[j], vs[j + 1]));
        }
        vs = tmp;
    }
    int res = min(vs[0], vs[1]);
    for (auto p : pe) {
        if (p.first == res) {
            cout << p.second << endl;
            return 0;
        }
    }
}