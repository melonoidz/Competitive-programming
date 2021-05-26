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
    int n, k;
    cin >> n >> k;
    vc<int> xs(3);
    // i+j+k=x
    // int x = 0;
    xs[0] = 0;
    xs[1] = 0;
    xs[2] = 0;
    for (int i = 3; i <= 3 * n; i++) {
        int cnt = (i - 1LL) * (i - 2LL) / 2LL;
        xs.push_back(xs.back() + cnt);
    }
    auto x = lower_bound(ALL(xs), k) - xs.begin();
    cout << x << endl;
    k -= xs[x - 1];
    int p = 0, q = 0, r = 0;
    for (int i = 1LL; i <= n; i++) {
        int now;
        if (x - i > 2 * n) {
            now = 0;
        } else {
            if (1LL + n >= x - i) {
                now = x - i - 1;
            } else {
                now = max(n, x - i - n) - min(n, x - i - n) + 1LL;
            }
        }
        if (k - now > 0) {
            k -= now;
        } else {
            p = i;
            break;
        }
    }
    // cout << p << " " << k << endl;
    if (x - p <= 1LL + n) {
        q = k;
    } else {
        q = x - p - n + (k - 1);
    }
    r = x - p - q;
    cout << p << " " << q << " " << r << endl;
}