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
    int n, b, tmp;
    b = 0, tmp = 0;
    cin >> n;
    vc<int> a(n);
    bool ok = true;
    rep(i, n) {
        cin >> tmp;
        if (tmp > i || tmp - b > 1) {
            ok = false;
        }
        b = tmp;
        a[i] = b;
    }
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    int res = 0;
    a.push_back(0);
    for (int i = 0; i < n; i++) {
        if (a[i] >= a[i + 1]) {
            res += a[i];
        }
    }
    cout << res << endl;
}