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
int n;
bool ch(int x, vc<int> a, vc<int> b, vc<int> c, vc<int> d, vc<int> e) {
    set<int> now;
    rep(i, n) {
        int tmp = 0;
        if (a[i] >= x) tmp += (1LL << 4);
        if (b[i] >= x) tmp += (1LL << 3);
        if (c[i] >= x) tmp += (1LL << 2);
        if (d[i] >= x) tmp += (1LL << 1);
        if (e[i] >= x) tmp += (1LL << 0);
        now.insert(tmp);
    }
    for (const auto& p : now) {
        for (const auto& q : now) {
            for (const auto& r : now) {
                if ((p | q | r) == 31) return true;
            }
        }
    }
    return false;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n;
    vc<int> a(n), b(n), c(n), d(n), e(n);
    rep(i, n) { cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i]; }
    int ng = 0, ok = 10e10;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (ch(mid, a, b, c, d, e)) {
            ng = mid;
        } else {
            ok = mid;
        }
    }
    cout << ng << endl;
}