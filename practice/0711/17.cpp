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
    int n, m;
    cin >> n >> m;
    vc<int> l(300300), r(300300), v1(300300), v2(300300), v3(300300),
        cnt(300300);
    vc<pi> cur;
    rep(i, m) cin >> l[i] >> r[i];
    int x = 0, y = 0, z = 0;
    // x
    rep(i, m) v3[l[i]]++, v3[r[i]]++;
    rep(i, n + 1) { x += v3[i] * (v3[i] - 1LL) / 2LL; }
    // y
    rep(i, m) { v1[r[i]]++, v2[l[i] - 1LL]++; }
    rep(i, n + 1) v1[i + 1] += v1[i];
    rep(i, n + 1) y += v1[i] * v2[i];

    rep(i, m) cur.emplace_back(r[i], l[i]);
    sort(ALL(cur));
    // z
    rep(i, cur.size()) {
        auto cl = cur[i].second, cr = cur[i].first;
        int ret = 0;
        for (int j = cl + 1; j <= cr; j++) {
            ret += cnt[j];
        }
        z += ret;
        cnt[cl]++;
    }

    int ans = m * (m - 1LL) / 2LL;
    cout << ans - (x + y + z) << endl;
}