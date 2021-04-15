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
    int n, t;
    cin >> n >> t;
    vc<int> a, b;
    rep(i, n) {
        int x;
        cin >> x;
        if (i % 2 == 0)
            a.push_back(x);
        else
            b.push_back(x);
    }
    int ans = 0;
    vc<int> ta, tb;
    for (int bit = 1; bit < (1 << a.size()); bit++) {
        int time = 0;
        for (int i = 0; i < a.size(); i++) {
            if (bit & (1 << i)) {
                time += a[i];
            }
        }
        ta.push_back(time);
    }
    for (int bit = 1; bit < (1 << b.size()); bit++) {
        int time = 0;
        for (int i = 0; i < b.size(); i++) {
            if (bit & (1 << i)) {
                time += b[i];
            }
        }
        tb.push_back(time);
    }
    tb.push_back(0);
    sort(ALL(ta));
    sort(ALL(tb));
    for (auto q : ta) {
        auto d = lower_bound(ALL(tb), t - q + 1) - tb.begin();
        if (q + tb[d - 1] <= t) {
            chmax(ans, q + tb[d - 1]);
        }
    }
    cout << ans << endl;
}