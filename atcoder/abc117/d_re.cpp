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
    int n, k;
    cin >> n >> k;
    int kk = bitset<2>(k).size();
    //cout << kk << endl;
    vc<int> a(kk, 0);
    rep(i, n) cin >> a[i];
    int ans = 0;
    vc<int> cnt(kk, 0);
    for (int d = kk; d >= 0; d--) {
        for (int i = 0; i < n; i++) {
            if (a[i] & (1 << d)) {
                cnt[d]++;
            }
        }
    }
    for (int dd = kk; dd >= 0; dd--) {
        if (k & (1 << dd)) {
            ans += (1 << dd) * max(cnt[dd], n - cnt[dd]);
        } else {
            ans += (1 << dd) * (n - cnt[dd]);
        }
    }
    cout << ans << endl;
}