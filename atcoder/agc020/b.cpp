#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
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
    int k;
    cin >> k;
    vc<int> a(k, 0);
    rep(i, k) cin >> a[i];
    reverse(a.begin(), a.end());
    int L = 2;
    int R = 2;
    for (int i = 0; i < k; i++) {
        int nl, nr;
        if ((L - 1) / a[i] == R / a[i]) {
            cout << -1 << endl;
            return 0;
        }
        if (L % a[i] == 0) {
            nl = L / a[i] * a[i];
        } else {
            nl = (1 + L / a[i]) * a[i];
        }
        nr = R / a[i] * a[i];

        nr += a[i] - 1;
        L = nl;
        R = nr;
    }
    cout << L << " " << R << endl;
    return 0;
}