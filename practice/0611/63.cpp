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
    vc<vc<int>> p(h, vc<int>(w));
    rep(i, h) rep(j, w) cin >> p[i][j];
    int ans = 0;
    for (int bit = 0; bit < (1 << h); bit++) {
        vvc<int> tmp;
        auto pop = popcount(bit);
        if (pop == 0) continue;
        for (int i = 0; i < h; i++) {
            if (bit & (1 << i)) {
                tmp.push_back(p[i]);
            }
        }
        map<int, int> cnt;
        for (int i = 0; i < w; i++) {
            bool same = true;
            for (int j = 0; j < pop; j++) {
                if (tmp[j][i] != tmp[0][i]) same = false;
            }
            if (same) {
                cnt[tmp[0][i]] += pop;
            }
        }
        for (auto u : cnt) {
            chmax(ans, u.second);
        }
    }
    cout << ans << endl;
}