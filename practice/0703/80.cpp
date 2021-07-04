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
    int n, d;
    cin >> n >> d;
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    vc<int> pop(1 << n), bit(1 << n);
    for (int i = 1; i < (1 << n); i++) {
        pop[i] = pop[i >> 1] + (i & 1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << i); j++) {
            bit[j + (1 << i)] = bit[j] | a[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        // check
        int okdigit = d - popcount(bit[i]);
        if (pop[i] % 2 == 0) {
            ans += (1LL << okdigit);
        } else {
            ans -= (1LL << okdigit);
        }
    }
    cout << ans << endl;
    return 0;
}