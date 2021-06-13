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
    vc<pi> s, revs;
    rep(i, n) {
        int x, v;
        cin >> x >> v;
        s.emplace_back(x, v);
        revs.emplace_back(c - x, v);
    }
    sort(ALL(s));
    sort(ALL(revs));
    int ans = 0;
    vc<int> ls(100100, 0), rs(100100, 0);
    // left->left
    for (int i = 0; i < n; i++) {
        ls[i + 1] = ls[i] + s[i].second;
    }
    for (int i = 0; i < n; i++) {
        ls[i + 1] -= s[i].first;
        chmax(ans, ls[i + 1]);
    }
    // right->right
    for (int i = 0; i < n; i++) {
        rs[i + 1] = rs[i] + revs[i].second;
    }
    for (int i = 0; i < n; i++) {
        rs[i + 1] -= revs[i].first;
        chmax(ans, rs[i + 1]);
    }
    // left->right
    vc<int> lmax(100100, 0), rmax(100100, 0);
    for (int i = 0; i <= n; i++) {
        lmax[i + 1] = max(ls[i], lmax[i]);
        rmax[i + 1] = max(rmax[i], rs[i]);
    }
    for (int i = 0; i < n; i++) {
        int left = ls[i + 1] - s[i].first;
        int now = left + rmax[n - i];
        chmax(ans, now);
    }
    // right->left
    for (int i = 0; i < n; i++) {
        int right = rs[i + 1] - revs[i].first;
        int now = right + lmax[n - i];
        chmax(ans, now);
    }
    cout << ans << endl;
}