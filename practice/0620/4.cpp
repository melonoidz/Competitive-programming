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
    int l, r, ans = 0;
    cin >> l >> r;
    vc<int> cnt(1001000, 0);
    for (int i = 2; i <= r; i++) {
        int tmp = r / i - (l - 1) / i;
        cnt[i] = tmp * tmp;
    }
    // GCDがちょうどiを求める
    // 大きいほうからやるとうまくいく
    for (int i = r; i >= 1; i--) {
        for (int j = 2 * i; j <= r; j += i) {
            cnt[i] -= cnt[j];
        }
    }
    // gcd(x,y)=g かつ (x=g or y=g)
    // hint 4-1
    for (int j = 2; j <= r; j++) {
        int now = cnt[j];
        if (j >= l) now -= (r / j) * 2 - 1;
        ans += now;
    }
    cout << ans << endl;
    return 0;
}