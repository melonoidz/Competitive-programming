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
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    auto s = accumulate(ALL(a), 0LL);
    if (s % 10 != 0) {
        cout << "No" << endl;
        return 0;
    }
    s /= 10;
    rep(i, n) {
        int c = a[i];
        a.push_back(c);
    }
    vc<int> b;
    b.push_back(0);
    rep(i, 2 * n) {
        int tmp = b.back() + a[i];
        b.push_back(tmp);
    }
    for (int i = 1; i <= n; i++) {
        int goal = b[i] + s;
        auto d = lower_bound(ALL(b), b[i] + s) - b.begin();
        if (b[d] == goal) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}