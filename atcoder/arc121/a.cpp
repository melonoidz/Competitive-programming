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
    vc<pair<pi, int>> u, v;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        u.push_back(make_pair(make_pair(x, y), i));
        v.push_back(make_pair(make_pair(y, x), i));
    }
    sort(ALL(u));
    sort(ALL(v));
    vc<pair<int, pi>> ans;
    // TOP-[i]
    for (int i = 0; i < 2; i++) {
        auto dist = abs(u[i].first.first - u[n - 1].first.first);
        auto p = u[i].second;
        auto q = u[n - 1].second;
        auto ind = make_pair(min(p, q), max(p, q));
        ans.emplace_back(dist, ind);
    }
    for (int i = 0; i < 2; i++) {
        auto dist = abs(v[i].first.first - v[n - 1].first.first);
        auto p = v[i].second;
        auto q = v[n - 1].second;
        auto ind = make_pair(min(p, q), max(p, q));
        ans.emplace_back(dist, ind);
    }
    // SECOND-[i]
    for (int i = 0; i < 2; i++) {
        auto dist = abs(u[i].first.first - u[n - 2].first.first);
        auto p = u[i].second;
        auto q = u[n - 2].second;
        auto ind = make_pair(min(p, q), max(p, q));
        ans.emplace_back(dist, ind);
    }
    for (int i = 0; i < 2; i++) {
        auto dist = abs(v[i].first.first - v[n - 2].first.first);
        auto p = v[i].second;
        auto q = v[n - 2].second;
        auto ind = make_pair(min(p, q), max(p, q));
        ans.emplace_back(dist, ind);
    }

    sort(ALL(ans), greater<pair<int, pi>>());
    if (ans[0].second != ans[1].second) {
        cout << ans[1].first << endl;
    } else {
        cout << ans[2].first << endl;
    }
}