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
    int n, q;
    cin >> n >> q;
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    vc<int> t;
    int st = 0;
    rep(i, n) {
        int now = a[i] - st - 1;
        t.push_back(now);
        st = a[i];
    }
    // rep(i, t.size()) cout << t[i] << " ^^ ";
    vc<int> sn;
    sn.push_back(0);
    for (int i = 0; i < t.size(); i++) {
        int now = sn.back() + t[i];
        sn.push_back(now);
    }
    const int inf = 1LL << 60;
    sn.push_back(inf);
    // rep(i, sn.size()) cout << sn[i] << "-- ";

    rep(i, q) {
        int k;
        cin >> k;
        auto d = lower_bound(ALL(sn), k) - sn.begin();
        // cout << d << endl;
        if (d == 1) {
            cout << k << endl;
        } else {
            int res = k - sn[d - 1];
            int f = a[d - 2];
            cout << f + res << endl;
        }
    }
}